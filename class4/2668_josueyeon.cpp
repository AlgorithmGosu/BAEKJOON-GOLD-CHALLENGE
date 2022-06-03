// DFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> graph[101];
int visited[101];

vector<int> res;
vector<int> temp;

void DFS(int node)
{
    visited[node] = 1;

    res.push_back(node);
    temp.push_back(graph[node][0]);
    
    for(int i = 0;i < graph[node].size();i++)
    {
        if (visited[graph[node][i]] == 0)
            DFS(graph[node][i]);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
     
    for(int i = 1;i <= N;i++)
    {
        int temp;
        cin>>temp;
        
        graph[i].push_back(temp);
    }
    
    set<int> ans;
    int size = ans.size();
    for(int i = 1;i <= N;i++)
    {
        res.clear();
        temp.clear();
        fill_n(visited, 101, 0);
        
        DFS(i);
    
        sort(temp.begin(), temp.end());
        sort(res.begin(), res.end());
        
        bool flag = true;
        for(int i = 0;i < res.size();i++)
        {
            if (res[i] != temp[i])
            {
                flag = false;
                break;
            }
        }
        
        if (flag == true)
        {
            for(int i = 0;i < res.size();i++)
                ans.insert(res[i]);
                
        }
    }
    for(int i = 1;i <= N;i++)
    {
        if (i == graph[i][0])
            ans.insert(i);
    }
    
    cout<<ans.size()<<"\n";
    for(auto i = ans.begin();i != ans.end();i++)
    {
        cout<<*i<<"\n";
    }
    
    return 0;
    
}
