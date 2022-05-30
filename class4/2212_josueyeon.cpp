// Greedy
// 집중국을 어디에 두는 지가 아니라 인접한 노드의 거리차이가 얼마나 나는지 계산해서 정렬한 다음에 거리 차이를 N-K 만큼 더하면 됨

// 비슷한 문제: 13164 유치원

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N, K;
    cin>>N>>K;
    
    vector<int> v;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    vector<int> dist;
    for(int i = 0;i < N - 1;i++)
        dist.push_back(v[i + 1] - v[i]);
    
    sort(dist.begin(), dist.end());
    
    int result = 0;
    for(int i = 0;i < N - K;i++)
        result += dist[i];
    
    cout<<result<<"\n";

    return 0;
}

