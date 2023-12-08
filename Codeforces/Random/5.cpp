#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

map<pair<ll,ll>, ll > mp;

ll n;

ll calculate (ll mid) {
    ll  middle = 1;

        ll r = mid - 1;
        while ( r > 0) {
            if(n%r == 0) middle++;
            else break;
            r--;
        }

        ll lt = mid + 1;
        while ( lt <=n) {
            if(n% lt == 0) middle++;
            else break;
            lt++;
        }
    return middle;
}

ll  greatestRange(ll low, ll high) {

    if(mp.find(make_pair(low, high)) != mp.end()) return mp[make_pair(low, high)];

    //cout << low<< " "<< high<< endl;

    if(low <= 0 || high <=0 || low > n ||  high > n || low > high ) return 0;

    if(high == low) {
        if(n % low == 0) return calculate(low);
        return 0;
    }

    ll mid = (low + ((high - low) / 2));

    ll left  = greatestRange(low, mid -1);
    ll right = greatestRange(mid+1, high);

    ll middle = 0;

    if(n % mid == 0) {
       middle = calculate(mid);
    }

    mp[make_pair(low, high)] = max(middle, max(left, right));
    return mp[make_pair(low, high)];
}

std::unordered_set<ll>oddDivisors;

void divisors(ll num) {
    ll square_root = min ((ll)1000000, (ll) sqrt(num) + 1);
    for (ll i = 1; i < square_root; i+=2) { 
        if (num % i == 0 && i&1) {
            oddDivisors.insert(i);
        }
        if (num % (num/i) == 0&& (num/i) & 1) {
            oddDivisors.insert((num/i));
        }
    }
}

int main()
 {
    int t;
    cin  >> t;

    while (t--) {
        
        cin >>n;

        ll ans  = 1;

        while(n % ans == 0)  ans++;

        cout << ans - 1<< endl;
    }
 }