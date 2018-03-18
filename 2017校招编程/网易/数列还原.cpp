/* 题目描述
牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，其中有一些位置（不超过 10 个）看不清了，但是牛牛记得这个数列顺序对的数量是 k，顺序对是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。
输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含两个整数 n 和 k（1 <= n <= 100, 0 <= k <= 1000000000），接下来的 1 行，包含 n 个数字表示排列 A，其中等于0的项表示看不清的位置（不超过 10 个）。
输出描述:
输出一行表示合法的排列数目。
示例1
输入

5 5
4 0 0 2 0
输出

2 */

/* 分析：暴力 + 预处理。由于未知数不超过10个，那么可以用next_permutation暴力枚举未知数的安插顺序。那么如何来求出总的顺序对呢？总顺序对可以拆分为三部分，即：
总顺序对 = 已知数间的顺序对 + 未知数间的顺序对 + 已知数和未知数间的顺序对；第一部分可以先求出来 O(100^2)，第二部分在每次暴力枚举时可以求出 O(55)，关键是第三部分，我们可以这样预处理，计算出每个未知数在每个位置上与已知数之间产生的顺序对数，这个是可以做到的，即算左边比它小的数有多少，右边算比它大的数。时间复杂度大概也就在O(10 * 100)。这样算来总的复杂度为：O(10! * 55)，是可以通过的。

代码清单： */


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
  
  
int n, k;  
int A[maxn];  
int bidx;  
int B[15];  
bool vis[maxn];  
  
void input() {  
  
    memset(vis, false, sizeof(vis));  
    for(int i = 0; i < n; ++i) {  
        scanf("%d", &A[i]);  
        vis[A[i]] = true;  
    }  
}  
  
int get_pair(int *a, int x) {  
  
    int cnt = 0;  
    for(int i = 0; i < x - 1; ++i) {  
        for(int j = i + 1; j < x; ++j) {  
            if(a[i] < a[j]) cnt += 1;  
        }  
    }  
    return cnt;  
}  
  
void solve() {  
  
    if(k > n * (n + 1) / 2) {  
        printf("0\n");  
        return ;  
    }  
    bidx = 0;  
    for(int i = 1; i <= n; ++i) {  
        if(!vis[i]) B[bidx++] = i;  
    }  
  
    int pair1 = 0;  
    for(int i = 0; i < n; ++i) {  
        if(A[i] == 0) continue;  
        for(int j = i + 1; j < n; ++j) {  
            if(A[j] != 0 && A[i] < A[j]) {  
                pair1 += 1;  
            }  
        }  
    }  
  
    int left[maxn][15], right[maxn][15];  
    memset(left, 0, sizeof(left));  
    memset(right, 0, sizeof(right));  
  
    for(int i = 0; i < bidx; ++i) {  
        int cnt = 0, id = 0;  
        for(int j = 0; j < n; ++j) {  
            if(A[j] != 0) {  
                if(A[j] < B[i]) cnt += 1;  
            }  
            else {  
                left[B[i]][id++] = cnt;  
            }  
        }  
        cnt = 0; id = bidx - 1;  
        for(int j = n - 1; j >= 0; --j) {  
            if(A[j] != 0) {  
                if(A[j] > B[i]) cnt += 1;  
            }  
            else {  
                right[B[i]][id--] = cnt;  
            }  
        }  
    }  
  
    int ans = 0;  
  
    do {  
  
        int sum = pair1 + get_pair(B, bidx);  
        for(int i = 0; i < bidx; ++i) {  
            sum = sum + left[B[i]][i] + right[B[i]][i];  
        }  
        if(sum == k) ans += 1;   
  
    }while(next_permutation(B, B + bidx));    
  
    printf("%d\n", ans);  
}  
  
int main() {  
  
    while(scanf("%d%d", &n, &k) != EOF) {  
        input();  
        solve();  
    }  
    return 0;  
}  