n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cnt = 0

mean_a = sum(a) / n
mean_b = sum(b) / m


if mean_a > mean_b:
    for i in a:
        if i <= mean_a and i > mean_b and i not in b:
            cnt += 1
else:
    for i in b:
        if i > mean_a and i <= mean_b and i not in a:
            cnt += 1

print(cnt)
