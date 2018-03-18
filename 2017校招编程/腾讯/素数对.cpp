/*
题目描述
        给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
输入描述:
        输入包括一个整数n,(3 ≤ n < 1000)
输出描述:
        输出对数
示例1
        输入

10
输出

2*/

bool isPrime(int n) {
    if (n == 2)
        return true;
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


int main() {
    int n;
    while (cin>>n){
        int p[10010] = {0}, c = 0;
        for (int i = 2; i < 1001; ++i) {
            if (isPrime(i)) {
                p[c++] = i;
            }
        }
        int i=0,j=c-1;
        int count=0;
        while (i<=j){
            if(p[i]+p[j]==n||2*p[i]==n||2*p[j]==n){
                count++;
                i++;
                j--;
            } else if(p[i]+p[j]>n){
                j--;
            } else{
                i++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}