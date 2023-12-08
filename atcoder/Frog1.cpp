#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n;
     cin >> n;

     ll a[n];

     for(ll i=0; i<n; i++) cin >>a[i];

     ll ans[n];
    
    ans [0] = 0; ans[1] = abs(a[0] - a[1]);

    for(ll i=2; i <n ; i++)
    {
        ans[i] = min(ans[i-1] + abs(a[i] - a[i-1]), ans[i-2] + abs(a[i] - a[i-2]));
    }

    cout<<ans[n-1]<<endl;
}