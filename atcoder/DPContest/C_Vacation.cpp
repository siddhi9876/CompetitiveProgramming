#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll>happiness[n+1];

    for(ll i=1; i <=n; i++) {
        ll a, b, c;
        cin >>a >>b >> c;
        happiness[i].push_back(a);
        happiness[i].push_back(b);
        happiness[i].push_back(c);
    }

    ll a = happiness[1][0], b = happiness[1][1], c = happiness[1][2];

    for(int i = 2; i<=n; i++) {
        ll a1 = happiness[i][0] + max(b, c);
        ll b1 = happiness[i][1] + max(a, c);
        ll c1 = happiness[i][2] + max(a, b);

        a = a1; b = b1; c = c1;
    }

    ll ans = max(a, max(b,c));

    cout<<ans<<endl;
    
}