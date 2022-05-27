// MST: kruskal algorithm
// 이때 대학교의 그룹이 같은 경우는 간선 vector에 추가하지 않는다

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int parent[1001];
bool IsWoman[1001];

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
    
    // N(node), M(edge)
    int N, M;
    cin>>N>>M;
    
    for(int i = 1; i <= N;i++)
    {
        char univ;
        cin>>univ;
        
        if (univ == 'W')
            IsWoman[i] = true;
        
        else if (univ == 'M')
            IsWoman[i] = false;
    }
    
    for(int i = 1;i <= N;i++)
        parent[i] = i;
    
    vector<pair<int, pair<int, int>>> graph;
    for(int i = 0;i < M;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        if (IsWoman[a] != IsWoman[b])
            graph.push_back({c, {a, b}});
    }
    
    sort(graph.begin(), graph.end());
    
    long result = 0;
    for(int i = 0;i < graph.size();i++)
    {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        int w = graph[i].first;
        
        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            result += w;
        }
    }
    
    for(int i = 1;i <= N;i++)
    {
        if (findParent(i) != findParent(1))
        {
            result = -1;
            break;
        }
    }
    cout<<result<<"\n";
    
    return 0;
    
}

