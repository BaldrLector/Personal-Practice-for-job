/*
题目描述
        Please create a function to extract the filename extension from the given path,return the extracted filename extension or null if none.
输入描述:
        输入数据为一个文件路径
输出描述:
        对于每个测试实例，要求输出对应的filename extension
示例1
        输入

Abc/file.txt
        输出

txt*/

#include<iostream>
#include<string>
using namespace std;

int main(){

    string s,res;
    cin>>s;
    int i;
    for(i=0;i<s.size();i++){
        if(s[i]=='.') break;
    }

    if(s[i]!='.') {
        cout<<"null"<<endl;
        return 0;
    }
    for(i++;i<s.size();i++) res+=s[i];
    cout<<res<<endl;

    return 0;
}