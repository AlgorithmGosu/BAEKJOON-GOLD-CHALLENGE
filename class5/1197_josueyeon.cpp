// 최소 신장 트리: kruskal algorithm (greedy)
// 가장 가중치가 낮은 간선부터 선택하여 union-find 연산으로 같은 집합에 속하도록 만드는 과정을 반복(사이클이 생기지 않는 경우에 대해서)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1197 MST

int parent[100001];
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
    ios::sync_with_stdio(false);
    
    int V, E;
    cin>>V>>E;
    
    vector<pair<int, pair<int, int>>> graph;
    for(int i = 0;i < E;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
        graph.push_back({c, {a, b}});
    }
    
    sort(graph.begin(), graph.end());
    
    for(int i = 1;i <= V;i++)
        parent[i] = i;
    
    int result = 0;
    for(int i = 0;i < graph.size();i++)
    {
        int w = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        
        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            result += w;
        }
    }
    cout<<result<<"\n";
    
    return 0;
    
}

