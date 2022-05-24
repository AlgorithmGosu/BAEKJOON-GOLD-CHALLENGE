// MST: 최소 스패닝 트리 - kruskal algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];
int findParent(int x)
{
    return (x == parent[x] ? x : parent[x] = findParent(parent[x]));
}
void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    vector<pair<int, pair<int, int>>> graph;
    fill_n(parent, N + 1, 0);
    for(int i = 1;i <= N;i++)
        parent[i] = i;
    
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            int temp;
            cin>>temp;
            
            if (j >= i + 1)
                graph.push_back({temp, {i, j}});
        }
    }
    sort(graph.begin(), graph.end());
    
    long result = 0;
    for(int i = 0;i < graph.size();i++)
    {
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        int w = graph[i].first;
        
        if (findParent(x) != findParent(y))
        {
            result += w;
            unionParent(x, y);
        }
    }
    cout<<result<<"\n";
    
    return 0;
}

