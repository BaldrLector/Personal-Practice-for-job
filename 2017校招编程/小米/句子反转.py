a=input().split()

res=''
for i,s in enumerate(a[::-1]):
    if i!=0: res+=' '
    res+=s
print(res)