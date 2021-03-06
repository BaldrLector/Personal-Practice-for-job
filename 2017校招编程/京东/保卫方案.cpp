/*
题目描述
        战争游戏的至关重要环节就要到来了，这次的结果将决定王国的生死存亡，小B负责首都的防卫工作。首都位于一个四面环山的盆地中，周围的n个小山构成一个环，作为预警措施，小B计划在每个小山上设置一个观察哨，日夜不停的瞭望周围发生的情况。 一旦发生外地入侵事件，山顶上的岗哨将点燃烽烟，若两个岗哨所在的山峰之间没有更高的山峰遮挡且两者之间有相连通路，则岗哨可以观察到另一个山峰上的烽烟是否点燃。由于小山处于环上，任意两个小山之间存在两个不同的连接通路。满足上述不遮挡的条件下，一座山峰上岗哨点燃的烽烟至少可以通过一条通路被另一端观察到。对于任意相邻的岗哨，一端的岗哨一定可以发现一端点燃的烽烟。 小B设计的这种保卫方案的一个重要特性是能够观测到对方烽烟的岗哨对的数量，她希望你能够帮她解决这个问题。
输入描述:
        输入中有多组测试数据，每一组测试数据的第一行为一个整数n(3<=n<=10^6),为首都周围的小山数量，第二行为n个整数，依次表示为小山的高度h（1<=h<=10^9）.
输出描述:
        对每组测试数据，在单独的一行中输出能相互观察到的岗哨的对数。
示例1
        输入

5
1 2 4 5 3
输出

7*/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], b[maxn], L[maxn], R[maxn], C[maxn];
int n;

int main()
{
    cin >> n;           //输入山的数量
    int ma = -1, mid = 0;           //用于把a[]转化成最高山在第一位数组b[]的临时变量
    for (int i = 0; i < n; i++)         //输入a
    {
        cin >> a[i];
        if (a[i] > ma)
        {
            ma = a[i];
            mid = i;
        }
    }
    mid--;
    for (int j = 1; j <= n; j++)            //将a[]转化成最高的山在第一位的b[]，最高的山在b[1]
    {
        b[j] = a[(mid + j) % n];
    }
    L[1] = 1;           //left数组中设定最高的山，下一个比他高的设为1，即自己
    for (int i = 2; i <= n; i++)            //生成left数组
    {
        L[i] = i - 1;           //设定左边的第一座山就比自己高
        while (L[i] > 1 && b[L[i]] <= b[i])             //while语句左移直到找到比自己要高的山
            L[i] = L[L[i]];
    }
    for (int i = n; i >= 1; i--)            //生成right，C数组
    {
        R[i] = i + 1;           //设定右边第一座山就比自己高，并且设定右边的山默认是最高的，因为和最高的山相邻
        while (R[i] <= n && b[R[i]] < b[i])             //while语句右移知道找到跟自己相等或者比自己高的山
            R[i] = R[R[i]];
        if (R[i] <= n && b[R[i]] == b[i])           //如果跟自己一样高，则C[]++
        {
            C[i] = C[R[i]] + 1;
            R[i] = R[R[i]];
        }
    }

    long long ans = 0;              //结果可能很大，用longlong存储
    for (int i = 2; i <= n; i++)            //不用计算最高的山
    {
        ans += C[i] + 2;
        if (L[i] == 1 && R[i] == n + 1)             //此时就是和最高的山形成pair，重复计算了，所以减1
        {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}