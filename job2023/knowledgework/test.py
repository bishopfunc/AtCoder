def f(a, b):
    if b == 0: return 0
    return f(b, a % b)
def f2(x):
    if x <= 1:
        return 0
    elif x % 2 == 0:
        return f2(x+1)+x
    else:
        return f2(x-3)-x
def main():
    print(f(10, 2))
    count = 0 
    for i in range(10):
        for j in range(i, 10):
          count += 1
    print(count)
    print(f2(10))
if __name__ == "__main__":
    main()