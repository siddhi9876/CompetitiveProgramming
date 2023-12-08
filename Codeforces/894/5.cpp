#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    int t;

    cin >> t;

    while(t--) {
        ll n, m, d;
        cin >> n >> m>> d;

        ll ans = 0;
        ll fin = 0;
        multiset<ll>s;
        for(int i =1; i<=n; i++) {

            ll x;
            cin >> x;
            if(x > 0) {
                ans += x;
                s.insert(x);
            }

            if(s.size() > m) {
                ans -= *s.begin();
                s.erase(s.begin());
            }

            fin = max(fin, ans - d * i);
        }

        cout << fin << endl;
    }
}