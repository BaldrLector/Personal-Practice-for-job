s1 = input()
s2 = input()
cnt = 0
for i in range(len(s1)+1):
    temp = s1[:i]+s2+s1[i:]
    if temp[::-1]==temp: cnt += 1
print(cnt)
