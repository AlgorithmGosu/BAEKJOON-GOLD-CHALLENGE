// 1620 포켓몬 마스터
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin>>N>>M;
    
	// hash map 사용
    vector<string> pocketmon(100001);
    unordered_map<string, int> map;
    
    for(int i = 1;i <= N;i++)
    {
        string temp;
        cin>>temp;
        
        pocketmon[i] = temp;
        map[temp] = i;
    }
    
    for(int i = 0;i < M;i++)
    {
        string input;
        cin>>input;
        
        if (input[0] >= 65 && input[0] <= 90)
            cout<<map[input]<<"\n";
        
        else
            cout<<pocketmon[stoi(input)]<<"\n";
    }
}

