// BFS

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int A, B;
    cin>>A>>B;
    
    unordered_set<long long> visited;
    
    queue<pair<long long, long long>> q;
    q.push({A, 1});
    visited.insert(A);
    
    while(!q.empty())
    {
        long long temp = q.front().first;
        long long count = q.front().second;
        q.pop();
        
		// B보다 커지면 볼 필요 없음
        if (temp > B)
            continue;
        
        if (temp == B)
        {
            cout<<count<<"\n";
            return 0;
        }
        if (visited.count(temp * 10 + 1) == 0 && temp * 10 + 1 <= 1e9)
        {
            q.push({temp * 10 + 1, count + 1});
            visited.insert(temp * 10 + 1);
        }
        if (visited.count(temp * 2) == 0 && temp * 2 <= 1e9)
        {
            q.push({temp * 2, count + 1});
            visited.insert(temp * 2);
        }
        
    }
    cout<<-1<<"\n";
    return 0;
}

