#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(0);
    ll n;
    cin>>n;
    
    ll ans = 0;
    while(n--)
    {
        int count = 0;
        int x;

        cin >> x;
        if(x) count++;

        cin >> x;
        if(x) count++;

        cin >> x;
        if(x) count++;

        if(count >= 2) ans++;
    }

    cout << ans << endl;
 
}