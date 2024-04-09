"""
入力 N（1-200,000）
出力 N個の小文字(a-z)による単語. 文字は奇数回出現する.N>26なら文字は必ず1回使う.

N=1 z
N=4 code xxxy uutu
N=7 gwgtgwww

"""

def solution(N):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    if N == 1:
        return alphabet[0]
    elif N <= 26:
        return alphabet[:N]
    else:
        remaining_num = N - 25
        if remaining_num % 2 == 1: #残りが奇数回
            repeated_chars = alphabet[-1] * remaining_num
        else: #残りが偶数回
            repeated_chars = alphabet[0] * remaining_num
        return alphabet + repeated_chars

def main():
    N = int(input())
    word = solution(N)
    print(word)
  
if __name__ == "__main__":
    main()
