import sys
from collections import defaultdict

def check_is_rectangle(x_dict, y_dict):
    for x_coords in x_dict.values():
        for y_coords in y_dict.values():
            if len(x_coords.intersection(y_coords)) >= 4:
                return True
    return False

def init_dict(_dict, l):
    for i in range(0, l):
        _dict[0].add((0, i))
        _dict[l].add((0, i))
    return _dict

def main():
    x_dict = defaultdict(set)
    y_dict = defaultdict(set)
    n, l = map(int, input().split())
    x_dict = init_dict(x_dict, l)
    y_dict = init_dict(y_dict, l)
    for i in range(1, n):
        a, b, c, d = map(int, input().split())
        # xが同じ,縦線
        if a == c:
            min_x, max_x = min(b,d), max(b,d)
            for i in range(min_x + 1, max_x + 1):
              x_dict[a].add((min_x, i))
        # yが同じ,横線
        if b == d:
            min_y, max_y = min(a,c), max(a,c)
            for i in range(max_y + 1, max_y + 1):
              y_dict[b].add((max_y, i))
        if check_is_rectangle(x_dict, y_dict):
            print("NO")
            print(i + 1)
            return
        # print(x_dict.items())
        # print(y_dict.items())
    print("YES")

if __name__ == '__main__':
    main()
