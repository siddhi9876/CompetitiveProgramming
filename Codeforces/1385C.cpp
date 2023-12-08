#include<bits/stdc++.h>
#define ll long long int
using namespace std;

//Trnasforms to lowercase : transform(s1.begin(), s1.end(),s1.begin(), ::tolower);

int main()
{
    ios_base :: sync_with_stdio(0);

    ll t;
    cin >> t;
     
    while(t--)
    {
        ll n;
        cin >> n;
        ll a[n];

        for(int i =0; i< n;i++) cin >>a[i];

        ll high = n-1;

        for(int i = n-2; i >=0; i--)
        {
            if(a[i] >= a[i+1]) high = i;
            else break;
        }

        ll low = 0;
        for(int i=1; i< high;i++) {
            if(a[i] >= a[i-1]) continue;
            else low = i;
        }

        cout<<low<<endl;
    }
 
}