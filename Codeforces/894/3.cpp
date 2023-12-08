#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

     int t;
     cin >> t;
     while(t--) {

        ll n;
        cin >> n;

        vector<ll> a;
        for(int i = 0; i< n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        if(a[0] > n) {
            cout <<"NO"<<endl;
        }
        else {
            vector<ll>b(a[0]+1, 0);
            for(ll i = a.size() - 1; i >=0; i--) {
                b[a[i]] = max(b[a[i]], i+1);
            }

            ll x = 0;
            for(ll i = b.size()-1; i>=1; i--) {
                b[i] = max(b[i], x);
                x = b[i];
            }
            
            int isSame = true;

            if(a.size() != b.size() - 1) isSame= false;
            else {
                for(ll i = 0; i< a.size(); i++) {
                    if(a[i] != b[i+1]) isSame = false;
                }
            }
            if(isSame) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
     }
}