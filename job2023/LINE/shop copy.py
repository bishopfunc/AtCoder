from datetime import datetime
from dataclasses import dataclass

# @da
# class Request:
#     user_id: str


class Auction:
    items = []
    caceled_id = []
    def get_request(self, request):
        # 現在時刻 == 終了時刻 -> 終了
        for item in self.items():
            if item.end_time ==  request.request_time #TODO
              item.finished_flag = True
              item.finished_time = request.request_time

    def sell():
        pass
    
    def sell_cancel(self, request):
        # 出品取り消し -> 終了
        for item in self.items():
            if item.item_id == request.item_id:
                item.finished_time = request.request_time
                self.items().remove(item)
                del item
                
    def bid(self, request):
        # 通常入札
        # 即決金額で入札 -> 終了
        for item in self.items():
              if item.item_id == request.item_id:
                  # エラー処理 #TODO
                  item.current_price = request.price
                  item.highest_bidder = request.user_id
                  if item.BIN_price == request.price:
                      item.finished_time = request.request_time
                      self.items().remove(item)
                      del item
    def bid_cancel(self, request):
        pass

    def auction_finished(self):
        # 出品取り消し
        # 現在時刻 == 終了時刻
        # 即決金額で入札
        for item in self.items():
            if item.finished_flag:
                print(f'AUCTION_FINISHED: {item.finished_time} {item.item_id} {item.current_price} {item.BIN_price} {item.highest_bidder}')
                self.items().remove(item)
                del item
class User:
    user_id = ''

class Item:
    item_id = ''  #オークション対象のアイテムID
    minimum_price = 0
    BIN_price = 0 #その商品の即決金額
    start_time = ''
    seller = ''
    bidder = ''
    current_price = 0 #その商品の現在金額
    bidder_price_dict = {}
    highest_bidder = '' #その商品の最高入札者
    finished_time = ''
    finished_flag = False
    def check_end_time():
        pass

if __name__ == '__main__':
    request = input().split()
    request_dict = {}
    request_type: str = request[1]
    if request_type == 'SELL':
        request_time: datetime = datetime.strptime(request[0], '%Y-%m-%dT%H:%M')
        user_id: str = request[2]
        item_id: str = request[3]
        minimum_price: int = int(request[4])
        BIN_price: int or None  =  None if request[5] == '-' else int(request[5])
        end_time: datetime = datetime.strptime(request[6], '%Y-%m-%dT%H:%M')

    elif request_type == 'SELL_CANCEL':
        request_time: datetime = datetime.strptime(request[0], '%Y-%m-%dT%H:%M')
        user_id: str = request[2]
        item_id: str = request[3]
        print('SELL_CANCEL: this item is currently not for sale') #商品が出品されてない
        print('SELL_CANCEL: user is not the seller of this item') #出品者が違う
        print('SELL_CANCEL: accepted') #受けいれ OK

    elif request_type == 'BID':
        request_time: datetime = datetime.strptime(request[0], '%Y-%m-%dT%H:%M')
        user_id: str = request[2]
        item_id: str = request[3]
        price: int = int(request[4])
        print('BID: this item is currently not for sale') #商品が出品されてない
        print('BID: user is the seller of this item') #出品者は入札できない
        print('BID: the bid is lower than the minimum price') #入札金額 < 最低金額
        print('BID: the bid is higer than the BIN price') #入札金額 > 即決金額
        print("BID: the price must higer than the user's previous highest price") #入札金額 < その人の最高入札金額
        current_price = '' #その商品の現在金額
        BIN_price = '' #その商品の即決金額
        highest_bidder = '' #その商品の最高入札者
        print(f'BID: {current_price} {BIN_price} {highest_bidder}') #OK

    elif request_type == 'BID_CANCEL': 
        request_time: datetime = datetime.strptime(request[0], '%Y-%m-%dT%H:%M')
        user_id: str = request[2]
        item_id: str = request[3]
        current_price = '' #その商品の現在金額
        BIN_price = '' #その商品の即決金額
        highest_bidder = '' #その商品の最高入札者
        print('BID_CANCEL: this item is currently not for sale') #出品されてない
        print('BID_CANCEL: user has not bid on the item') #入札してない
        print(f'BID_CANCEL: {current_price} {BIN_price} {highest_bidder}') #OK
    elif request_type == 'AUCTION_FINISHED':
        pass
        # finished_time = '' #オークション結果確定時刻
        # item_id = '' #オークション対象のアイテムID
        # current_price = '' #その商品の現在金額 
        # BIN_price = '' #その商品の即決金額
        # highest_bidder = '' #その商品の最高入札者
        # print(f'AUCTION_FINISHED: {finished_time} {item_id} {current_price} {BIN_price} {highest_bidder}')
