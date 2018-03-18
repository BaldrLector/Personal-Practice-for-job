/*
题目描述
        Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
输入描述:
        输入为一个正整数N(1 ≤ N ≤ 1,000,000)
输出描述:
        输出一个最小的步数变为Fibonacci数"
示例1
        输入

15
输出

2*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> F(100010);


int main(){

    F[0]=0;
    F[1]=1;
    for(int i=2;i<F.size();i++){
        F[i]=F[i-1]+F[i-2];
    }


    int n;
    while(cin>>n){
        for(int i=0;i<F.size();i++){
            if(F[i]==n){
                cout<<0<<endl;
                break;
            }else if(F[i]>n){
                cout<<min(abs(F[i]-n),abs(n-F[i-1]))<<endl;
                break;
            }
        }
    }
    return 0;
}