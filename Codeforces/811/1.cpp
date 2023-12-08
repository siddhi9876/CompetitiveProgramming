#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<bool> is_prime(100000, true);
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

vector<int>CountPrime(3005, 0);
void modified_sieve(ll n) {

is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= n; i++) {

        if(is_prime[i]) {

            for(int j = i; j <=n ; j+=i) {
                is_prime[j] = false;
                CountPrime[j] = CountPrime[j] + 1;
            }
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(0);
    
    ll n;
    cin >> n;
    modified_sieve(3002);

    int ans = 0;
    for(int i = 2; i<=n; i++) {

        if(CountPrime[i] == 2) ans++;
    }
    cout<< ans <<endl;
}