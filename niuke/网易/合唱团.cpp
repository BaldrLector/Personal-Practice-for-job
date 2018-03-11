/* 有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入

3
7 4 7
2 50
输出

49 */





/* 

1. 题目分析

题目要求n各学生中选择k个，使这k个学生的能力值乘积最大。这是一个最优化的问题。另外，在优化过程中，提出了相邻两个学生的位置编号差不超过d的约束。
如果不用递归或者动态规划，问题很难入手，并且，限制条件d也需要对每一个进行约束，编程十分复杂
所以，解决的方法是采用动态规划（理由：1.求解的是最优化问题；2.可以分解为最优子结构）
2. 问题分解

1.对该问题的分解是关键。
从n个学生中，选择k个，可以看成是：先从n个学生里选择最后1个，然后在剩下的里选择k-1个，并且让这1个和前k-1个满足约束条件
2.数学描述
为了能够编程实现，需要归纳出其递推公式，而在写递推公式之前，首先又需要对其进行数学描述
记第k个人的位置为one,则可以用f[one][k]表示从n个人中选择k个的方案。然后，它的子问题，需要从one前面的left个人里面，选择k-1个，这里left表示k-1个人中最后一个（即第k-1个）人的位置，因此，子问题可以表示成f[left][k-1].
学生能力数组记为arr[n+1],第i个学生的能力值为arr[i]
one表示最后一个人，其取值范围为[1,n];
left表示第k-1个人所处的位置，需要和第k个人的位置差不超过d，因此
max{k-1,one-d}<=left<=one-1
在n和k定了之后，需要求解出n个学生选择k个能力值乘积的最大值。因为能力值有正有负，所以
当one对应的学生能力值为正时，
f[one][k] = max{f[left][k-1]arr[i]}(min{k-1,one-d}<=left<=one-1);
当one对应的学生能力值为负时
f[one][k] = max{g[left][k-1]arr[i]}(min{k-1,one-d}<=left<=one-1);
此处g[][]是存储n个选k个能力值乘积的最小值数组

 */




#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
const int maxn = 50 + 5;  
const long long minn = -1e17;  
  
struct DP {  
    long long mins;  
    long long maxs;  
}dp[maxn][15];  
  
int n;  
int a[maxn];  
int k, d;  
  
void input() {  
  
    for(int i = 1; i <= n; ++i) {  
        scanf("%d", &a[i]);  
    }  
    scanf("%d%d", &k, &d);  
}  
  
void solve() {  
  
    memset(dp, 0, sizeof(dp));  
    for(int i = 1; i <= n; ++i) dp[i][1].mins = dp[i][1].maxs = a[i];  
  
    long long ans = minn;  
    for(int i = 1; i <= n; ++i) {  
  
        for(int ki = 2; ki <= k; ++ki) {  
  
            int j = i - d;  
            if(j <= 0) j = 1;  
            for(; j < i; ++j) {  
  
                dp[i][ki].mins = min(dp[i][ki].mins, min(dp[j][ki - 1].mins * a[i], dp[j][ki - 1].maxs * a[i]));  
                dp[i][ki].maxs = max(dp[i][ki].maxs, max(dp[j][ki - 1].mins * a[i], dp[j][ki - 1].maxs * a[i]));  
            }  
        }  
    }  
  
    for(int i = 1; i <= n; ++i) {  
          
        ans = max(ans, dp[i][k].maxs);  
          
    }  
  
    printf("%lld\n", ans);  
}  
  
int main() {  
  
    while(scanf("%d", &n) != EOF) {  
        input();  
        solve();  
    }  
    return 0;  
}  

/* 



 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int k, d;
        cin >> k >> d;
        vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
        for (int i = 0; i < n; i++){
            dp_max[i][1] = a[i];
            dp_min[i][1] = a[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = 2; j <= k; j++){
                for (int m = max(0, i - d); m <= i - 1; m++){
                    dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
                    dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
                }
            }
        }
        long long max_value = dp_max[k - 1][k];
        for (int i = k; i < n; i++){
            max_value = max(max_value, dp_max[i][k]);
        }
        cout << max_value << endl;
    }
    return 0;
}