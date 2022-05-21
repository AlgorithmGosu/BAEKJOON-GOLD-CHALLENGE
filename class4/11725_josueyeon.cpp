// DFS: 다음 노드를 확인하기 전에 다음 노드의 부모 노드인 현재 노드를 1차원 배열에 저장한다.

#include <iostream>
#include <vector>
using namespace std;

int parent[100001];
void DFS(vector<int> graph[], bool visited[], int start)
{
    visited[start] = true;
    
    for(int i = 0;i < graph[start].size();i++)
    {
        if (visited[graph[start][i]] == false)
        {
            parent[graph[start][i]] = start;
            DFS(graph, visited, graph[start][i]);
        }
    }
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    vector<int> graph[100001];
    bool visited[100001];
    
    for(int i = 0;i < N - 1;i++)
    {
        int a, b;
        cin>>a>>b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    fill_n(visited, N + 1, false);
    DFS(graph, visited, 1);
    
    for(int i = 2;i <= N;i++)
        cout<<parent[i]<<"\n";
    
    return 0;
}

