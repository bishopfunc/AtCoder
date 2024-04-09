from collections import deque


#従業員番号 id
#残りの作業量 leftA
#queueにより高速化
def main():
    todo_id_queue = deque() #作業待ち従業員idを入れるqueue
    done_id_list = [] #終了済み従業員idを入れるlist
    id_leftA_dict = {} #従業員idと残りの作業量leftAのdict
    N, W = map(int, input().split())
    A = list(map(int, input().split()))
    for i, task in enumerate(A, 1): #
        id_leftA_dict[i] = task #従業員idと残りの作業量(初期値はA_i)のdict
        todo_id_queue.append(i) #idをqueueに追加
    
    while todo_id_queue:
        id = todo_id_queue.popleft() #queueの先頭を取得
        #作業量が終わらず、残りの作業量leftAが発生する
        if(id_leftA_dict[id] > W ): #残りの作業量が機械の作業量より多い
            id_leftA_dict[id] -= W  #leftAを更新
            todo_id_queue.append(id) #idを末尾に追加
        #作業量が終わる
        else:
            done_id_list.append(id) #idを終了済みに入れる

    for id in done_id_list:
        print(id)

if __name__ == "__main__":
    main()




