/*

题目描述
        游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。
输入描述:
        输入包括一行,两个整数表示人物ID.
输出描述:
        输出是否完成
示例1
        输入

1024 1024
输出
1*/

//#include<iostream>
//using namespace std;
//int main(){
//    int a,b;
//    while(cin>>a>>b){
//        if(b>=1&&b<=1024){
//            if(a==b){
//                cout<<1<<endl;
//            }else{
//                cout<<0<<endl;
//            }
//        }else{
//            cout<<-1<<endl;
//        }
//    }
//    return 0;
//}

//1024种任务有2^1024种可能，需要1024个bit，就是1024/8=128byte。一个int是4byte，刚好需要32个int。就是说，把32个int排成一行，就是1024个bit，每个bit来表示某个任务是否完成。
#include<iostream>
using namespace std;
//参数：s是32个int构成的数组。n表示第几个任务（在这里从0开始），deal表示操作类型：如果为1表示置位，否则表示取位。
int check(unsigned int* s,int n,int deal){//if deal==1 set; else get;
    int id=n/32;//注意n是从0开始的，否则就会不统一
    int id2=n%32;
    unsigned int b=0x80000000;//测试时候发现如果不加unsigned的话，就会出错。有符号数字会填充符号位
// b 表示左边第一位是1其他都是0的无符号整数。
    b>>=id2;
    if(deal==1){
        s[id]|=b;
        return -1;
    }else{

        return (s[id]&b)!=0;
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    unsigned int s[32]={};
    if(a<1||a>1024 ||b<1||b>1024){
        cout<<-1;
        return 0;
    }
    check(s,a-1,1);
    int i=check(s,b-1,0);
    if(i)
        cout<<1;
    else
        cout<<0;
    return 0;
}

