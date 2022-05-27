// shortest path: 플로이드 워셜(N:N)
// 아이템까지의 최단 거리를 구해서 수색 범위 내에 있는 아이템의 총합이 가장 큰 것을 반환

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int graph[101][101];
int item[31];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // n(지역 개수), m(수색 범위), r(길의 개수)
    int n, m, r;
    cin>>n>>m>>r;
    
    for(int i = 1;i <= 101;i++)
    {
        for(int j = 1;j <= 101;j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 1e9;
        }
    }
    
    // 구역에 있는 아이템의 수
    for(int i = 1;i <= n;i++)
        cin>>item[i];
    
    for(int i = 0;i < r;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
        graph[a][b] = c;
        graph[b][a] = c;
    }
    
    // 플로이드 워셜 탐색 진행
    for(int i = 1;i <= n;i++)
    {
        for(int a = 1;a <= n;a++)
        {
            for(int b = 1;b <= n;b++)
            {
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
            }
        }
    }
    
    int result = 0;
    for(int i = 1;i <= n;i++)
    {
        int sum = 0;
        for(int j = 1;j <= n;j++)
        {
            if (graph[i][j] <= m)
                sum += item[j];
        }
        result = max(sum, result);
    }
    
    cout<<result<<"\n";
    return 0;
}

