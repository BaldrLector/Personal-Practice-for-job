/*
题目描述
        有一个X*Y的网格，小团要在此网格上从左上角到右下角，只能走格点且只能向右或向下走。请设计一个算法，计算小团有多少种走法。给定两个正整数int x,int y，请返回小团的走法数目。
输入描述:
        输入包括一行，逗号隔开的两个正整数x和y，取值范围[1,10]。
输出描述:
        输出包括一行，为走法的数目。
示例1
        输入

3 2
输出

10*/

#include<iostream>
#include<vector>

using namespace std;

int n,m;
int dp[11][11]={0};


int main(){

    cin>>n>>m;

    for(int i=0;i<=n;i++) dp[i][m]=1;
    for(int j=0;j<=m;j++) dp[n][j]=1;

    for(int i=n-1;i>=0;i--)
        for(int j=m-1;j>=0;j--){
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }

    cout<<dp[0][0]<<endl;

    return 0;
}