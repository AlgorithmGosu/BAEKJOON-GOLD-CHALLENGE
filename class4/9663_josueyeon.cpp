// backtracking

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int result;
int N;
int d[16];

bool is_valid(int row)
{

    for(int i = 1;i < row;i++)
    {
        if (d[i] == d[row] || (abs(i - row) == abs(d[i] - d[row])))
            return false;
    }
    return true;
}

void queens(int n)
{
    if (n > N)
    {
        result++;
        return;
    }
    
    for(int i = 1;i <= N;i++)
    {
        d[n] = i;
        if (is_valid(n))
            queens(n + 1);
    }
}
int main()
{
    cin>>N;
    
    result = 0;
    queens(1);
    cout<<result<<"\n";
    
    return 0;
}

