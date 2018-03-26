
def F(n, s, m, now):
    if s > n :
        return 100001
    if s == n:
        return now
    else:
        return min(F(n, 2 * s, s, now + 1), F(n, s + m, m, now + 1))


n = int(input())
print(F(n, 1, 1, 0))
