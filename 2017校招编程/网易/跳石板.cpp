/*
题目描述
        小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
        输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述:
        输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1
        输入

4 24
输出

5*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void factor(int n, vector<int> & arr)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            arr.push_back(i);
            if(n / i != i)
                arr.push_back(n / i);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, 0);
    vector<int> factors;
    dp[n] = 1;
    for(int i = n; i <= m; i++)
    {
        if(!dp[i])
            continue;
        factors.clear();
        factor(i, factors);
        for(int j = 0; j < factors.size(); j++)
        {
            if(i + factors[j] <= m && dp[i + factors[j]])
                dp[i + factors[j]] = min(dp[i + factors[j]], dp[i] + 1);
            else if(i + factors[j] <= m)
                dp[i + factors[j]] = dp[i] + 1;
        }

    }
    cout << (dp[m] > 0 ? dp[m] - 1 : -1);
    return 0;
}

