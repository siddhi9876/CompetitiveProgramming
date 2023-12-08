#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n = 100000000;

int main()
{
    ll t;
    cin>> t;
    while(t--) {
        ll n;
        cin >> n;

        ll sum = 0;

        for(int i = 0; i < n; i++) {
            ll k;
            cin >> k;

            if( k & 1) sum += k;
        }

        if(sum & 1) cout << "NO" <<endl;
        else cout <<"YES"<<endl;
    }
}