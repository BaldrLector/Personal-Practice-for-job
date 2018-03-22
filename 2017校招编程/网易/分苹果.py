# n = int(input())
# a = list(map(int, input().split()))
#
# even = False
# odd = False
#
# for e in a:
#     if e % 2 == 0:
#         even = True
#     else:
#         odd = True
#
# if sum(a) % n != 0 or (even and odd):
#     print(-1)
# else:
#     ans = 0
#     avg = sum(a) / n
#     for e in a:
#         if (e > avg): ans += (e - avg) // 2;
#     print(int(ans))



n = int(input())
a = list(map(int, input().split()))

def solve():
    if sum(a) % n != 0:
        return -1
    else:
        ans = 0
        avg = sum(a) / n
        for e in a:
            dif=abs(int(e-avg))
            if dif %2!=0:
                return -1
            else:
                ans+=dif//2
        return ans/2

print(int(solve()))