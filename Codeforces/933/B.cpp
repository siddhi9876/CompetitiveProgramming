#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll>a(n, 0);

        for(int i = 0; i < n; i++) cin >> a[i];

        bool ans = true;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) continue;

            if(i >= n-2 || a[i] < 0) {
                ans = false;
                break;
            }

            a[i+1]  = a[i+1] - (2* a[i]);
            a[i+2]  = a[i+2] - a[i];
        }

        cout << (ans ? "YES" : "NO") <<endl;
    }
}