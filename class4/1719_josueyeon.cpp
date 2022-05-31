// Shortest path: 플로이드 워

#include <iostream>
#include <vector>
using namespace std;

int graph[201][201];
int dist[201][201];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // N(집 크기)
    int n, m;
    cin>>n>>m;
    
    for(int i = 0;i < 201;i++)
    {
        for(int j = 0;j < 201;j++)
        {
            if (i == j)
            {셜
                dist[i][j] = 0;
                graph[i][j] = 0;
            }
            else
            {
                dist[i][j] = 0;
                graph[i][j] = 1e9;
            }
        }
    }

    for(int i = 0;i < m;i++)
    {
        int a, b, cost;
        cin>>a>>b>>cost;
        
        graph[a][b] = cost;
        graph[b][a] = cost;
        
        dist[a][b] = b;
        dist[b][a] = a;
    }
    

    for(int i = 1;i <= n;i++)
    {
        for(int a = 1;a <= n;a++)
        {
            for(int b = 1;b <= n;b++)
            {
                if (graph[a][b] > graph[a][i] + graph[i][b])
                {
                    graph[a][b] = graph[a][i] + graph[i][b];

					// 거쳐가는 경로의 가장 앞의 경로로 업데이트
                    dist[a][b] = dist[a][i];
                }
            }
        }
    }
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if (i == j)
                cout<<'-'<<" ";
            else
                cout<<dist[i][j]<<" ";
        }
            
        cout<<"\n";
    }
    
    return 0;
}

/*
 - 2 1 5 5 7
 2 - 3 5 3 5
 1 3 - 4 6 7
 5 5 4 - 6 4
 5 3 6 6 - 2
 7 5 7 4 2 -
 */

