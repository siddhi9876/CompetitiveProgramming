#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    
    ll N, W;

    cin >> N >> W;

    vector<ll>w;
    vector<ll>v;

    for(ll i=0; i< N; i++) {
        ll x, y;
        cin >> x >> y;
        w.push_back(x);
        v.push_back(y);
    }

    vector<ll>dp(W+1, 0);

    for(int i = 0; i < N; i++) {
        for(int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
        }
    }

    cout << dp[W] <<endl;
}