#include<bits/stdc++.h>
#define ll long long int
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

ll dp[100005] = {0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    ll n, k;

    cin >> n >> k;

    ll a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }

    for(ll i = 1; i <= k ; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j] <= i  && dp[i - a[j]] == 0) dp[i] = 1;
        }
    }

    string ans = (dp[k] == 1) ? "First" : "Second";
    cout << ans << endl;
}