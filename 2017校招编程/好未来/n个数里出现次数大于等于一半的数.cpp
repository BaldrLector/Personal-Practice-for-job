/*
题目描述
        输入n个整数，输出出现次数大于等于数组长度一半的数。
输入描述:
        每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n/2。
输出描述:
        输出出现次数大于等于n/2的数。
示例1
        输入

3 9 3 2 5 6 7 3 2 3 3 3
输出

3*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    vector<int> v;
    while (cin >> n) {
        v.push_back(n);
    }
    int cnt = 0, now = v[0];
    for (int i = 0; i < v.size(); i++) {
        if (now == v[i]) {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt < 0) {
            cnt = 0;
            now = v[i];
        }
    }
    cout << now << endl;

    return 0;

    return 0;
}
