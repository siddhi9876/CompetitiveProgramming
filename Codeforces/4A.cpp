#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(0);

    ll n;
    cin >> n;
    ll x = n-2;
    if(x > 0 && x%2 == 0 ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}