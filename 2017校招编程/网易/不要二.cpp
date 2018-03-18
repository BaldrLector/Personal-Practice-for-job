/*
题目描述
        二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
        ( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
        小易想知道最多可以放多少块蛋糕在网格盒子里。
输入描述:
        每组数组包含网格长宽W,H，用空格分割.(1 ≤ W、H ≤ 1000)
输出描述:
        输出一个最多可以放的蛋糕数
示例1
        输入

3 2
输出

4*/
//其实就是一个数学问题，分整除4，整除2，奇数等几种情况讨论即可。蛋糕位置就是间隔每个2*2的正方形的区域。

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int num[51][32];

int main(){
    int n,m;
    cin>>n>>m;
    int nn = n / 4 * 2;
    if(n % 4 == 1) nn++;
    if(n % 4 >= 2) nn+=2;
    int ans = m / 4 * n * 2;
    if( m % 4 == 1) ans += nn;
    if( m % 4 == 2) ans += nn * 2;
    if( m % 4 == 3) ans += nn + n;
    cout<<ans<<endl;
}


#include<iostream>

#include<vector>

using namespace std;



intmain(){

    intW, H, i, j, counts = 0;

    cin>>W>>H;

    if(W % 4== 0|| H % 4== 0){

        counts = W*H/2;

    }elseif(W % 2== 0&& H % 2== 0){

        counts = (W*H/4+ 1) * 2;

    }else{

        counts = W*H/2+ 1;

    }

    cout<<counts<<endl;

    return0;

}