#include <bits/stdc++.h>
using namespace std;

double findP(double x, long long n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }

    // double answer = x*findP(x, n-1);

    double answer = findP(x, n / 2);
    answer = answer * answer;

    if (n % 2 == 1)
        answer = answer * x;
    return answer;
}
double myPow(double x, int n)
{
    if (n >= 0)
        return findP(x, n);
    return (double)1 / findP(x, abs(n));
}

int main()
{
    double x = 2.00000;
    double n = -2;
    cout<<myPow(x,n);
}