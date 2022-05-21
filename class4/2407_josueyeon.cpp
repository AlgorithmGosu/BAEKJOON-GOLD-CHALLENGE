// DP + divide and qonquer
// __uint128_t gcc compiler 가 인식 가능한 자료형은 2^30 까지 표현 가능함

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

__uint128_t dp[105][105];

__uint128_t comb(int n, int m)
{
    if (n == m || m == 0)
        return 1;
    
    if (dp[n][m] != 0)
        return dp[n][m];
    
    return dp[n][m] = comb(n - 1, m - 1) + comb(n - 1, m);
}

int main()
{
    int n, m;
    cin>>n>>m;
    
    int arr[100];
    int idx = 0;
    
    dp[0][0] = 1;
    dp[1][1] = 1;
    __uint128_t res = comb(n, m);
    while(res > 0)
    {
        arr[idx++] = res % 10;
        res = res / 10;
    }
    while(--idx >= 0)
        cout<<arr[idx];
    cout<<"\n";
    
    return 0;
}


