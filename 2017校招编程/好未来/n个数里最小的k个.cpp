/*
题目描述
        找出n个数里最小的k个
输入描述:
        每个测试输入包含空格分割的n+1个整数，最后一个整数为k值,n
        不超过100。
输出描述:
        输出n个整数里最小的k个数。升序输出
        示例1
输入

3 9 6 8 -10 7 -11 19 30 12 23 5
输出

-11 -10 3 6 7*/

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<int> v;
    while(cin>>n){
        v.push_back(n);
    }
    int len=v.size();
    int k=v[len-1];
    v.pop_back();
    sort(v.begin(),v.end());
    for(int i=0;i<k-1;++i){
        cout<<v[i]<<' ';
    }
    cout<<v[k-1]<<endl;
    return 0;
}