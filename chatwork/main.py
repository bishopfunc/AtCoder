from datetime import datetime
import argparse
from collections import OrderedDict
from sqlalchemy import create_engine, inspect, Column, Integer, DateTime
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base

# 上映スケジュールと残り席数
showtime_seats = {
    datetime(2023, 4, 30, 15, 0): 4,
    datetime(2023, 4, 30, 20, 0): 6,
    datetime(2023, 5, 1, 15, 0): 1,
    datetime(2023, 5, 1, 20, 0): 2,
    datetime(2023, 5, 2, 15, 0): 4,
    datetime(2023, 5, 2, 20, 0): 5,
}
# 料金表
prices = {
    "adult": 1600,
    "child": 1000,
    "elder": 1200,
}

# 割引
discounts = {
    "first_day": 1000,
    "late_show": 1400,
    "weekday_senior": 1200,
}

parser = argparse.ArgumentParser(description='Choose data source.')
parser.add_argument('-s', '--source', choices=['db', 'dict'], required=True, help='データ取得先 (db or dict)')
args = parser.parse_args()    

Base = None
if args.source == 'db':
    Base = declarative_base() # tableのベースクラスを作成

    # table用のクラス遠作成
    class Schedule(Base):
        __tablename__ = 'schedule'

        id = Column(Integer, primary_key=True)
        showtime = Column(DateTime, nullable=False)
        remaining_seats = Column(Integer, nullable=False)

# tableを初期化する関数
def table_init(schedule):    
    engine = create_engine('sqlite:///schedule.db')
    Base.metadata.create_all(engine) # table作成
    Session = sessionmaker(bind=engine) # sessionを生成するクラス

    ins = inspect(engine)
    for _t in ins.get_table_names():
        if  _t == Schedule.__tablename__:
            return Session

    session = Session() # sessionを生成
    for id, (showtime, remaining_seats) in enumerate(schedule.items(), 1):
        new_schedule = Schedule(id=id, showtime=showtime, remaining_seats=remaining_seats) # Datatime_objを挿入
        session.add(new_schedule)

    session.commit() # 変更をcommit
    session.close() # sessionを閉じる
    return Session

# 入力を処理する関数
def get_input():
    adult = validate_input_num(input("大人の数  (60 歳未満): "))
    child = validate_input_num(input("未成年の数(18 歳未満): "))
    elder = validate_input_num(input("シニアの数(60 歳以上): "))
    now_date =  input("日付(yyyymmdd): ")
    now_time =  input("時間(hhmm): ")
    now_datetime = validate_input_datetime(now_date, now_time)
    return adult, child, elder, now_datetime

# 入力された数字を検証する関数
def validate_input_num(n):
    try:
        n = int(n or 0)
    except Exception:
        print("数字を入力してください")
        exit(0)
    return n

# 入力された日時を検証する関数
def validate_input_datetime(date, time):
    try:
        datetime_obj = datetime.strptime(date + time, "%Y%m%d%H%M")
    except ValueError:
        print("正しい日時のフォーマットで入力してください\n 日付(yyyymmdd) 時間(hhmm)")
        exit(0)
    return datetime_obj


# 料金を計算する関数
def calculate_price(adult, child, elder, datetime):
    price = 0
    # ファーストデイ割引
    if datetime.day == 1:
        price = (adult + elder + child) * discounts["first_day"]
    # レイトショー割引
    elif datetime.hour >= 20:
        price = (adult + elder) * discounts["late_show"]
    # 平日シニア割引
    elif datetime.weekday() < 5 and 10 <= datetime.hour < 20 and elder > 0:
        price = adult * prices["adult"] + child * prices["child"] + elder * discounts["late_show"]
    # 割引なし
    else:
        price = adult * prices["adult"] + child * prices["child"] + elder * prices["elder"]
    return price

# 最安の時間帯を検索する関数
def find_cheapest_schedule(adult, child, elder, now, schedule):
    cheapest_price = float('inf')
    cheapest_schedule = None
    sorted_schedule = OrderedDict(sorted(schedule.items())) # 昇順にソートする((最安値になる日時が複数存在する場合は最も早い日時のみを返す)

    for datetime, seats in sorted_schedule.items():
        if datetime < now or seats < (adult + child + elder): # 過去の時間または、席数が少ない場合はスキップ
            continue
        elif child > 0 and datetime.hour >= 20: # 子連れかつ、20時以降はスキップ
            continue
        # print(datetime, seats)
        price = calculate_price(adult, child, elder, datetime) 
        if price < cheapest_price: # 同じ値段なら更新されない(最安値になる日時が複数存在する場合は最も早い日時のみを返す)
            cheapest_price = price
            cheapest_schedule = datetime

    return cheapest_schedule, cheapest_price

# 全てのレコードを選択し、ソートした上で、辞書に変換
def record_to_dict(Session):
    session = Session() # sessionを作成
    schedules = session.query(Schedule).order_by(Schedule.showtime).all() # 全てのレコードを選択し、昇順にソート
    schedule_dict = {schedule.showtime: schedule.remaining_seats for schedule in schedules} # datetimeをキーとし、席数を値とする辞書を作成
    session.close() # sessionを閉じる

    return schedule_dict

def main():
    adult, child, elder, now = get_input()    
    if args.source == 'db':
        Session = table_init(showtime_seats)
        schedule = record_to_dict(Session)
    else:
        schedule = showtime_seats   
    cheapest_schedule, cheapest_price = find_cheapest_schedule(adult, child, elder, now, schedule)
    if cheapest_schedule is None:
        print("適当な日時が存在しません。")
    else:
        print(f"日時: {cheapest_schedule}, 料金: {cheapest_price}")

if __name__ == "__main__":
    main()
