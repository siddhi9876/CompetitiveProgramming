#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n = 100005;

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

vector<ll>dividers[100006];
void calculateDivider() {

is_prime[0] = is_prime[1] = false;

for(int i = 2; i < n; i++ ) {

    if(is_prime[i]) {

        dividers[i].push_back(i);
        for(int j = i*2; j < n; j+=i ) {
            is_prime[j] = false;
            dividers[j].push_back(i);
        }
    }
}

}

map<ll, int> multiples;
int main(){
    ios_base :: sync_with_stdio(0);
    calculateDivider();

    bool isActivated[100005]{false};

    ll m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        ll k;
        char c;

        cin >> c >> k;

        if(c== '+') {
            if(isActivated[k]) {
                cout<<"Already on"<<endl;
            }
            else {
                int conflict = 0;
                for(ll j : dividers[k]) {
                        if(multiples[j] != 0) {
                            conflict = multiples[j];
                            break;
                        }
                }

                if(conflict == 0) {
                    cout <<"Success"<< endl;
                    for(ll j : dividers[k]) {
                        multiples[j] = k;
                    }
                    isActivated[k] = true;
                }
                else {
                    cout <<"Conflict with "<<conflict<< endl;
                }
            }
        }
        else {
            if(isActivated[k] == false) cout <<"Already off" <<endl;
            else {
                cout<<"Success"<<endl;
                for(ll j : dividers[k]) {
                    multiples[j] = 0;
                }
                isActivated[k] = false;
            }
        }
    }
}