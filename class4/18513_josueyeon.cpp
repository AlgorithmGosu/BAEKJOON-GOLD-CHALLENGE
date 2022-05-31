// BFS

#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

unordered_set<long long> visited;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N, K;
    cin>>N>>K;

    visited.clear();
    priority_queue<pair<long long, long long>> q;
    for(int i = 0;i < N;i++)
    {
        long long temp;
        cin>>temp;
        
        q.push({0, temp});
        visited.insert(temp);
    }
    
    long long sum = 0;
    int count = 0;
    while(count < K && !q.empty())
    {
        long long w = q.top().first * -1;
        long long pos = q.top().second;
        
        q.pop();
        
        if (pos < -1e9 || pos > 1e9)
            continue;
        
        if (visited.count(pos + 1) == 0)
        {
            visited.insert(pos + 1);
            q.push({(w + 1) * -1, pos + 1});
            sum += w + 1;
            count++;
        }
        
        if (visited.count(pos - 1) == 0)
        {
            visited.insert(pos - 1);
            q.push({(w + 1) * -1, pos - 1});
            sum += w + 1;
            count++;
        }
    }

    cout<<sum<<"\n";
    
    return 0;
}


