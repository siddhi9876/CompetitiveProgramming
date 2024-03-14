#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

//getline(cin, s)  - Reads line containing spaces
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//while (cin >> x) {code}
//__int128_t with a value range of  −10 ^38 ...10 ^ 38

typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    ll n, k;
    cin >> n >> k;

    vector<int>vec(n+1, 0);

    sort(vec.begin(), vec.end());

    for(int i = 0; i < n; i++) cin >> vec[i];

    ll prev[k+1] = {0};
    ll curr[k+1] = {0};
    for(int i = 0; i <=vec[0]; i++) prev[i] = 1;

    for(int i = 1; i <=k; i++) {
        prev[i] = (prev[i] + prev[i-1]) % mod;
    }

    for(int i = 1; i < n; i++) {
     
    }

}