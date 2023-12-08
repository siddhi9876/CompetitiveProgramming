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
    sieve(2000);

    int n, k;
    cin >> n >> k;

    int cnt = 0;

    for(int i = 3; i <= n; i++) {
        
        if(is_prime[i] == false) continue;
        int flag = 0, j = 1;
        for(int j = 1; j <= i; j++) {
            if(is_prime[j]) {
                int k = j+1;
                while(is_prime[k] == false && k<=i) k++;

                if(is_prime[k] && (j+k == (i-1)))  { cnt++; flag =1; }
            }

            if(flag == 1) break;
        }
    }

    if(cnt >= k) cout <<"YES"<<endl;
    else cout <<"NO"<< endl;
}