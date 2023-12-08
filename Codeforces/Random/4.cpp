#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
 {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll temp = 0;
        for(int i= 0 ; i< n;i++) {
            ll k;

            cin >> k;

            if(k == i+1) temp++;
        }

        if(temp & 1) cout << (temp/2) + 1 << endl;
        else cout <<(temp/2) << endl;
    }
 }