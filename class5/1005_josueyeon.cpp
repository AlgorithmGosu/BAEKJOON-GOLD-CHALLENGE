// 위상 정렬
// 같은 레벨에서는 가장 큰 값을 저장하도록 함

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int indegree[1001];
int times[1001];
int resultTime[1001];
vector<int> graph[1001];

void topologySort(int N, int W)
{
    queue<int> q;
    
    for(int i = 1;i <= N;i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            resultTime[i] = times[i];
        }
    }
    
    while(!q.empty())
    {
        int now = q.front();
        
        q.pop();
        
        if (now == W) {
            break;
        }
    
        for(int i = 0;i < graph[now].size();i++)
        {
            indegree[graph[now][i]] -= 1;
            resultTime[graph[now][i]] = max(resultTime[graph[now][i]], resultTime[now] + times[graph[now][i]]);
            if (indegree[graph[now][i]] == 0)
                q.push(graph[now][i]);
        }
    }
    
    cout<<resultTime[W]<<"\n";
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    for(int test = 0;test < T;test++)
    {
        for(int i = 0;i < 1001;i++)
            graph[i].clear();
        memset(times, 0, sizeof(times));
        memset(resultTime, 0, sizeof(resultTime));
        memset(indegree, 0, sizeof(indegree));
        
        // N(node), K(edge), W(target)
        int N, K, W;
        cin>>N>>K;
        
        for(int i = 1;i <= N;i++)
            cin>>times[i];
            
        for(int i = 0;i < K;i++)
        {
            int a, b;
            cin>>a>>b;
            
            graph[a].push_back(b);
            indegree[b] += 1;
        }
        
        cin>>W;
        
        topologySort(N, W);
    }
    
    return 0;
}

