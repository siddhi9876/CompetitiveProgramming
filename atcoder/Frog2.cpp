#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n, k;

    cin >> n >> k;

    ll a[n];
    for(ll i=0; i<n;i++) cin>>a[i];

    ll ans[n];
    ans[0] = 0;
    for(int i =1; i<n;i++)
    {
        ans[i] = INT_MAX;
        int j = 1;
        while(j <=k && i-j >= 0)
        {
            ans[i] = min(ans[i], abs(a[i] - a[i-j]) + ans[i-j]);
            j++;
        }
    }
    cout<<ans[n-1]<<endl;
}