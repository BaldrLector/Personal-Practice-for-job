/*
题目描述
        有一条彩色宝石项链，是由很多种不同的宝石组成的，包括红宝石，蓝宝石，钻石，翡翠，珍珠等。有一天国王把项链赏赐给了一个学者，并跟他说，你可以带走这条项链，但是王后很喜欢红宝石，蓝宝石，紫水晶，翡翠和钻石这五种，我要你从项链中截取连续的一小段还给我，这一段中必须包含所有的这五种宝石，剩下的部分你可以带走。如果无法找到则一个也无法带走。请帮助学者找出如何切分项链才能够拿到最多的宝石。
输入描述:
        我们用每种字符代表一种宝石，A表示红宝石，B表示蓝宝石，C代表紫水晶，D代表翡翠，E代表钻石，F代表玉石，G代表玻璃等等，我们用一个全部为大写字母的字符序列表示项链的宝石序列，注意项链是首尾相接的。每行代表一种情况。
输出描述:
        输出学者能够拿到的最多的宝石数量。每行一个
        示例1
输入

        ABCYDYE
ATTMBQECPD
        输出

1
3*/

/*，先是右指针一直往后移动，知道左右指针之间包含了ABCDE 5个字母之后，然后更新长度，更新完了之后，左指针往右移动，
直到左右指针之间已经不完全包含ABCDE之后，右指针又开始像右移动，直到完全包含，又更新，一直下去，直到右指针到了字符串的右边界*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    string s;
    int i,j,num,len;
    while(cin>>s){
        len=s.length();
        s=s+s;
        i=0,j=0,num=0;
        int Min=len;
        map<char,int> book;
        while(true){
            while(i<s.length()&&num<5){
                if((s[i]=='A'||s[i]=='B'||s[i]=='C'||s[i]=='D'||s[i]=='E')
                   &&book[s[i]]++==0)
                    num++;
                i++;
            }
            if(num<5) break;
            Min=min(Min,i-j);
            if((s[j]=='A'||s[j]=='B'||s[j]=='C'||s[j]=='D'||s[j]=='E')
               &&--book[s[j]]==0) num--;
            j++;
        }
        printf("%d\n",len-Min);
    }
}//尺取法，求包含ABCDE的最短字串