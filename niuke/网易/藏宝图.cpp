/* 题目描述
牛牛拿到了一个藏宝图，顺着藏宝图的指示，牛牛发现了一个藏宝盒，藏宝盒上有一个机关，机关每次会显示两个字符串 s 和 t，根据古老的传说，牛牛需要每次都回答 t 是否是 s 的子序列。注意，子序列不要求在原字符串中是连续的，例如串 abc，它的子序列就有 {空串, a, b, c, ab, ac, bc, abc} 8 种。
输入描述:
每个输入包含一个测试用例。每个测试用例包含两行长度不超过 10 的不包含空格的可见 ASCII 字符串。
输出描述:
输出一行 “Yes” 或者 “No” 表示结果。
示例1
输入

x.nowcoder.com
ooo
输出

Yes */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>

using namespace std;


int main() {

    string s1, s2;
    while (cin>>s1>>s2) {
        int i=0,j=0;
        while (i<s1.size()&&j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            } else{
                i++;
            }
        }
        if(j==s2.size()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}