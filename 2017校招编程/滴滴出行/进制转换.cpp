/*
题目描述
        给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
        输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述:
        为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1
        输入

7 2
输出

111*/

#include<iostream>
#include<math.h>
#include<string>
using namespace std;

char num[1001],c=0;

void toN(int m,int n){

    while(m!=0){
        int r=m%n;
        if(r>=0&&r<=9)    num[c++]='0'+r;
        else if(r==10)    num[c++]='A';
        else if(r==11)    num[c++]='B';
        else if(r==12)    num[c++]='C';
        else if(r==13)    num[c++]='D';
        else if(r==14)    num[c++]='E';
        else if(r==15)    num[c++]='F';
        m/=n;
    }
}

int main(){

    int m,n;
    c=0;
    while(cin>>m>>n){
        bool flag=true;
        if(m<0){
            m=-m;
            flag=false;
        }
        toN(m,n);
        if(flag==false) cout<<"-";
        for(int i=c-1;i>=0;i--) cout<<num[i];
        cout<<endl;
    }


    return 0;
}