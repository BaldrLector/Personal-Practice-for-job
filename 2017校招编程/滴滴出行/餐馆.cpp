/*
题目描述
        某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数； 有m批客人，每批客人有两个参数:b人数，c预计消费金额。 在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大
        输入描述:
输入包括m+2行。 第一行两个整数n(1 <= n <= 50000),m(1 <= m <= 50000) 第二行为n个参数a,即每个桌子可容纳的最大人数,以空格分隔,范围均在32位int范围内。 接下来m行，每行两个参数b,c。分别表示第i批客人的人数和预计消费金额,以空格分隔,范围均在32位int范围内。
输出描述:
        输出一个整数,表示最大的总预计消费金额
示例1
        输入

3 5 2 4 2 1 3 3 5 3 7 5 9 1 10
输出

20*/

#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long llong;
int findTable(vector<llong> &table, int nums){
    int result = -1;
    for(llong i = 0; i < table.size(); ++i){
        if(table[i] >= nums){
            table[i] = 0;
            return i;
        }
    }
    return result;
}
bool compare(const vector<llong> &g1, const vector<llong> &g2){
    return g1[1] > g2[1];
}
llong CalMaxComsume(vector<llong> &table, vector<vector<llong>> &guest){
    llong result = 0;
    sort(table.begin(), table.end());
    stable_sort(guest.begin(), guest.end(),[](const vector<llong> &g1,const vector<llong> &g2){
        return g1[0]<g2[0];
    });
    stable_sort(guest.begin(), guest.end(),compare);

    for(llong i = 0; i < guest.size(); ++i){
        llong index = findTable(table, guest[i][0]);
        if(index != -1)
            result += guest[i][1];
    }
    return result;
}
int main(void)
{
    llong n, m;
    cin >> n >> m;
    vector<llong> table(n);
    vector<vector<llong>> guest(m, vector<llong>(2));
    for(int i = 0; i < n; ++i)
        cin >> table[i];
    for(int i = 0; i< m; ++i)
        cin >> guest[i][0] >> guest[i][1];
    cout << CalMaxComsume(table, guest);
    return 0;
}