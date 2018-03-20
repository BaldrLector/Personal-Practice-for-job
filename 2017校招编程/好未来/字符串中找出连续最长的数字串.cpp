/*
题目描述
        读入一个字符串str，输出字符串str中的连续最长的数字串
        输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述:
        在一行内输出str中里连续最长的数字串。
示例1
        输入

abcd12345ed125ss123456789
        输出

123456789*/

#include<iostream>
using namespace std;
int main(){
    string A;
    cin>>A;
    int flag=0,mflag=0,pos=0;
    int l=A.length();
    string B;
    for(int i=0;i<=l;i++)
    {
        if(A[i]>='0'&&A[i]<='9')
        {
            flag++;
        }
        else{
            if(flag>mflag)
            {
                mflag=flag;
                pos=i-flag;
            }
            flag=0;
        }
    }
    for(int j=0;j<mflag;j++)
    {
        B+=A[pos+j];
    }


    cout<<B;
    return 0;
}
