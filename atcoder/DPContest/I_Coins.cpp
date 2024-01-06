#include<bits/stdc++.h>
#define ll long long int
using namespace std;

double dp[3000][3000];

int main() {
    ios_base :: sync_with_stdio(0);

    ll n;
    vector<double>p;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        double pi;
        cin>> pi;
        p.push_back(pi);
    }

    dp[0][0] = (1 - p[0]);
    dp[0][1] = p[0];

    for(int i = 1; i<n; i++) {
        dp[i][i+1] = p[i] * dp[i-1][i];
        for(int j = i; j >=0; j--) {
            dp[i][j] = (1 - p[i]) * dp[i-1][j] + (j > 0 ?  p[i] * dp[i-1][j-1] : 0);
        }
    }
    
    double ans = 0;
    for(int i = n; i >= (n/2)+1; i--) {
        ans += dp[n-1][i];
    }

    cout <<setprecision(10)<<ans<<endl;
}