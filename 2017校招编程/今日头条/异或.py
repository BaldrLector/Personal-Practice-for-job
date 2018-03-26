t = list(map(int, input().split()))
n = t[0]
m = t[1]
a = list(map(int, input().split()))

bm = bin(m)
b = [bin(i) for i in a]
c = 0

for i in range(n):
    for j in range(i + 1, n):
        if a[i] ^ a[j] > m:
            c += 1

print(c)
