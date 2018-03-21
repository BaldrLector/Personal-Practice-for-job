/*
题目描述
        假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
输入描述:
        输入一个待编码的字符串,字符串长度小于等于100.
输出描述:
        输出这个编码的index
示例1
        输入

baca
        输出

16331*/


#include<bits/stdc++.h>

using namespace std;

bool f(string s, string a, string b) {
    int pos = s.find(a);
    if (pos == -1)
        return false;
    else {
        string temp = s.substr(pos + a.size(), s.size() - pos - 1);
        int pos = temp.find(b);
        if (pos == -1)
            return false;
        else
            return true;
    }
}


int main() {
    string s, a, b;
    while (cin >> s >> a >> b) {
        int p = 0, q = 0;
        if (f(s, a, b))
            p = 1;
        reverse(s.begin(), s.end());

        if (f(s, a, b))
            q = 1;

        if (p && q)
            cout << "both" << endl;
        else if (p && !q)
            cout << "forward" << endl;
        else if (!p && q)
            cout << "backward" << endl;
        else
            cout << "invalid" << endl;

    }
    return 0;
}


int main() {
        string s, s1, s2;
        while (cin >> s >> s1 >> s2) {
                bool forward = true, back = false;
                forward = subs(s, s1 + s2);
                reverse(s.begin(), s.end());
                bool backward = subs(s, s1 + s2);
                if (forward && backward)
                    cout << "both" << endl;
                else if (forward)
                    cout << "forward" << endl;
                else if (backward) {}
                    cout << "backward" << endl;
                else
                    cout << "invalid" << endl;
            
    }
        return 0;
}