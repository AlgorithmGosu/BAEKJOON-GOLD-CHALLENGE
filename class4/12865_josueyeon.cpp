// DP
// 쪼갤 수 없는 베낭 문제 -> DP
// 쪼갤 수 있는 베낭 문제 -> Greedy

#include <iostream>
#include <vector>
using namespace std;

int backpack[101][100001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // 물건 개수, 최대 무게
    int N, W;
    cin>>N>>W;
    
    vector<pair<int, int>> graph;
    for(int i = 1;i <= N;i++)
    {
        int a, b;
        cin>>a>>b;
        
        // {무게, 가치}
        graph.push_back({a, b});
        
        for(int j = 1;j <= W;j++)
        {
            if (a <= j)
            {
                backpack[i][j] = max(backpack[i - 1][j - a] + b, backpack[i - 1][j]);
            }
            else
            {
                backpack[i][j] = backpack[i - 1][j];
            }
        }
    }

    cout<<backpack[N][W]<<"\n";
    
    return 0;
}

