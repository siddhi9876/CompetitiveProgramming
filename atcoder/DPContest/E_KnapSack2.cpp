#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    
    ll N, W;

    cin >> N >> W;

    vector<ll>w;
    vector<ll>v;

    ll totalV = 0;
    for(ll i=0; i< N; i++) {
        ll x, y;
        cin >> x >> y;
        w.push_back(x);
        v.push_back(y);
        totalV += y;
    }

    vector<ll>dp(totalV+1, W+1);
    dp[0] = 0;

    for(ll i = 0; i < N; i++) {
        for(ll j = totalV; j >= v[i]; j--) {
            if(dp[j-v[i]] != W+1); {
                dp[j] = min(dp[j], w[i] + dp[j-v[i]]);
            }
        }
    }

    ll ans = 0;
    for(int i = totalV; i >=0; i--) {
        if(dp[i] != (-1) && dp[i] <= W) {
            ans = i;
            break;
        }
    }

    cout << ans <<endl;
}