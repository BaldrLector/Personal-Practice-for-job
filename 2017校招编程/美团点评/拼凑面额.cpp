/*
题目描述
        给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多，编写程序求组成N员（N为0-10000的非负整数）的不同组合的个数。
输入描述:
        输入为一个数字N，即需要拼凑的面额
        输出描述:
输出也是一个数字，为组成N的组合个数。
示例1
        输入

5
输出

2*/


/*动态规划，每一步的累加按照面值的大小而增加
**
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N;
    int a[6]={1,5,10,20,50,100};
    cin>>N;
    vector<long> d(N+1,0);
    d[0]=1;
    for(int i=0;i<6;i++)
        for(int j=1;j<=N;j++)
            if(j>=a[i])
                d[j]=d[j]+d[j-a[i]];

    cout<<d[N]<<endl;

    return 0;
}