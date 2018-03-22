n = int(input())
s = []
for i in range(n):
    s.append(input())

lens, lexs = sorted(s, key=len), sorted(s)
if s == lexs and s == lens:
    print('both')
elif s == lexs:
    print('lexicographically')
elif s == lens:
    print('lengths')
else:
    print('none')
