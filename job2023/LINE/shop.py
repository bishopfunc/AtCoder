from datetime import datetime
from dataclasses import dataclass, field
from typing import List, Dict


@dataclass
class Request:
    request_time: str 
    request_type: str
    user_id: str
    item_id: str
    def __post_init__(self):
        self.request_time: datetime = datetime.strptime(self.request_time, '%Y-%m-%dT%H:%M')

@dataclass
class SellRequest(Request):
    minimum_price: str
    BIN_price: str 
    end_time : str 

    def __post_init__(self):
        super().__post_init__()
        self.minimum_price: int = int(self.minimum_price)
        self.BIN_price: int or str = int(self.BIN_price) if self.BIN_price != '-' else '-' 
        self.end_time: datetime = datetime.strptime(self.end_time, '%Y-%m-%dT%H:%M')

@dataclass
class BidRequest(Request):
    price: str
    def __post_init__(self):
        super().__post_init__()    
        self.price: int = int(self.price)

@dataclass
class SellCancelRequest(Request):
    pass

@dataclass
class BidCancelRequest(Request):
    pass

class User:
    user_id = ''
    bid_history = [] #入札した商品の一覧

@dataclass
class Item():
    start_time: datetime
    seller: User #出品者
    item_id: str  #その商品のアイテムID        
    minimum_price: int #その商品の最低金額
    BIN_price: int #その商品の即決金額
    end_time:datetime

    current_price: int = 0 #その商品の現在金額
    bidder_price_dict = {}
    highest_bidder: User = None #その商品の最高入札者
    finished_time: datetime = None #オークション結果確定時刻
    finished_flag: bool = False

    
class Auction:
    def __init__(self) -> None:
        self.items = []
        self.old_items = [] #終了済みの商品

    def get_request(self, request) -> None:
        # 現在時刻 == 終了時刻 -> 終了
        for item in self.items:
            if item.end_time ==  request.request_time: 
              item.finished_time = request.request_time
              print(f'AUCTION_FINISHED: {item.finished_time} {item.item_id} {item.current_price} {item.BIN_price} {item.highest_bidder}')
              self.items.remove(item)
              del item
              return 
            
    def sell(self, request) -> None:
        for item in self.old_items: #過去の出品も確認
            if request.item_id == item.item_id:
                print('SELL: this item_id is already in use') #同じidの商品が出品済み
                return
        new_item = Item(
            item_id=request.item_id, 
            end_time=request.end_time, 
            start_time=request.request_time, 
            BIN_price=request.BIN_price, 
            minimum_price=request.minimum_price,
            seller=request.user_id
          )
        self.items.append(new_item)
        self.old_items.append(new_item)
        print('SELL: accepted') #OK

    def sell_cancel(self, request) -> None:
        flag = True
        for item in self.items:
            if request.item_id == item.item_id:       
              flag == False         
        if flag:
            print('SELL_CANCEL: this item is currently not for sale') #商品が出品されてない
            return 
        for item in self.items:
            if request.item_id == item.item_id:
                if request.user_id != item.seller:
                  print('SELL_CANCEL: user is not the seller of this item') #出品者が違う
                  return

        for item in self.items:
            if request.item_id == item.item_id:                
                # 出品取り消し -> 終了
                item.finished_time = request.request_time
                print(f'AUCTION_FINISHED: {item.finished_time} {item.item_id} {item.current_price} {item.BIN_price} {item.highest_bidder}')
                self.items.remove(item)
                del item
                return 
        
        self.items.remove(request.item_id)
        print('SELL_CANCEL: accepted') #受けいれ OK
                
    def bid(self, request):
        # 通常入札
        # 即決金額で入札 -> 終了
        for item in self.items:
              if item.item_id == request.item_id:
                  if request.user_id == item.seller:
                      print('BID: user is the seller of this item')
                      return
                  if request.price < item.minimum_price:
                      print('BID: the bid is lower than the minimum price')
                      return
                  if item.BIN_price != '-' and request.price >= item.BIN_price:
                      item.current_price = item.BIN_price
                      item.highest_bidder = item.seller
                      item.finished_time = request.request_time
                      print(f'AUCTION_FINISHED: {item.finished_time} {item.item_id} {item.current_price} {item.BIN_price} {item.highest_bidder}')
                      self.items.remove(item)
                      return
                  # if item.highest_bidder is not None and request.price <= item.highest_bidder.bidder_price_dict.get(request.user_id, 0):
                  #     print("BID: the price must be higher than the user's previous highest price")
                  #     return

                  item.current_price = request.price
                  item.highest_bidder = request.user_id
                  item.bidder_price_dict[request.user_id] = request.price

                  #正常処理
                  item.current_price = request.price
                  item.highest_bidder = request.user_id
                  item.bidder_price_dict.update({request.user_id: request.price})
                  print(f'BID: {item.current_price} {item.BIN_price} {item.highest_bidder}') #OK                  
                  # 入札金額 == 即決金額 -> 終了
                  if item.BIN_price == request.price:
                      item.finished_time = request.request_time
                      print(f'AUCTION_FINISHED: {item.finished_time} {item.item_id} {item.current_price} {item.BIN_price} {item.highest_bidder}')
                      self.items.remove(item)
                      del item
                      return 
                  
    def bid_cancel(self, request):
        flag = True
        for item in self.items:
            if request.item_id == item.item_id:       
              flag == False         
        if flag:
            print('BID_CANCEL: this item is currently not for sale') #出品されてない
        for item in self.items:
            if request.item_id == item.item_id:
                if request.user_id != item.seller:
                  print('BID_CANCEL: user has not bid on the item') #入札してない
                  return
        
                del item.bidder_price_dict[request.user_id]
                print(f'BID_CANCEL: {item.current_price} {item.BIN_price} {item.highest_bidder}')


def main():
  auction = Auction()
  while(True):
      line = input().split()
      request_type: str = line[1]
      if request_type == 'SELL':
          request = SellRequest(*line)
          auction.get_request(request)
          auction.sell(request)
      elif request_type == 'SELL_CANCEL':
          request = SellCancelRequest(*line)
          auction.get_request(request)
          auction.sell_cancel(request)
      elif request_type == 'BID':
          request = BidRequest(*line)
          auction.get_request(request)
          auction.bid(request)

      elif request_type == 'BID_CANCEL': 
          request = BidCancelRequest(*line)
          auction.get_request(request)
          auction.bid_cancel(request)    
if __name__ == '__main__':
    try:
        main()
    except EOFError:
        pass
      




