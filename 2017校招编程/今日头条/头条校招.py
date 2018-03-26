# 先排序，如果不和条件就添加几个


n = int(input())
a = list(map(int, input().split()))
a.sort()

b = [a[0]]
c = 0

for i in range(1, n):
    if a[i] - a[i - 1] <= 10:
        b.append(a[i])
    else:
        c += (3 - (len(b) % 3)) % 3
        b = [a[i]]
if len(b) != 0:
    c += (3 - (len(b) % 3)) % 3

print(c)
