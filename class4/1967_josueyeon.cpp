// DFS
// 1167 참조하기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1967 트리의 지름

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
            DFS(graph, visited, next, weight + w);
    }
    if (result < weight)
    {
        result = weight;
        pos = node;
    }
}

int main()
{
    // n(node)
    int n;
    cin>>n;
    
    vector<pair<int, int>> graph[10001];
    bool visited[10001];
    
    for(int i = 0;i < n - 1;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
        // a-b를 잇는 가중치 c
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    result = 0;
    fill_n(visited, n + 1, false);
    DFS(graph, visited, 1, 0);
    
    result = 0;
    fill_n(visited, n + 1, false);
    DFS(graph, visited, pos, 0);
    cout<<result<<"\n";
    
    return 0;
    
}


