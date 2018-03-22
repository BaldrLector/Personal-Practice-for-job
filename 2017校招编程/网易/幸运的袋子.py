def solution():
    n = int(input())
    nums = sorted(list(map(lambda x:int(x), input().strip().split())))
    count = 0
    while count < n and nums[count] == 1:
        count += 1
    if count == n: return n-1
    nums = nums[count:]
    n = len(nums)
    def dfs(id, sm, pr):
        lst = None
        result = count - pr + sm
        for i in range(id, n):
            if nums[i] != lst:
                if (pr * nums[i]) - (sm + nums[i]) <= count:
                    result += dfs(i + 1, sm + nums[i], pr * nums[i])
                    lst = nums[i]
                else:
                    break
        return result
    return dfs(0, 0, 1)
print(solution())
