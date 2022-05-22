// MST: kruskal algorithm

#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> edges;
int parent[100001];

int findParent(int x)
{
    return parent[x] = (parent[x] == x ? x : findParent(parent[x]));
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
    // N(집의 개수), M(길의 개수), result(결과)
    int N, M, result = 0;
    int maxresult = 0;
    cin>>N>>M;
    
    
    for(int i = 0;i < M;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
        edges.push_back({c, {a, b}});
    }
    
    for(int i = 1;i <= N;i++)
        parent[i] = i;
    
    sort(edges.begin(), edges.end());
    
    for(int i = 0;i < edges.size();i++)
    {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        
        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            result += cost;
            maxresult = max(cost, maxresult);
        }
    }
    
    result -= maxresult;
    cout<<result<<endl;
    
    return 0;
    
}
