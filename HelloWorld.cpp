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
ll binpow(ll a, ll b) {
    if(b == 0) return 1;
    ll res = binpow(a, b/2);
    if(b % 2) return res* res * a;
    else return res * res;
}

ll binpow2(ll a, ll b) {

    ll res = 1;
    while (b > 0) {
        if(b & 1) res = res * a;

        a = a * a;
        b = b >> 1;
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    sieve(n);

    for(int i = 1; i <= 50; i++) {
        cout << i<< "  " <<is_prime[i] << endl;
    }

    cout << "Hello World" << endl;
}