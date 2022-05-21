#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin>>N>>M;
    
    vector<int> res;
    vector<int> comb;
    for(int i = 1;i <= N;i++)
        res.push_back(i);
    
    for(int i = 0;i < M;i++)
        comb.push_back(1);
    
    for(int i = 0;i < N - M;i++)
        comb.push_back(0);
    
    sort(comb.begin(), comb.end());
    
    stack<vector<int>> ans;
    do
    {
        vector<int> rest;
        for(int i = 0;i < comb.size();i++)
        {
            if (comb[i] == 1)
                rest.push_back(res[i]);
        }
        ans.push(rest);
    } while(next_permutation(comb.begin(), comb.end()));
    
    
    while(!ans.empty())
    {
        vector<int> temp = ans.top();
        for(int i = 0;i < temp.size();i++)
            cout<<temp[i]<<" ";
        cout<<"\n";
        ans.pop();
    }
     
    return 0;
    
}

