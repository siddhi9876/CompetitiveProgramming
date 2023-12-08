#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    ll N, W;
    cin >> N >> W;

    ll w[N+1], v[N+1];

    for(ll i=1; i<= N; i++) cin >> w[i] >> v[i];

    ll dp[N+1][W+1];
    for (ll i=0; i<=W; i++) dp[0][i] = 0;

    for(ll i=1; i<=N; i++)
    {
        for(ll j = 0; j<=W; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j-w[i] >=0)
            {
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);
            }

           // cout<<i<< " "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout <<dp[N][W]<<endl;
}