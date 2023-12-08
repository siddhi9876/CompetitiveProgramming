#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int dp[1005][1005] ={{0}};
int temp[1005][1005] ={{0}};
int main()
{
    ll n, m;
    cin >>n >> m;

    for(int i =1; i <= n;i++)
    {
        for(int j=1; j<=m; j++){
            char c;
            cin >> c;
            if(c == '#') temp[i][j] = 1;
        }
    }

    for(int i = 1; i <=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(temp[i][j] == 1) continue;

            if( i== 1 && j==1) dp[i][j] = 1;
            else if(i==1) dp[i][j] = dp[i][j-1];
            else if (j==1) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }

    cout<< dp[n][m]<<endl;
}