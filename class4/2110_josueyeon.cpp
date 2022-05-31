// Binary Search

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N, C;
    cin>>N>>C;
    
    vector<int> pos;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        pos.push_back(temp);
    }
    
    sort(pos.begin(), pos.end());
    
    int start = 1;  // 최소 거리 차이
    int end = pos[pos.size() - 1] - pos[0]; // 최대 거리 차이
    
    // 가능한 거리 차이에 대해서 이분 탐색 진행하며 공유기 설치 가능한지 확인
    // C개 보다 작으면 간격 줄이기, C개보다 많으면 간격 늘리기
    
    int result = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        
        int count = 1;
        int temp = pos[0];
        for(int i = 1;i < pos.size();i++)
        {
            if (pos[i] - temp >= mid)
            {
                count++;
                temp = pos[i];
            }
        }
        if (count >= C)
        {
            start = mid + 1;
            result = mid;
        }
        else
            end = mid - 1;
        
    }
    cout<<result<<"\n";
    return 0;
}

