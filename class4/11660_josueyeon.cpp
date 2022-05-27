// DP: 겹치는 부분은 한번 더 더해줘서 중복을 체크한다.

#include <iostream>
#include <vector>
using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // N x N, M(횟수)
    int N, M;
    cin>>N>>M;
    
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            cin>>arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    
    for(int i = 0;i < M;i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        
        int sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout<<sum<<"\n";
    }
    return 0;
}


