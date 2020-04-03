

with open('bef.c') as fp:
    tmp = [s.strip() for s in fp.readlines()]
    lst = []
    font = []
    for l in tmp:
        if (l == ''):
            pass
        elif (l[0:2] == '//'):
            pass
        else:
            lst.append(l[2:10])

    for itr in range(95):
        c = []
        for x in lst[itr*16:itr*16+16]:
            t = 0
            if (x[0] == '1'):
                t = t | 0x80
            if (x[1] == '1'):
                t = t | 0x40
            if (x[2] == '1'):
                t = t | 0x20
            if (x[3] == '1'):
                t = t | 0x10
            if (x[4] == '1'):
                t = t | 0x08
            if (x[5] == '1'):
                t = t | 0x04
            if (x[6] == '1'):
                t = t | 0x02
            if (x[7] == '1'):
                t = t | 0x01
            c.append(t)
        font.append(c)

    for c in range(95):
        print('{ ', end='')
        for i in range(16):
            print('0x', end='')
            print(format(font[c][i], '02X'), end='')
            if (i < 15):
                print(', ', end='')
        print('},')
