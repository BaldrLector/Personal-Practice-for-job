/*
题目描述
        将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述:
        每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
        输出描述:
依次输出倒置之后的字符串,以空格分割
        示例1
输入

        I like beijing.
输出

        beijing. like I*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(){

    int c=0;
    string ss[110];
    while(cin>>ss[c++]){}
    for(int i=c-2;i>=0;i--){
        cout<<ss[i];
        if(i!=0)    cout<<" ";
    }
    return 0;
}