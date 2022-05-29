// Tenary Search

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> town;

long long getDist(long long position)
{
    long long result = 0;
    for(int i = 0;i < town.size();i++)
    {
        if (town[i].first > position)
            result += (town[i].first - position) * town[i].second;
        else
            result += (position - town[i].first) * town[i].second;
    }
    return result;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // N(마을)
    int N;
    cin>>N;
    
    town.clear();
    for(int i = 0;i < N;i++)
    {
        long long a, b;
        cin>>a>>b;
        
        town.push_back({a, b});
    }
    
    long long low = -1e9;
    long long high = 1e9;
    
    while(low <= high)
    {
        long long mid = (low + high) / 2;
        
        long long left = getDist(mid);
        long long right = getDist(mid + 1);
        
        if (left <= right)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    cout<<low<<"\n";

    return 0;
}

