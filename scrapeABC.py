import logging
import requests
import os, sys, re
from bs4 import BeautifulSoup
import validators
import urllib.parse
from tqdm import tqdm
from logging import getLogger
from time import sleep

logging.basicConfig(format = '%(asctime)s (%(msecs)03dmsec) --%(module)s.py: %(message)s', datefmt='%Y-%m-%d %H:%M:%S')
logger = getLogger(__name__) # ログの設定

# ファイルにコピーされるテンプレート（カスタマイズ可）
TEMPLATE = \
"""
#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
"""
EXTENSION = 'cpp'

USERNAME = 'bishopfunc'
PASSWORD = 'Beibei071121'

def login():
    login_url = "https://atcoder.jp/login"
    session = requests.session() # sessionを作成
    res = session.get(login_url) # cookieを取得するためにgetでアクセス
    revel_session = res.cookies.get_dict()['REVEL_SESSION'] # revel_sessionを取得
    revel_session = urllib.parse.unquote(revel_session) # revel_sessionをデコード
    csrf_token = re.search(r'csrf_token\:(.*)_TS', revel_session).groups()[0].replace('\x00\x00', '') # csrf_tokenを正規表現で取得し、余分な文字を除去する
    sleep(1) # 取得するまで待つ
    headers = {'content-type': 'application/x-www-form-urlencoded'} # ヘッダーの定義
    params = {
      'username': USERNAME, 
      'password': PASSWORD,
      'csrf_token': csrf_token,
    } # クエリーの定義
    data = {
      'continue': 'https://atcoder.jp/'
    } # データの定義
    res = session.post(login_url, params=params, data=data, headers=headers) # 必要な情報を使ってpostでログイン
    res.raise_for_status() # http statusが異常なら例外をを起こす
    return session

def validate_url(url):
    # コンテスト名とURLのバリデーション
    if(not validators.url(url)):
        url = f'https://atcoder.jp/contests/{url}'

    # URLの'/tasks'や'/'の処理
    url = url[:-1] if (url[-1] == '/') else url
    url = url if ('tasks'in url) else url + '/tasks'
    return url

def main(key):
    # ログイン
    session = login()
    url = validate_url(key)

    # コンテストページから各問題のリンクを取得
    base_url = 'https://atcoder.jp'
    try:
        response = session.get(url).text
        sleep(1)
    except requests.exceptions.RequestException as e:
        logger.error('invalid url or contest name')
        exit()
    
    # bs4で読み込む
    soup = BeautifulSoup(response, features="lxml") 

    # 各問題のリンクを取得
    td_list = soup.find_all('td', class_='text-center no-break')
    link_list = [td.find('a').get('href') for td in td_list]
    access_url_list = [base_url + link for link in link_list]

    # コンテスト名からフォルダを作成
    try:
      contest_title = soup.find('a', class_='contest-title').contents[0]
      contest_title = contest_title.strip().replace(' - ', '_').replace(' ', '_')
      os.makedirs(contest_title, exist_ok=True)
    except Exception as e:
        logger.error('contest name is not exist')
        exit()

    # 各問題のタイトルを取得し、ファイルを作成
    for url in tqdm(access_url_list):  
        response = session.get(url).text
        soup = BeautifulSoup(response, features="lxml") # bs4で読み込む
        title = soup.find('span', class_='h2').contents[0] 
        title = title.strip().replace(' - ', '_').replace(' ', '_') # スペースやハイフン(-)をアンダーバー(_)に変換
        filename = f'{contest_title}/{title}.{EXTENSION}' # プログラムファイルを生成
        with open(filename, 'w', encoding='utf-8') as f: 
            f.writelines(TEMPLATE.strip())

if __name__ == '__main__':
    try:
        key = sys.argv[1]
    except IndexError as e:
        logger.error('please input url or contest name')
        exit()
    main(key)