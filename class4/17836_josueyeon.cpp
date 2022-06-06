// BFS: 두번 BFS 진행해주면 됨

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int graph[101][101];
int visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int BFS(int n, int m)
{
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{0, 0}, 0});
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        
        int time = q.front().second;
        
        q.pop();
    
        for(int dir = 0;dir < 4;dir++)
        {
            int tempX = x + dx[dir];
            int tempY = y + dy[dir];
            
            if (tempX < 0 || tempX >= n || tempY < 0 || tempY >= m)
                continue;
            
            if (graph[tempX][tempY] != 1 && visited[tempX][tempY] == 0)
            {
                visited[tempX][tempY] = time + 1;
                q.push({{tempX, tempY}, time + 1});
            }
        }
    }
    return visited[n - 1][m - 1];
}

int swordBFS(int n, int m, int swordX, int swordY)
{
    if (visited[swordX][swordY] == 0)
        return 0;
    
    int temp;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if (i == swordX && j == swordY)
                temp = visited[i][j];
            visited[i][j] = 0;
        }
    }
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{swordX, swordY}, temp});
    visited[swordX][swordY] = temp;
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        
        int time = q.front().second;
        
        q.pop();
    
        for(int dir = 0;dir < 4;dir++)
        {
            int tempX = x + dx[dir];
            int tempY = y + dy[dir];
            
            if (tempX < 0 || tempX >= n || tempY < 0 || tempY >= m)
                continue;
            
            if (visited[tempX][tempY] == 0)
            {
                visited[tempX][tempY] = time + 1;
                q.push({{tempX, tempY}, time + 1});
            }
        }
    }
    return visited[n - 1][m - 1];
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // N(집 크기)
    int n, m, T;
    cin>>n>>m>>T;
    
    int swordx, swordy;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cin>>graph[i][j];
            
            if (graph[i][j] == 2)
            {
                swordx = i;
                swordy = j;
            }
        }
    }
    
    int ans1 = BFS(n, m);
    int ans2 = swordBFS(n, m, swordx, swordy);
    
    int ans = min(ans1, ans2);
    
    if (ans > T ||(ans1 == 0 && ans2 == 0))
    {
        cout<<"Fail\n";
        return 0;
    }
    else if (ans1 * ans2 == 0)
    {
        if (ans1 == 0)
        {
            if (ans2 > T)
                cout<<"Fail\n";
            else
                cout<<ans2<<"\n";
        }
        else
        {
            if (ans1 > T)
                cout<<"Fail\n";
            else
                cout<<ans1<<"\n";
        }

    }
    else
        cout<<ans<<"\n";
    
    return 0;
}
