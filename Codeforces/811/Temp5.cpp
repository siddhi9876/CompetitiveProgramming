#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPowerOfTwo (ll x)
{
    if(x == 1 || x == 2 || x == 4 || x == 8) return true;
    return false;
}

vector<ll> findVectorEven(ll val)
{
    vector<ll> vec(10);
    vec[1] = {2, 4, 8};
    vec[2] = {2, 4, 8};
    vec[3] = {6};
    vec[4] = {2, 4, 8};
    vec[6] = {6};
    vec[7] = {6};
    vec[8] = {2, 4, 8};
    vec[9] = {6};
    return vec[val];
}

vector<ll> findVectorOdd(ll val)
{
    vector<ll> vec(10);
    vec[1] = {6};
    vec[2] = {6};
    vec[3] = {2, 4, 8};
    vec[4] = {6};
    vec[6] = {2, 4, 8};
    vec[7] = {2, 4, 8};
    vec[8] = {6};
    vec[9] = {2, 4, 8};
    return vec[val];
}
bool isPossible(ll small, ll large)
{
    if(small == large) return true;
    ll small_10 = small / 10;
    ll large_10 = large /10;

    ll diff = large_10 - small_10;

    if(small % 5 == 0)
    {
        if(small == large) return true;
        if(small + small%10 == large) return true;
        return false;
    }
    
    return ispoweroftwo(small%10) == ispoweroftwo(large%10);
}

int main()
{
     ll t;
     cin >> t;
      while(t--)
      {
          ll n;
          cin >. n;
          vector<ll> vec;

          for(int i =0; i< n;i++)
        {
            ll x;
            vec.push_back(x);
        }

        sort(vec.begin(), vec.end());
        ll i =n-1;
        for( i=0; i < n-1; i++ )
        {
            if(isPossible(vec[i], vec[i+1])== false) break;
        }
        if(i != n-1) cout << "NO"<<endl;
        else cout<< "YES"<<endl;
      }
}
