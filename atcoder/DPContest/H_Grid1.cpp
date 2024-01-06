#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007;
using namespace std;

ll dp[1005][1005];

int main() {
    ios_base :: sync_with_stdio(0);
    vector<string>s;

    ll n, m;
    cin >> n >> m;

    for(int i =0; i<n;i++){
        string temp;
        cin>> temp;
        s.push_back(temp);
    }

    ll ans = 0;
    for(ll i = 0; i <n;i++) {
        for(ll j = 0; j < m; j++) {
            if(i==0 && j==0) dp[i][j] = 1;
            else if( i== 0) dp[i][j] = s[i][j] == '#' ? 0 : dp[i][j-1];
            else if (j == 0) dp[i][j] = s[i][j] == '#' ? 0 : dp[i-1][j];
            else dp[i][j] = s[i][j] == '#' ? 0 : (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[n-1][m-1] <<endl;
}