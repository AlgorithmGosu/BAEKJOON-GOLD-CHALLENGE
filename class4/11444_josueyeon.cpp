#include <vector>
#include <iostream>
using namespace std;

vector<vector<unsigned long long>> operator*(vector<vector<unsigned long long>> &a, vector<vector<unsigned long long>> &b)
{
    vector<vector<unsigned long long>> temp(2, vector<unsigned long long>(2));
    
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            for(int k = 0;k < 2;k++)
            {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] = temp[i][j] % 1000000007;
        }
    }
    return temp;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    vector<vector<unsigned long long>> A = {{1, 1}, {1, 0}};
    vector<vector<unsigned long long>> E = {{1, 0}, {0, 1}};
    
    unsigned long long n;
    cin>>n;
    
    while (n > 0)
    {
        if (n % 2 == 1)
            E = E * A;
        A = A * A;
        n = n / 2;
    }
    
    cout<<E[0][1]<<"\n";
    
    return 0;
}

