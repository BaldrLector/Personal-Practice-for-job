import sys

input = sys.stdin
n = int(input.readline().strip())
power = input.readline().strip().split(" ")
power = [int(i) for i in power]
kd = input.readline().strip().split(" ")
k = int(kd[0])
d = int(kd[1])

fmax = [[0 for i in range(n)] for i in range(k)]
fmin = [[0 for i in range(n)] for i in range(k)]

for kk in range(k):
    for i in range(n):
        if kk == 0 or i == 0:
            fmax[kk][i] = power[i]
            fmin[kk][i] = power[i]
        else:
            M = []
            for t in range(max(i-d, 0), i):
                M.extend([fmax[kk-1][t]*power[i], fmin[kk-1][t]*power[i]])
            fmax[kk][i], fmin[kk][i] = max(M), min(M)

print(max(fmax[k-1]))



#
#
# n = int(input())
#
# a = list(map(int, input().split()))
# k, d = map(int, input().split())
#
# fmax = [[0 for i in range(k+1)] for i in range(n)]
# fmin = [[0 for i in range(k+1)] for i in range(n)]
#
# for i in range(n):
#     fmax[i][1] = a[i]
#     fmin[i][1] = a[i]
#
# for i in range(n):
#     for j in range(2, k + 1):
#         for m in range(max(i - d, 0), i):
#             fmax[i][j] = max(fmax[i][j], fmax[m][j - 1] * a[i], fmin[m][j - 1] * a[i])
#             fmin[i][j] = min(fmin[i][j], fmax[m][j - 1] * a[i], fmin[m][j - 1] * a[i])
#
# temp=[fmax[i][k] for i in range(n)]
# maxV = max(temp)
# print(maxV)
