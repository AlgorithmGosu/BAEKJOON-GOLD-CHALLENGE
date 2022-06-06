// DFS

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> graph[2001];
int visited[2001];
int result = 0;

void DFS(int n, int count)
{
    if (count == 5)
    {
        result = 1;
        return;
    }

    visited[n] = 1;
    
    for(int i = 0;i < graph[n].size();i++)
    {
        if (visited[graph[n][i]] == 0)
            DFS(graph[n][i], count + 1);
    }
    visited[n] = 0;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin>>N>>M;

    
    for(int i = 0;i < M;i++)
    {
        int a, b;
        cin>>a>>b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i = 0;i < N;i++)
    {
        fill_n(visited, 2001, 0);
        result = 0;
        DFS(i, 1);
        if (result == 1)
        {
            cout<<result<<"\n";
            return 0;
        }
    }
    cout<<result<<"\n";
    
    return 0;
}
