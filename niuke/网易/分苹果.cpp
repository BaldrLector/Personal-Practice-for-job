// [编程题] 分苹果
// n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数

// 都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，问最少需要移动多少次可以平分苹

// 果，如果方案不存在输出 -1。 
// 输入描述:
// 每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），接下来的一行包含 n 

// 个整数 ai（1 <= ai <= 100）。


// 输出描述:
// 输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。

// 输入例子:
// 4
// 7 15 9 5

// 输出例子
// 3

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int ret = 0;
    int n = 0;
    int num = 0;
    while( cin >> n ){
        vector<int> data;
        int cnt = 0;
        int sum = 0;
        for( int i = 0; i < n; i++ ){
            cin >> num;
            data.push_back(num);
            sum += num;
        }
        if( sum % n != 0 ){
            cout << "-1" << endl;
            continue;
        }
        int avg = sum / n;
        for( int i = 0; i < n; i++ ){
            if( data[i] == avg ){
                continue;
            }
            int dif = data[i] - avg > 0 ? data[i] - avg : avg - data[i];
            if( dif % 2 != 0 ){
                cnt = -1;
                break;
            }
            if( data[i] > avg ){
                cnt += dif / 2;
            }
        }
        cout << cnt << endl;
    }
    return ret;
}



/* 首先判断不存在的情况。

1）当总和不能均分时；

2）当数据中同时出现了偶数以及奇数时；

3）当所有数为偶数并且总和均分为奇数 or 所有数为奇数并且总和均分为偶数时；

以上任一条件满足的时候直接输出-1即可。

否则，一遍循环找比均分值大的数，然后相减除2，累计即可。 */

#include <set>  
#include <map>  
#include <cmath>  
#include <queue>  
#include <vector>  
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
const int maxn = 100 + 5;  
  
int n;  
int a[maxn];  
  
void input() {  
  
    for(int i = 0; i < n; ++i) {  
        scanf("%d", &a[i]);  
    }  
}  
  
void solve() {  
  
    int suma = 0;  
    bool odd = false;  
    bool even = false;  
  
    for(int i = 0; i < n; ++i) {  
        suma += a[i];  
        if(a[i] % 2) odd = true;  
        else even = true;  
    }  
  
    int ave = suma / n;  
  
    if(suma % n) {  
        printf("-1\n");  
    }  
    else if(odd && even) {  
        printf("-1\n");  
    }  
    else if((odd && ave % 2 == 0) || (even && ave % 2 != 0)) {  
        printf("-1\n");  
    }  
    else {  
        int ans = 0;  
        for(int i = 0; i < n; ++i) {  
            if(a[i] > ave) ans += (a[i] - ave) / 2;  
        }  
        printf("%d\n", ans);  
    }  
}  
  
int main() {  
  
    while(scanf("%d", &n) != EOF) {  
        input();  
        solve();  
    }  
    return 0;  
}  