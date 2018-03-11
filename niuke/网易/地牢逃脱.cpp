/* 题目描述
给定一个 n 行 m 列的地牢，其中 '.' 表示可以通行的位置，'X' 表示不可通行的障碍，牛牛从 (x0 , y0 ) 位置出发，遍历这个地牢，和一般的游戏所不同的是，他每一步只能按照一些指定的步长遍历地牢，要求每一步都不可以超过地牢的边界，也不能到达障碍上。地牢的出口可能在任意某个可以通行的位置上。牛牛想知道最坏情况下，他需要多少步才可以离开这个地牢。
输入描述:
每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 50），表示地牢的长和宽。接下来的 n 行，每行 m 个字符，描述地牢，地牢将至少包含两个 '.'。接下来的一行，包含两个整数 x0, y0，表示牛牛的出发位置（0 <= x0 < n, 0 <= y0 < m，左上角的坐标为 （0, 0），出发位置一定是 '.'）。之后的一行包含一个整数 k（0 < k <= 50）表示牛牛合法的步长数，接下来的 k 行，每行两个整数 dx, dy 表示每次可选择移动的行和列步长（-50 <= dx, dy <= 50）
输出描述:
输出一行一个数字表示最坏情况下需要多少次移动可以离开地牢，如果永远无法离开，输出 -1。以下测试用例中，牛牛可以上下左右移动，在所有可通行的位置.上，地牢出口如果被设置在右下角，牛牛想离开需要移动的次数最多，为3次。
示例1
输入

3 3
...
...
...
0 1
4
1 0
0 1
-1 0
0 -1
输出

3 */


/* ……花了很大时间在思考，为什么大家都不敢做，居然到现在为止没人写题解……
……这是这一片题中，最没有思考价值的题目了，因为，是纯粹套路……

写过在这种方格图中四方向/八方向的BFS（宽度优先搜索）吗？
没写过的话，买一本《信息学奥赛一本通》，翻到算法部分，第八章，广度优先搜索，把练习题做掉。

我们假定你知道这种做法……
剩下来的问题是，揣摩题意。

“地牢的出口可能在任意某个可以通行的位置上”
还有，“最坏情况下，他需要多少步才可以离开这个地牢”
——这两句话在一起，导致题意很不明确……
于是你只能看样例和解释揣测了……

最坏情况下，看上去不是他不知道出口在哪里然后随机乱走，因为样例解释里说了，最坏在右下角，要3步——完全不知道的情况下，怎么可能只走3步？完全可以先右边走了，再走到左边，这远大于3步。
OK，既然出口应该是知道的，而且走3步看上去是直接走的，那么问题的题意很大概率是这个：

现在知道牛牛自己的起点，在终点（出口）是所有可通行格子中的一个的情况下，设哪一个格子为终点，会导致牛牛要走出去的最小步数最大？

问题清楚多了……
从起点出发，BFS整个图，然后找距离最远的可通行点，作为答案，OVER。

——什么，50种步伐怎么办？
——对每个格子，把50种步伐都试过去啊！ */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
 
int n,m;
int direction[55][2];
int dcnt;
char ground[55][55];
int dis[55][55];
 
struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point go(int idx){
        return Point(x+direction[idx][0],y+direction[idx][1]);
    }
    bool isOK(){
        return x>=0&&y>=0&&x<n&&y<m&&ground[x][y]=='.';
    }
};
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",ground[i]);
    }
    Point start;
    scanf("%d%d",&start.x,&start.y);
    scanf("%d",&dcnt);
    for(int i=0;i<dcnt;i++){
        scanf("%d%d",&direction[i][0],&direction[i][1]);
    }
    fill(dis[0],dis[54]+55,INT_MAX);
    dis[start.x][start.y]=0;
     
    queue<Point> q;
    q.push(start);
    while(!q.empty()){
        Point x=q.front();q.pop();
        for(int i=0;i<dcnt;++i){
            Point y=x.go(i);
            if(y.isOK()){
                if(dis[y.x][y.y]>dis[x.x][x.y]+1){
                    dis[y.x][y.y]=dis[x.x][x.y]+1;
                    q.push(y);
                }
            }
        }
    }
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ground[i][j]=='.') answer=max(answer,dis[i][j]);
        }
    }
    printf("%d\n",answer==INT_MAX?-1:answer);
    return 0;
}
