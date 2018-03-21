/*
题目描述
        给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
输入描述:
        输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 50000。第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)。
输出描述:
        输出保留下来的结果。
示例1
        输入

325 1
输出

35*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e4 + 20;
char str[maxn], s[maxn];
int k, top = 0, num = 0;

int main() {
    scanf("%s%d", str, &k);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        while (top > 0 && s[top - 1] < str[i] && num < k) {
            num++;
            top--;
        }
        s[top++] = str[i];
    }
    top = min(top, len - k);
    s[top] = '\0';
    puts(s);
    return 0;
}
