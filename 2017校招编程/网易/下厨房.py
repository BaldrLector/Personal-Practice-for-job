import sys
s = set()
for line in sys.stdin:
    for f in line.split():
        s.add(f)
print(len(s))