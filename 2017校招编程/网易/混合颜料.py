n = int(input())
num = list(map(int, input().split()))

n_picked = 0

while len(num) > 2:
    num = sorted(num, reverse=True)
    first = format(num[0], 'b')
    second = format(num[1], 'b')

    if len(first) == len(second):
        compound_num = num[0] ^ num[1]

        if compound_num not in num:
            num.append(compound_num)
    else:
        n_picked += 1
    num.pop(0)

print(n_picked + len(num))
