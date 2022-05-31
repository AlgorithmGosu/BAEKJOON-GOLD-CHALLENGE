// Simulation

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int graph[50][50];

void BFS(int R, int C)
{
    // 미세먼지 확산
    queue<pair<int, int>> q;
    for(int i = 0;i < R;i++)
    {
        for(int j = 0;j < C;j++)
        {
            if (graph[i][j] != 0 && graph[i][j] != -1)
                q.push({i, j});
        }
    }
    
    int air[50][50];
    for(int i = 0;i < 50;i++)
        for(int j = 0;j < 50;j++)
            air[i][j] = 0;
    
    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        
        q.pop();
        
        int count = 0;
        for(int dir = 0;dir < 4;dir++)
        {
            int tempI = i + dx[dir];
            int tempJ = j + dy[dir];
            
            if (tempI < 0 || tempJ < 0 || tempI >= R || tempJ >= C)
                continue;
            
            else if (graph[tempI][tempJ] != -1)
            {
                count++;
                air[tempI][tempJ] += graph[i][j] / 5;
            }
        }
        graph[i][j] = graph[i][j] - ((graph[i][j] / 5) * count);
    }
    
    for(int i = 0;i < R;i++)
    {
        for(int j = 0;j < C;j++)
        {
            if (graph[i][j] != -1)
            {
                graph[i][j] += air[i][j];
            }
        }
    }
}

void purifierOn(int R, int C, pair<int, int> purifier[2])
{
    int firstR = purifier[0].first;
    int firstC = purifier[0].second;
    
    int clockwiseR[4] = {-1, 0, 1, 0};
    int clockwiseC[4] = {0, 1, 0, -1};
    
    int dir = 0;
    
    while(true)
    {
        if ((firstR == 0 && firstC == 0) || (firstR == 0 && firstC == C - 1)
            || (firstR == purifier[0].first && firstC == C - 1))
            dir++;
        
        int tempR = firstR + clockwiseR[dir];
        int tempC = firstC + clockwiseC[dir];
        
        if (graph[tempR][tempC] == -1)
        {
            graph[firstR][firstC] = 0;
            break;
        }
        
        if (graph[firstR][firstC] != -1)
            graph[firstR][firstC] = graph[tempR][tempC];
        
        firstR = tempR;
        firstC = tempC;
    }
    
    firstR = purifier[1].first;
    firstC = purifier[1].second;
    
    int counterclockwiseR[4] = {1, 0, -1, 0};
    int counterclockwiseC[4] = {0, 1, 0, -1};
    
    dir = 0;
    while(true)
    {
        if ((firstR == R - 1 && firstC == 0) || (firstR == R - 1 && firstC == C - 1)
            || (firstR == purifier[1].first && firstC == C - 1))
            dir++;
        
        int tempR = firstR + counterclockwiseR[dir];
        int tempC = firstC + counterclockwiseC[dir];
        
        if (graph[tempR][tempC] == -1)
        {
            graph[firstR][firstC] = 0;
            break;
        }
        
        if (graph[firstR][firstC] != -1)
            graph[firstR][firstC] = graph[tempR][tempC];
        
        firstR = tempR;
        firstC = tempC;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int R, C, T;
    cin>>R>>C>>T;
    
    pair<int, int> purifier[2];
    
    int idx = 0;
    for(int i = 0;i < R;i++)
    {
        for(int j = 0;j < C;j++)
        {
            cin>>graph[i][j];
            
            if (graph[i][j] == -1)
                purifier[idx++] = {i, j};
        }
    }

    for(int times = 0;times < T;times++)
    {
        BFS(R, C);
        purifierOn(R, C, purifier);
    }
    
    int result = 0;
    for(int i = 0;i < R;i++)
    {
        for(int j = 0;j < C;j++)
        {
            if (graph[i][j] != -1)
            {
                result += graph[i][j];
            }
        }
    }
    
    cout<<result<<"\n";
    return 0;
}

