V,n = list(map(int, input().split()))
w, p = [ 0 for i in range(n+1)], [ 0 for i in range(n+1)]

f = [[0 for i in range(n + 1)] for _ in range(n + 1)]


for i in range(1, n + 1):
    w[i], p[i] = list(map(int, input().split()))

for i in range(1, n + 1):
    for v in range(w[i], V + 1):
        f[i, v] = max(f[i - 1, V], f[i - 1, v - w[i] + p[i]])

print(f[n, V])
