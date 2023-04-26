def main():
    H, M = input().split()
    hm_list = []
    new_hm_list = []
    for h in range(24):
        for m in range(60):
            if m < 10: 
                strm = "0" + str(m)
            strh = "0" + str(h) if h < 10 else str(h)
            strm = "0" + str(m) if m < 10 else str(m)
            hm = (strh, strm) 
            hm_list.append(hm)
    for hm in hm_list:
        a = hm[0][0]
        b = hm[0][1]
        c = hm[1][0]
        d = hm[1][1]
        new_hm_list.append((a+c, b+d))
    and_list = list(set(new_hm_list) & set(hm_list))
    strh = "0" + str(H) if int(H) < 10 else str(H)
    strm = "0" + str(M) if int(M) < 10 else str(M)
    and_list.append((strh, strm))
    and_list = sorted(list(and_list))
    and_list.append(and_list[0])
    ix = and_list.index((strh, strm))
    # print(ix)
    # print(len(and_list))
    if and_list[ix+1] == (strh, strm):
        pass
    else:
        ix += 1
    print(and_list[ix][0], and_list[ix][1])
if __name__ == "__main__":
    main()