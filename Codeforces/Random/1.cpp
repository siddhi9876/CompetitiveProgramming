#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n = 100000000;

vector<bool> is_prime(n+1, true);
void sieve(ll n) {

is_prime[0] = is_prime[1] = false;

for(int i = 2; i*i <=n; i++ ) {

    if(is_prime[i]) {

        for(int j = i*i; j <= n; j+=i ) {
            is_prime[j] = false;
        }
    }
}

}

int main(){
    ios_base :: sync_with_stdio(0);

    ll n;
    cin >> n;

    sieve(n+1);

    if(n <= 2) cout << 1 << endl;
    else cout << 2 << endl;

    for(ll i= 2; i<= n+1; i++) {
        if(is_prime[i]) cout<<1<<" ";
        else cout << 2 << " ";
    }
}