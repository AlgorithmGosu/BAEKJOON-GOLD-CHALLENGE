// 위상 정렬: 방향 그래프의 순서대로 정렬
// 이때 수업을 듣는 학기를 증가시키기 위해 pair를 사용해서 학기를 저장한다

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

vector<int> graph[1001];
int indegree[1001];

void topologySort(int N)
{
    vector<pair<int, int>> result;
    queue<pair<int, int>> q;
    
    for(int i = 1;i <= N;i++)
    {
        if (indegree[i] == 0)
            q.push({i, 1});
    }
    
    while(!q.empty())
    {
        int temp = q.front().first;
        int sem = q.front().second;
        
        q.pop();
        result.push_back({temp, sem});
        
        for(int i = 0;i < graph[temp].size();i++)
        {
            indegree[graph[temp][i]] -= 1;
            
            if (indegree[graph[temp][i]] == 0)
                q.push({graph[temp][i], sem + 1});
        }
    }
    
    sort(result.begin(), result.end());
    for(int i = 0;i < result.size();i++)
    {
        cout<<result[i].second<<" ";
    }
    cout<<"\n";
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // N(node), M(edge)
    int N, M;
    cin>>N>>M;
    
    for(int i = 0;i < M;i++)
    {
        int a, b;
        cin>>a>>b;
        
        graph[a].push_back(b);
        indegree[b] += 1;
    }
    
    topologySort(N);
    
    return 0;
}

