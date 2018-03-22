m, n = [int(x) for x in input().split()]
nums = [[int(x) for x in input().strip()] for _ in range(m)]
start, end = min(min(row) for row in nums), sum(sum(row) for row in nums) // 16 + 1

sums = [[0] * (n + 1) for _ in range(m + 1)]

for i in range(1, m + 1):
    for j in range(1, n + 1):
        sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + nums[i - 1][j - 1]


def cal(si, ei, sj, ej):
    return sums[si][sj] - sums[si][ej + 1] - sums[ei + 1][sj] + sums[ei + 1][ej + 1]


def guess(target):
    for l1 in range(m - 3):
        if cal(0, l1, 0, n - 1) < target * 4: continue
        for l2 in range(l1 + 1, m - 2):
            if cal(l1 + 1, l2, 0, n - 1) < target * 4: continue
            for l3 in range(l2 + 1, m - 1):
                if cal(l2 + 1, l3, 0, n - 1) < target * 4: continue
                if cal(l3 + 1, m - 1, 0, n - 1) < target * 4: continue
                start, count = 0, 0
                for i in range(n):
                    if cal(0, l1, start, i) >= target \
                            and cal(l1 + 1, l2, start, i) >= target \
                            and cal(l2 + 1, l3, start, i) >= target \
                            and cal(l3 + 1, m - 1, start, i) >= target:
                        start, count = i + 1, count + 1
                    if count == 4:
                        return True
    return False


while start < end:
    mid = (start + end) // 2
    if not guess(mid):
        end = mid
    else:
        start = mid + 1
print(end - 1)
