// DFS
// 트리의 지름: 어떤 한 지점에서 가장 먼 노드를 구한 다음, 그 노드에서 가장 먼 노드까지의 거리가 트리의 지름이 된다.(증명은 블로그)
// 따라서 DFS를 2번 돌면 구할 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result;
int pos;
void DFS(vector<pair<int, int>> graph[], bool visited[], int node, int weight)
{
    visited[node] = true;
    
    for(int i = 0;i < graph[node].size();i++)
    {
        int next = graph[node][i].first;
        int w = graph[node][i].second;
        
        if (visited[next] == false)
        {
            DFS(graph, visited, next, weight + w);
        }
    }
    if (result < weight)
    {
        result = weight;
        pos = node;
    }
    result = max(result, weight);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    vector<pair<int, int>> graph[100001];
    bool visited[100001];

    for(int i = 1;i <= N;i++)
    {
        int n;
        cin>>n;
        
        while(1)
        {
            int node;
            cin>>node;
            
            if (node == -1)
                break;
            
            else
            {
                int w;
                cin>>w;
                
                graph[n].push_back({node, w});
            }
        }
    }
    result = 0;
    fill_n(visited, N + 1, false);
    DFS(graph, visited, 1, 0);
    
    result = 0;
    fill_n(visited, N + 1, false);
    DFS(graph, visited, pos, 0);

    cout<<result<<"\n";
    
    return 0;
}

