import re

s1 = input()
s2 = input()

r = '.*'

for c in s2:
    r = r + c + '.*'

if re.search(r, s1):
    print("Yes")
else:
    print("No")
