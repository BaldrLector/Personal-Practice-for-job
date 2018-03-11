/* 航天飞行器是一项复杂而又精密的仪器，飞行器的损耗主要集中在发射和降落的过程，科学家根据实验数据估计，如果在发射过程中，产生了 x 程度的损耗，那么在降落的过程中就会产生 x2 程度的损耗，如果飞船的总损耗超过了它的耐久度，飞行器就会爆炸坠毁。问一艘耐久度为 h 的飞行器，假设在飞行过程中不产生损耗，那么为了保证其可以安全的到达目的地，只考虑整数解，至多发射过程中可以承受多少程度的损耗？
输入描述:
每个输入包含一个测试用例。每个测试用例包含一行一个整数 h （1 <= h <= 10^18）。
输出描述:
输出一行一个整数表示结果。
示例1
输入

10
输出

2 */

/* 分析：暴力。令 x = sqrt(h)，然后判断 x 是否满足题意（x + x * x <= h），若不满足，则 x -= 1 直到满足为止。
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
  
long long h;  
  
int main() {  
  
    while(scanf("%lld", &h) != EOF) {  
        long long x = (long long)sqrt(h);  
        for(; x >= 0; --x) {  
            if(x + x * x <= h) {  
                printf("%lld\n", x);  
                break;  
            }  
        }  
    }  
    return 0;  
}  

