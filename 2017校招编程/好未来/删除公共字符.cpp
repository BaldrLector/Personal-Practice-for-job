/*
题目描述
        输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述:
        每个测试输入包含2个字符串
输出描述:
        输出删除后的字符串
示例1
        输入

They are students. aeiou
        输出

Thy r stdnts.*/

#include<iostream>
#include<string>

using namespace std;

int main(){

    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    bool Hash[300]={false};
    for(int i=0;i<s2.size();i++){
        Hash[s2[i]]=true;
    }
    for(int i=0;i<s1.size();i++){
        if(Hash[s1[i]]==false) cout<<s1[i];
    }
    cout<<endl;
    return 0;
}