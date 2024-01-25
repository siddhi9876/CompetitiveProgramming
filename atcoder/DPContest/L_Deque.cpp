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

ll dpX[3005][3005];
ll dpY[3005][3005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    memset(dpX,(-1),sizeof(dpX));
    memset(dpY,(-1),sizeof(dpY));

    ll n;
    cin >> n;

    vector<ll>vec(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
        dpX[i][i] = vec[i];
        dpY[i][i] = -vec[i];
    }

    for(int k = 1; k < n; k++) {
        for(int i = 0; i < n; i++) {
            int j = i+k;
            if(j < n) {
                dpX[i][j] = max(vec[i] + dpY[i+1][j], vec[j] + dpY[i][j-1] );
                dpY[i][j] = min(-vec[i] + dpX[i+1][j], -vec[j] + dpX[i][j-1]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j <n ; j++) {
            dpX[i][j] = max(vec[i] + dpY[i+1][j], vec[j] + dpY[i][j-1] );
            dpY[i][j] = min(-vec[i] + dpX[i+1][j], -vec[j] + dpX[i][j-1]);
        }
    }

    cout <<dpX[0][n-1] << endl;
}