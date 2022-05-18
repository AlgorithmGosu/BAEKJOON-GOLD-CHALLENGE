#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int idx = 0;
    
    vector<int> res;
    vector<int> t;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        res.push_back(temp);
        t.push_back(temp);
    }
    
    sort(t.begin(), t.end());
    
    unordered_map<int, int> m;
    int temp = t[0];
    m[t[0]] = idx;
    for(int i = 1;i < N;i++)
    {
        if (temp != t[i])
        {
            idx++;
            m[t[i]] = idx;
            temp = t[i];
        }
    }
    
    for(int i = 0;i < res.size();i++)
    {
        res[i] = m[res[i]];
    }
    
    for(int i = 0;i < res.size();i++)
        cout<<res[i]<<" ";
    cout<<"\n";
    
    return 0;
}

