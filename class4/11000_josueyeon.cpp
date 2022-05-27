// priority_queue

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // N(수업 수)
    int N;
    cin>>N;
    
    vector<pair<int, int>> v;
    for(int i = 0;i < N;i++)
    {
        int start, end;
        cin>>start>>end;
        
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());

    priority_queue<long> pq;
    
    pq.push(v[0].second * -1);
    for(int i = 1;i < v.size();i++)
    {
        if (v[i].first >= pq.top() * -1)
        {
            pq.pop();
            pq.push(v[i].second * -1);
        }
        else
            pq.push(v[i].second * -1);
        
    }

    cout<<pq.size()<<"\n";
    
    return 0;
}

