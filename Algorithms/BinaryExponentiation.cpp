//If  is mod a prime number we can speed up a bit this algorithm by calculating x^(n % (mod-1))  instead of x^n.

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll binPowRec(ll a, ll b)
{
    if(b==0) return 1;

    ll res = binPowRec(a, b/2);

    if(b%2) return res*res*a;

    else return res*res;
}

ll binPow(ll a, ll b, ll m = 1000000009)
{
     a = a % m;

    ll res = 1;

    while (b > 0)
    {
        if(b & 1) res = (res * a) % m;
         
         a = (a* a) % m;

         b >>= 1;
    }

    return res;
}
int main()
{
    cout<<binPow(2, 9) << endl;
    cout<<pow(2,9)<< endl;

}