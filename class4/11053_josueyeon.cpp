// DP
// 이전 값들과 비교했을 때 현재값이 큰 경우 dp 테이블이 가장 큰 값을 저장한다.
// 이때 정답이 dp 테이블 중간에 있을 수도 있기 때문에 max()로 계속 최댓값을 확인해야 한다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    
    int N;
    cin>>N;
    
    vector<int> v;
    int dp[1000];
    
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    fill_n(dp,1000, 1);

    int answer = 0;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < i;j++)
        {
            if (v[j] < v[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }
    cout<<answer<<"\n";
    
    return 0;
}

