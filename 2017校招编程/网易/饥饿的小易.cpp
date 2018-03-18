/*
题目描述
        小易总是感觉饥饿，所以作为章鱼的小易经常出去寻找贝壳吃。最开始小易在一个初始位置x_0。对于小易所处的当前位置x，他只能通过神秘的力量移动到 4 * x + 3或者8 * x + 7。因为使用神秘力量要耗费太多体力，所以它只能使用神秘力量最多100,000次。贝壳总生长在能被1,000,000,007整除的位置(比如：位置0，位置1,000,000,007，位置2,000,000,014等)。小易需要你帮忙计算最少需要使用多少次神秘力量就能吃到贝壳。
输入描述:
        输入一个初始位置x_0,范围在1到1,000,000,006
输出描述:
        输出小易最少需要使用神秘力量的次数，如果使用次数使用完还没找到贝壳，则输出-1
示例1
        输入

125000000
输出

1*/

/*8x+7=8(x+1)-1
4x+3=4(x+1)-1
嵌套一下呢？
8(4x+3)+7=8((4(x+1)-1)+1 )-1=32(x+1)-1
继续往下，发现能生成的数很有规律哦！
利用这个规律，枚举很有限的次数就行了。*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

int main(){
    int n;
    while(~scanf("%d",&n)){
        int times=4;
        int ans=100001;
        for(int i=1;i<=300000;++i){
            int x=((long long)(n)*times+times-1)%mod;
            if(x==0){
                ans=(i+1)/3+((i+1)%3?1:0);
                break;
            }
            times=times*2%mod;
        }
        printf("%d\n",ans>100000?-1:ans);
    }
    return 0;
}