def solution(S):
    S = S.lstrip('0')
    V = int(S, 2)

    operations = bin(V).count('1') + len(S) - 1
    # 2で割る 右シフトの回数
    # 1を引く ビットが1の数 
    # 1回分多い
    # 111=>110=>11=>10=>1=>0
    print(bin(V).count('1'))
    print(len(S) - 1)
    return operations

def main():
    S = input()
    word = solution(S)
    print(word)

if __name__ == "__main__":
    main()