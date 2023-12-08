#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        vector <ll>a(n,0);
        vector <ll> b(n,0);
        vector < ll> ans;

        for(ll i=0; i<n;i++) cin>> a[i];
        for(ll i=0; i<n;i++) cin>> b[i];

        ll maxVal = a[0] - b[0];
        for(ll i = 1; i < n; i++) {
            maxVal = max(maxVal, a[i] - b[i]);
        }

        for(ll i=0; i<n;i++) {
            if((a[i] - b[i]) == maxVal) ans.push_back(i+1);
        } 

        cout <<ans.size()<<endl;
        for(ll i = 0; i< ans.size(); i++) cout <<ans[i]<<" ";
        cout<<endl;
    }
}