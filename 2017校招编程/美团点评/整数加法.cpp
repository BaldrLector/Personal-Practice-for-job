/*
题目描述
        请设计一个算法能够完成两个用字符串存储的整数进行相加操作，对非法的输入则返回error
        输入描述:
输入为一行，包含两个字符串，字符串的长度在[1,100]。
输出描述:
        输出为一行。合法情况输出相加结果，非法情况输出error
        示例1
输入

123 123
abd 123
输出

246
Error
 */

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int main(){

    string s1, s2;
    while (cin >> s1 >> s2) {
        bool legal = true;
        string res;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        if (s1.size() > s2.size()) swap(s1, s2);
        int r = 0;
        int i = 0;
        for (; i < s1.size(); i++) {
            if (s1[i] >= '0' && s1[i] <= '9' && s2[i] >= '0' && s2[i] <= '9') {
                int temp = r + s1[i] - '0' + s2[i] - '0';
                res += '0' + temp % 10;
                r = temp / 10;
            } else {
                legal = false;
                break;
            }
        }
        for (; i < s2.size(); i++){
            int temp = r +s2[i] - '0';
            res += '0' + temp % 10;
            r = temp / 10;
        }
        if(r!=0)    res+='0'+r;
        reverse(res.begin(), res.end());
        if(legal)
            cout << res << endl;
        else
            cout<<"error"<<endl;

    }


    return 0;
}

