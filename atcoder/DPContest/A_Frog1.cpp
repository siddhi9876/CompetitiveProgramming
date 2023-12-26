#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll>height(n+1);

    for(ll i = 1; i<= n; i++) {
        cin >> height[i];
    }

    vector<ll>dp(n+1, -1);

    dp[0] = 0, dp[1] = 0, dp[2] = abs(height[2] - height[1]);

    for(ll i = 3; i<=n; i++) {
        dp[i] = min(dp[i-1] + abs(height[i] - height[i-1]), dp[i-2] + abs(height[i]- height[i-2]));
    }
    
    cout << dp[n] <<endl;
}