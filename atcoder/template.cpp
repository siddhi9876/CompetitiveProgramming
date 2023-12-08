#include<bits/stdc++.h>
#define ll long long int
using namespace std;

//cout<<std::fixed<<std::setprecision(13)<<ans<<endl;

//Trnasforms to lowercase : transform(s1.begin(), s1.end(),s1.begin(), ::tolower);

ll mod (ll n)
{
    if(n < 0) return (n* (-1));
    return n;
}

vector<ll>dp(100001, -1);

ll calculate(ll index, vector<ll>height)
{
    if(index < 0) return INT_MAX;
    if(dp[index] >=0 ) return dp[index];

    dp[index] = min(calculate(index-2, height) + mod(height[index] - height[index -2]),
    calculate(index-1, height) + mod(height[index] - height[index-1]));

    return dp[index];
}
int main()
{
    ios_base :: sync_with_stdio(0);

    ll n;
     cin >> n;

     vector<ll> height(n,0);
     for(ll i=0; i<n;i++) cin >> height[i];
     dp[0] = 0;
     if(n >=2) dp[1] = mod(height[1] - height[0]);
     cout<<calculate(n-1, height) <<endl;
}