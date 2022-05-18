#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    priority_queue<int> pq;
    for(int i = 0;i < N;i++)
    {
        int x;
        cin>>x;
        
        if (x == 0)
        {
            if (pq.empty())
                cout<<0<<"\n";
            else
            {
                cout<<pq.top() * -1<<"\n";
                pq.pop();
            }
        }
        else
            pq.push(x * -1);
    }
    
   
    return 0;
}

