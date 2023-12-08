#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll N, W;
    cin >> N >> W;

    ll dp[2][100001];
    ll w[N+1], v[N+1];
    for(int i=1; i<=N;i++)
    {
        cin >> w[i] >> v[i];
    }

    for(int i = 0; i<=100000; i++) dp[0][i] = 1000000009;

    ll flag = 0;
    for(int i =1; i<=N; i++)
    {
        for(int j = 0; j<=100000; j++)
        {
            dp[flag^1][j] = dp[flag][j];
            if(j - v[i] == 0)
            {
                dp[flag^1][j] = min(dp[flag][j], w[i]);
            }
            else if (j-v[i] > 0  )
            {
                dp[flag^1][j] = min(dp[flag][j], dp[flag][j-v[i]] + w[i]);
            }
            
        }
        flag = flag ^1;
    }

    ll j = 100000, ans = INT_MAX;
    while(dp[flag][j] > W && j>=0)
    {
        j--;
    }
    cout<<j<<endl;
}