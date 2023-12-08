#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        vector<ll> a;

        int cnt = 0;
        for(int i =0; i <=3 ; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
            if(x == 1) cnt++;
        } 

        if(cnt == 0) cout <<"0"<< endl;
        else if (cnt <= 3) cout<< "1" <<endl;
        else cout <<"2"<< endl;
    }
}