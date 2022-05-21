// 1697 숨바꼭질: BFS

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, K;
    cin>>N>>K;
    
    int d[100001] = {0,};
    
    queue<int> q;
    q.push(N);
    d[N] = 1;
    
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        
        if (temp == K)
        {
            cout<<d[temp] - 1<<"\n";
            return 0;
        }
        
        if (temp - 1 >= 0 && d[temp - 1] == 0)
        {
            d[temp - 1] = d[temp] + 1;
            q.push(temp - 1);
        }
        
        if (temp + 1 <= 100000 && d[temp + 1] == 0)
        {
            d[temp + 1] = d[temp] + 1;
            q.push(temp + 1);
        }
        
        if (temp * 2 <= 100000 && d[temp * 2] == 0)
        {
            d[temp * 2] = d[temp] + 1;
            q.push(temp * 2);
        }
    }
    
    return 0;
}

