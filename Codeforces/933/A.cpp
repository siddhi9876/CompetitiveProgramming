#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin>> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        vector<ll>a(n, 0);
        vector<ll>b(m,0);

        for(int i = 0; i < n; i++) cin >>a[i];
        for(int j=0; j<m;j++) cin >> b[j];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll slow = 0;
        ll fast = m-1;

        ll ans = 0;

        for(int i =0; i < n;i++) {
            while(fast >= 0 && (a[i] + b[fast] > k)) fast--;

            if(fast >= 0) ans += (fast+1);
        }

        cout<<ans<<endl;
    }
}