// (A * B mod C) = (A mod C) * (A mod C) mod C

#include <iostream>
using namespace std;

int Pow(int a, int b, int c)
{
    if (b == 0)
        return 1;
    long long temp = Pow(a, b / 2, c);
    temp = temp * temp % c;
    if (b % 2 == 0)
        return temp % c;
    else
        return temp * a % c;
    
}
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    
    cout<<Pow(a, b, c);
    
    return 0;
}

