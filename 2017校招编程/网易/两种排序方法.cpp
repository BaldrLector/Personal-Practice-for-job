/*
题目描述
        考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
输入描述:
        输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
        输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",

如果根据长度排列而不是字典序排列输出"lengths",

如果两种方式都符合输出"both"，否则输出"none"
示例1
        输入

3
a
        aa
bbb
        输出

both*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isLex(vector<string> v){
    for(int i=1;i<v.size();i++){
        if(v[i]<v[i-1])    return false;
    }
    return true;
}


bool isLen(vector<string> v){
    for(int i=1;i<v.size();i++){
        if(v[i].size()<v[i-1].size())    return false;
    }
    return true;
}

int main(){

    int n;
    while(cin>>n){
        vector<string> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(isLen(v)&&isLex(v)){
            cout<<"both"<<endl;
        }else if(isLen(v)){
            cout<<"lengths"<<endl;
        }else if(isLex(v)){
            cout<<"lexicographically"<<endl;
        }else{
            cout<<"none"<<endl;
        }
    }

    return 0;
}