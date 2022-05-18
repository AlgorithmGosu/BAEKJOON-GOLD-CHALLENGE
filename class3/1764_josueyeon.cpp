#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin>>N>>M;
    
    vector<string> result;
    unordered_map<string, int> m;
    
    for(int i = 0;i < N + M;i++)
    {
        string str;
        cin>>str;
        
        m[str] += 1;
        if (m[str] == 2)
            result.push_back(str);
    }
    
    sort(result.begin(), result.end());
    
    cout<<result.size()<<"\n";
    for(int i = 0;i < result.size();i++)
        cout<<result[i]<<"\n";
    
    return 0;
}

