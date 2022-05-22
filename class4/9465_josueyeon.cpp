// DP
// 스티커를 고르면 인접한 스티커는 고르지 못하기 때문에 둘 중에 큰 값을 골라서 선택한다

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    for(int len = 0;len < T;len++)
    {
        int N;
        cin>>N;
        
        int dp[2][100001];
        
        dp[0][0] = 0;
        dp[1][0] = 0;
        for(int i = 0;i < 2;i++)
        {
            for(int j = 1;j <= N;j++)
            {
                cin>>dp[i][j];
            }
        }
        
        for(int i = 2;i <= N;i++)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + dp[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + dp[1][i];
        }
        
        int result = max(dp[0][N], dp[1][N]);
        cout<<result<<"\n";
    }
    
    return 0;
}

