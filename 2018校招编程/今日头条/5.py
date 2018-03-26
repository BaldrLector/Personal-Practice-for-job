# n = int(input())
# a = [int(i) for i in input().split()]
#
# s = [i for i in range(n + 1)]
# dp = [0 for i in range(n + 1)]
#
# if max(a) < 0:
#     print("0 %d %d\n" % (a[0], a[n - 1]))
# else:
#     dp[0] = a[0]
#     for i in range(n):
#         if dp[i - 1] + a[i] > a[i]:
#             dp[i] = a[i] + dp[i - 1]
#             s[i] = s[i - 1]
#         else:
#             dp[i] = a[i]
#             s[i] = i
#
#     k = 0
#     for i, v in enumerate(dp):
#         if dp[k] < dp[i]:
#             k = i
#     print("%d %d %d\n" % (dp[k], a[s[k]], a[k]))

import math

while 1:
    n, m = list(map(int, input().split()))
    res = 0
    for i in range(m):
        res += n
        n = math.sqrt(n)
    print("%.2f" % (res))
