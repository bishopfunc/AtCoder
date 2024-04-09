from itertools import permutations


def main():
    x = input()
    x_list = list(x)
    all_list = []
    
    for p in permutations(x_list):
        if p[0] != '0':  
            num = int(''.join(p))
            all_list.append(num)
    
    print(min(all_list))


if __name__ == "__main__":
    main()
