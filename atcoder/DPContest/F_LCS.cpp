#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int dp[3005][3005];
int main()
{


    string s, t;

    cin >> s >> t;

    s = '$' + s;
    t = '#' + t;

    for(int i = 0; i < t.length(); i++) dp[i][0] = 0;
    for(int j =0; j< s.length(); j++) dp[0][j] = 0;

    for(int i =1; i< t.length(); i++) {
        for(int j = 1; j < s.length(); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
             if(t[i] == s[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }


    int i = t.length() -1, j = s.length()-1;
    string ans = "";
    int curr = dp[t.length() -1][s.length()-1];
    while(i && j) {
        if(dp[i-1][j] == curr) i--;
        else if(dp[i][j-1] == curr) j--;
        else {
            ans = s[j] + ans;
            i--; j--;
            curr--;
        }
    }

    cout <<ans<<endl;
}