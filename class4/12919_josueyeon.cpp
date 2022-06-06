// Brute Force

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int result;
void makeString(string A, string B)
{
    if (A == B)
    {
        result = 1;
        return;
    }
    
    // 문자열을 바꿀 수 없는 경우
    if (A.length() >= B.length())
        return;
    
    else
    {
        string temp = B;
        if (temp[temp.size() - 1] == 'A')
        {
            temp.pop_back();
            makeString(A, temp);
        }

        temp = B;
        reverse(temp.begin(), temp.end());
        if (temp[temp.size() - 1] == 'B')
        {
            temp.pop_back();
            makeString(A, temp);
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    string A, B;
    cin>>A>>B;
    
    makeString(A, B);
    
    cout<<result<<"\n";
    return 0;
    
}

