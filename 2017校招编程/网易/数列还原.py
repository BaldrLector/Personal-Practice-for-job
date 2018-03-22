def calc_count(l, k):
    t = 0
    for i in range(len(l) - 1):
        for j in range(i + 1, len(l)):
            if l[i] < l[j]:
                t += 1
    return 1 if t == int(k) else 0


n, k = input().split()
A = list(map(int, input().split()))
t = []
pos = []
count = 0
for x in range(1, int(n) + 1):
    if not x in A:
        t.append(x)
    if A[x - 1] == 0:
        pos.append(x - 1)
if len(t) == 1:
    A_temp = A
    A_temp[pos[0]] = t[0]
    count += calc_count(A_temp, k)
else:
    for i in range(len(t)):
        for j in range(len(t) - 1):
            t[j], t[j + 1] = t[j + 1], t[j]
            A_temp = A
            for index, item in enumerate(pos):
                A_temp[item] = t[index]
            count += calc_count(A_temp, k)
print(count)
