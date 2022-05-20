// BFS: 이때 2배로 가는 경로는 0초가 걸리므로 업데이트가 발생할 수 있다.
// 따라서 값이 수정되는 조건에 현재 값이 업데이트보다 큰 경우에도 업데이트 할 수 있도록 설정한다.

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, K;
    cin>>N>>K;
    
    int d[100001];
    fill_n(d, 100001, -1);
    
    queue<int> q;
    q.push(N);
    d[N] = 0;
    
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        
        if (temp == K)
        {
            cout<<d[temp]<<"\n";
            return 0;
        }
        
        if (temp - 1 >= 0 && ((d[temp] + 1 < d[temp - 1]) || (d[temp - 1] == -1)))
        {
            d[temp - 1] = d[temp] + 1;
            q.push(temp - 1);
        }
        
        if (temp + 1 <= 100000 && (d[temp] + 1 < d[temp + 1] || d[temp + 1] == -1))
        {
            d[temp + 1] = d[temp] + 1;
            q.push(temp + 1);
        }
        
        if (temp * 2 <= 100000 && (d[temp] < d[temp * 2] || d[temp * 2] == -1))
        {
            d[temp * 2] = d[temp];
            q.push(temp * 2);
        }
    }
    
    return 0;
}

