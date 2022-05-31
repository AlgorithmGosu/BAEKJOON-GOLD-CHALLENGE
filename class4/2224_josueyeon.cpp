// 플로이드 워셜

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int graph[123][123];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    for(int i = 0;i < 123;i++)
    {
        for(int j = 0;j < 123;j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 1e9;
        }
    }
    
    for(int i = 0;i < N;i++)
    {
        char a, b;
        string str;
        cin>>a>>str>>b;
        
        graph[a][b] = 1;
    }
    
    for(int i = 0;i < 123;i++)
    {
        for(int a = 0;a < 123;a++)
        {
            for(int b = 0;b < 123;b++)
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
        }
    }
    
    vector<pair<char, char>> ans;
    int count = 0;
    for(int i = 0;i < 123;i++)
    {
        for(int j = 0;j < 123;j++)
        {
            if  (graph[i][j] != 1e9 && graph[i][j] != 0)
            {
                if (i != j)
                {
                    count++;
                    ans.push_back({i, j});
                }
            }
        }
    }
    
    cout<<count<<"\n";
    for(int i = 0;i < ans.size();i++)
    {
        cout<<ans[i].first<<" => "<<ans[i].second<<"\n";
    }
    return 0;
}

