#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);

    ll n , k;
    cin >>n >> k;

    vector<ll>height(n+1, 0);
    vector<ll>dp(n+1);

    for(int i = 1; i <= n; i++) cin >> height[i];

    dp[1] = 0;

    for(int i = 2; i<=n; i++) {
        dp[i] = LLONG_MAX;
        for(int j = 1; j <=k && i - j >=1 ; j++) {
            dp[i] = min(dp[i] , dp[i-j] + abs(height[i] - height[i-j]));
        }
    }
    
    cout <<dp[n]<<endl;
}