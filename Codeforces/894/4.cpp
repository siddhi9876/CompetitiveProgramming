#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n;

        cin >> n;

        ll low = 1, high = 2e9;
        ll ans = low;
        while(low <= high) {
            ll mid = low + (high - low) /2;
            ll comb = mid * (mid - 1) / 2;

            if(comb <=n)  { ans = mid ; low = mid + 1;}
            else high = mid -1 ;
        }

        ll val = ans * (ans - 1) / 2;

        ans = ans + (n - val);
        cout <<ans <<endl;
    }
}