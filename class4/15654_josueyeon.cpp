#include <iostream>
#include <algorithm>
#include <vector>
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
    {
        int temp;
        cin>>temp;
        
        res.push_back(temp);
    }
    
    sort(res.begin(), res.end());
    
    for(int i = 0;i < M;i++)
        comb.push_back(1);
    
    for(int i = 0;i < N - M;i++)
        comb.push_back(0);
    
    sort(comb.begin(), comb.end());
    
    vector<vector<int>> r;
    do
    {
        vector<int> rest;
        for(int i = 0;i < comb.size();i++)
        {
            if (comb[i] == 1)
                rest.push_back(res[i]);
        }
        
        do
        {
            r.push_back(rest);
        } while(next_permutation(rest.begin(), rest.end()));
        
    } while(next_permutation(comb.begin(), comb.end()));
    
    sort(r.begin(), r.end());
    
    for(int i = 0;i < r.size();i++)
    {
        for(int j = 0;j < r[i].size();j++)
        {
            cout<<r[i][j]<<" ";
        }
        cout<<"\n";
    }
     
    return 0;
    
}

