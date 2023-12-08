#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    ll n;
    cin >> n;

    ll a=0, b=0, c= 0;

    for(int i=0;i<n;i++)
    {
        ll ai, bi, ci;

        cin >> ai >> bi >> ci;

        ll atemp, btemp, ctemp;

        atemp = ai + max(b, c);
        btemp = bi + max(c,a);
        ctemp = ci + max(a, b);

        a = atemp; b = btemp; c = ctemp;
       // cout<<a<<" "<<b<< " "<<c<<endl;
    }

    ll ans = max(a, max(b,c));
    cout<<ans<<endl;
}
