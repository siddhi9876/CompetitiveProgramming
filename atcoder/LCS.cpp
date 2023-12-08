#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int dp[3005][3005] = {{0}};
int main()
{

    string s1, s2;
     cin >> s1 >> s2;

    for(int i = 1; i <= s1.length(); i++)
    {
        for(int j=1; j<=s2.length(); j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }

    int row = s1.length();
    int col = s2.length();
    string ans = "";

    while(row && col)
    {
        if(dp[row][col] == dp[row-1][col]) row--;
        else if(dp[row][col] == dp[row][col-1]) col--;
        else
        {
            if(s1[row-1] == s2[col-1]) ans = s1[row-1] + ans;

            row--;
            col--;
        }
    }

    cout<<ans<<endl;
}