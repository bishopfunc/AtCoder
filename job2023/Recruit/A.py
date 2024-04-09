def main():
    n = int(input())

    for _ in range(n):
        a, b = map(int, input().split())
        conditon_a = b <= 60
        conditon_b = (a + b) <= 100
        if (conditon_a and conditon_b):
          print("fail")
        elif (conditon_a or conditon_b):
          print("reexamination")
        else:
          print("pass")

if __name__ == "__main__":
    main()