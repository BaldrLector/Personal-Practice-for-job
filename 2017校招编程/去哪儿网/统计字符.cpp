/*
题目描述
        给定一个英文字符串,请写一段代码找出这个字符串中首先出现三次的那个英文字符。
输入描述:
        输入数据一个字符串，包括字母,数字等。
输出描述:
        输出首先出现三次的那个英文字符
示例1
        输入

Have you ever gone shopping and
        输出

e*/

#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

int main(){

    string s;
    getline(cin,s);
    int Hash[300]={0};
    for(int i=0;i<s.size();i++){
        Hash[s[i]]++;
        if(Hash[s[i]]==3&&isalpha(s[i])){
            cout<<s[i]<<endl;
            break;
        }
    }

    return 0;
}