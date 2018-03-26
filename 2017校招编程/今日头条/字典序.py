n,m = [int(i) for i in input().split()]

def count_node(tmp,n):   #计算当前数字结点及以下一共有多少个结点
    count = 1
    base = 10
    while tmp*base<=n:
        add_count = min(tmp*base+base-1,n) - tmp*base + 1
        count += add_count
        base *= 10
    return count

def main(n,m):
    tmp = 1
    while m > 0:
        tmp_count = count_node(tmp,n)
        if m > tmp_count:
            tmp += 1
            m -= tmp_count
        elif m == 1:
            return tmp
        else:
            m -= 1
            tmp *= 10
    return tmp

print(main(n,m))