// DFS

#include <iostream>
#include <vector>
using namespace std;

int graph[17][17];
int result;

// 가로(0), 대각선(1), 세로(2)
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

void DFS(int n, int x1, int y1, int x2, int y2, int flag)
{
    if (x2 == n && y2 == n)
    {
        result++;
        return;
    }
    
    int start = 0;
    int end = 0;

	// flag를 세워서 방향에 따라 가능한 진행 방향을 인덱스로 제한함

    // 가로
    if (flag == 0)
    {
        start = 0;
        end = 1;
    }
    // 세로
    else if (flag == 2)
    {
        start = 1;
        end = 2;
    }
    // 대각선인 경우
    else if (flag == 1)
    {
        start = 0;
        end = 2;
    }
    
    for(int dir = start;dir <= end;dir++)
    {
        int tempX1 = x2;
        int tempY1 = y2;
        
        int tempX2 = x2 + dx[dir];
        int tempY2 = y2 + dy[dir];

        if (tempX1 <= 0 || tempX1 > n || tempY1 <= 0 || tempY1 > n ||
            tempX2 <= 0 || tempX2 > n || tempY2 <= 0 || tempY2 > n)
            continue;

        if (graph[tempX2][tempY2] != 1)
        {
            if (dir == 1)
            {
                if (graph[tempX2 - 1][tempY2] != 1 && graph[tempX2][tempY2 - 1] != 1)
                    DFS(n, tempX1, tempY1, tempX2, tempY2, dir);
            }
            else
                DFS(n, tempX1, tempY1, tempX2, tempY2, dir);
        }
    }

    
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    // N(집 크기)
    int n;
    cin>>n;
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
            cin>>graph[i][j];
    }
    result = 0;
    DFS(n, 1, 1, 1, 2, 0);
    cout<<result<<"\n";
    
    return 0;
}

