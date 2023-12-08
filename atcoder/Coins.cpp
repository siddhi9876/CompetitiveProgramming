#include <bits/stdc++.h>
#define ll long long int
//cout<<std::fixed<<std::setprecision(13)<<ans<<endl;
using namespace std;



int main()
{
    int n;
    cin >> n;

    double p[n+1];

    for(int i=1; i<= n;i++) cin >> p[i];

    double dp[n+1][n+1];
    memset(dp,0,sizeof(dp));

    dp[0][0] = 1.0;
    for(int i = 1; i <= n ; i++)
    {
        for(int j=0; j<=i; j++) 
        {
            if(j==0) dp[i][j] = dp[i-1][j] * (1.0 - p[i]);
            else dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1.0 - p[i]);
        }
    }

    double ans = 0;
    for(int i = (n/2)+1 ; i<=n;i++)
    {
        ans = ans + dp[n][i];
    }

    cout<<std::fixed<<std::setprecision(13)<<ans<<endl;
}
