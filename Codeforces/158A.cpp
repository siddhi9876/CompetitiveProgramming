#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;

    ll a[n];

    for(int i = 0; i <n ;i++) cin >> a[i];

    ll score = a[k-1];

    ll ans  = k;

    if(score <= 0)
    {
        for(int i = k-1 ; i>=0; i--) if(a[i] <= 0) ans--;
    }
    else 
    {
        for(int i = k; i < n; i++) if(a[i] == score) ans++;
    }

    cout<<ans<<endl;
}