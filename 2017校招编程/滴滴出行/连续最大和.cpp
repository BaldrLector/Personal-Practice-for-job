/*
题目描述
        一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
输入描述:
        输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
输出描述:
        所有连续子数组中和最大的值。
示例1
        输入

3 -1 2 1
输出

3*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    while(cin>>n){
        vector<int> dp(n),v(n);
        for(int i=0;i<n;i++)    cin>>v[i];
        dp[0]=v[0];
        for(int i=1;i<n;i++){
            dp[i]=max(v[i],dp[i-1]+v[i]);
        }
        int maxV=dp[0];
        for(int i=0;i<n;i++){
            if(maxV<dp[i])    maxV=dp[i];
        }
        cout<<maxV<<endl;
    }

    return 0;
}