#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;

        cin >> n;

        unordered_set<ll> mp;

        vector<ll> vec;

        for(ll i=0; i<n;i++)
        {
            ll x;
            cin >> x;
            vec.push_back(x);
        }

        int index = vec.size() - 1;

        for(; index>=0; index--)
        {
            if(mp.find(vec[index]) != mp.end())
            break;

            mp.insert(vec[index]);
        }

        cout<<index+1 << endl;
    }
}