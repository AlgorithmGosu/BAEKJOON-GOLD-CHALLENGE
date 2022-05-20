#include <iostream>
#include <queue>
using namespace std;

// BFS

// 동 서 남 북
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M, result;

void BFS(int graph[1001][1001])
{
    // {{x, y}, {벽 부술까?, 몇번 돌았는지}}
    queue<pair<pair<int, int>, pair<bool, int>>> q;
    // {x, y, 벽을 부쉈니?}: 벽을 부순 유무에 따라서 다른 경로가 됨
    bool visit[1001][1001][2];
    
    // 초기화
    visit[0][0][0] = true;
    q.push({{0, 0}, {true, 1}});
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        
        bool wall = q.front().second.first;
        int count = q.front().second.second;
        
        if (x == N - 1 && y == M - 1)
        {
            result = count;
            return;
        }
        q.pop();
        
        for(int dir = 0;dir < 4;dir++)
        {
            int tempX = x + dx[dir];
            int tempY = y + dy[dir];
            
            if (tempX < 0 || tempY < 0 || tempX >= N || tempY >= M)
                continue;

            // 벽인데 부술 수 있는 경우
            if (graph[tempX][tempY] == 1 && wall == true)
            {
                visit[tempX][tempY][1] = true;
                q.push({{tempX, tempY}, {false, count + 1}});
            }
            
            // 벽이 아니고 방문한 적 없는 경우
            else if (graph[tempX][tempY] == 0 && visit[tempX][tempY][wall] == false)
            {
                visit[tempX][tempY][wall] = true;
                q.push({{tempX, tempY}, {wall, count + 1}});
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // N x M
    cin>>N>>M;
    
    int graph[1001][1001];
    
    for(int i = 0;i < N;i++)
    {
        string temp;
        cin>>temp;
        
        for(int j = 0;j < temp.size();j++)
        {
            graph[i][j] = temp[j] - 48;
        }
    }
    
    
    result = 0;
    
    BFS(graph);
    
    if (result == 0)
        cout<<-1<<"\n";
    else
        cout<<result<<"\n";
    return 0;
}

