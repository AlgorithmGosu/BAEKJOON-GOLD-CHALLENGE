#include <iostream>
#include <vector>
using namespace std;

// 1865 웜홀

long dist[501];
void bellmanFord(vector<pair<int, int>> graph[], int N, int start, bool &cycle)
{
    cycle = false;
    dist[start] = 0;
    for(int count = 1;count <= N;count++)
    {
        for(int i = 1;i <= N;i++)
        {
                for(int j = 0;j < graph[i].size();j++)
                {
                    int next = graph[i][j].first;
                    int w = graph[i][j].second;
                    
                    if (dist[next] > w + dist[i])
                    {
                        // N번째에서도 업데이트가 발생하면 음의 순환 발생
                        if (count == N)
                        {
                            cycle = true;
                            return;
                        }
                        dist[next] = w + dist[i];
                    }
                
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    //ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    while (T-- > 0)
    {
        // N(node), M(edge), W(웜홀)
        int N, M, W;
        cin>>N>>M>>W;
        
        vector<pair<int, int>> graph[501];
        fill_n(dist, N + 1, 1e9);

        for(int i = 0;i < M;i++)
        {
            int a, b, c;
            cin>>a>>b>>c;
            
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        
        for(int i = 0;i < W;i++)
        {
            int a, b, c;
            cin>>a>>b>>c;
            
            graph[a].push_back({b, c * -1});
        }
        
        bool cycle = false;
        bellmanFord(graph, N, 1, cycle);
        
        if (cycle == false)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    
    return 0;
}


