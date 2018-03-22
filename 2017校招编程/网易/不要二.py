m, n = map(lambda x:int(x), input().strip().split())
num1 = (m // 4) * 2 + min(m % 4, 2)
num2 = (n // 4) * 2 + min(n % 4, 2)
print(num1 * num2 + (m - num1) * (n - num2))