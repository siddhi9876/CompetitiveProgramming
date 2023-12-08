#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        if(s.length() <= 10) cout << s<<endl;
        else 
        {
            string ans = "";
            ans = s[0] + to_string(s.length() - 2)+s[s.length() - 1];
            cout<< ans << endl;
        }
    }
}