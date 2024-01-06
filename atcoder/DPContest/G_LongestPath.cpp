#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[100005];
vector<ll>adj[100005];

ll calculate(ll n) {
    if(dp[n] != 0) return dp[n];

    for(ll i = 0; i < adj[n].size(); i++ ) {
        dp[n] = max(dp[n], calculate(adj[n][i]) + 1);
    }
    return dp[n];
}
int main() {
    ios_base :: sync_with_stdio(0);
    memset(dp, 0, sizeof(dp));

    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    ll ans = 0;
    for(ll i = 1; i<=n; i++) {
        if(dp[i] == 0) calculate(i);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}