n = int(input())
x = list(map(int,input().split()))
y = list(map(int,input().split()))

dist = [x[i] - 1 + y[i] - 1 for i in range(n)]

print(min(dist))
