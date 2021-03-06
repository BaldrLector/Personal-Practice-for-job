# 题目描述
# 现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
# 输入描述:
# 输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n-1）组成，
# 下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
# 输出描述:
# 输出树的高度，为一个整数
# 示例1
# 输入
#
# 5
# 0 1
# 0 2
# 1 3
# 1 4
# 输出
#
# 3

n=int(input())
tree=[1]*n
ch=[0]*n
for i in range(n-1):
    f, child=map(int,input().split())
    if(ch[f]>=2):
        ch[child]=2
        continue

    tree[child]+=tree[f]
    ch[f]+=1
print(max(tree))