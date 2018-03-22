x = int(input())
res, m = 100001, 1000000007
if x%m==0: res = 0
else:
    sum = (4*(x+1)-1)%m
    for i in range(3, 300001):
        sum = (2*sum+1)%m
        if sum==0:
            if i%3 == 0:
                res = i//3
            else:
                res = i//3+1
            break
print(res if res<=100000 else -1)