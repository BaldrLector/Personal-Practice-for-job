/*
题目描述
        小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
例如：半径的平方如果为25
        优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。
输入描述:
        输入为一个整数，即为圆半径的平方,范围在32位int范围内。
输出描述:
        输出为一个整数，即为优雅的点的个数
        示例1
输入

25
输出

12*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){

    int r2;
    while(cin>>r2){
        int sqr=(int)sqrt(1.0*r2);
        //int i=0,j=sqr;
        int cnt=0;
        for(int i=0;i<=sqr;i++){
            for(int j=i;j<=sqr;j++){
                if(i*i+j*j==r2){
                    if(i==0||i==j){
                        cnt+=4;
                    }else{
                        cnt+=8;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}