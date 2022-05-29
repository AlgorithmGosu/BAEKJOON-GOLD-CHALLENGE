// union-find: 사이클 판별하기

#include <vector>
#include <iostream>
using namespace std;

int parent[500001];

int findParent(int x)
{
    return (x == parent[x] ? x : parent[x] = findParent(parent[x]));
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // n(node), m(edge)
    int n, m;
    cin>>n>>m;
    
    for(int i = 1;i <= n;i++)
        parent[i] = i;
    
    bool stop = false;
    int result = 0;
    for(int i = 0;i < m;i++)
    {
        int a, b;
        cin>>a>>b;
        
		// 사이클 판별
        if (findParent(a) != findParent(b) && !stop)
        {
            unionParent(a, b);
        }
        else if (!stop)
        {
            stop = true;
            result = i + 1;
        }
    }
    cout<<result<<"\n";
    
    return 0;
}

