def main():
    N = int(input())
    A = list(map(int, input().split()))
    hist = dict()
    for i, a in enumerate(A, 1):
      if hist.get(a):
        print(i)
        return
      else:
        hist[a] = 1
    print(-1)
if __name__ == "__main__":
    main()