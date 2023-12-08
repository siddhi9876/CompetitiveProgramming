#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(0);

    ll n, m, a;

    cin >> n >> m >> a;

    ll rows = ( n/ a);
    if(n% a) rows++;

    ll cols = (m/ a);
    if(m%a) cols++;
 
    ll ans = rows * cols;

    cout << ans << endl;
}