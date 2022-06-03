// union-find
#include <iostream>
#include <vector>
using namespace std;

int parent[1000001];
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
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    for(int i = 0;i <= n;i++)
        parent[i] = i;

    for(int i = 0;i < m;i++)
    {
        int oper, a, b;
        cin>>oper>>a>>b;

        if (oper == 0)
            unionParent(a, b);

        else if (oper == 1)
        {
             if (findParent(a) == findParent(b))
                 cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}

