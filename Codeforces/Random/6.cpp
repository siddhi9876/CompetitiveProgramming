#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t;

    cin >> t;
    while(t--) {
        int n ;
        
        cin >> n;

        vector<int>a;
        for(int i =0 ; i<n ; i++) {
            int k;
            cin >> k;
            a.push_back(k);
        }

        vector<int> largest(n,0);
        largest[0] = 0;
        for(int i = 1; i < n; i++) {

            largest[i] = a[largest[i-1]] > a[i] ? largest[i-1] : i;
        }

        ll cnt = 0;
        vector<pair<int, int>>ans;
        for(int i = n-1; i >= 0; i--) {
            if(largest[i] != i) {

                ll temp = a[i];
                while(temp <= largest[i])
                {
                    temp = temp + a[largest[i]];
                    ans.push_back(make_pair(i+1, largest[i]+1));
                }
            }
        }

        cout << ans.size()<<endl;

        for(int i =0; i< ans.size(); i++) {
            cout << ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
}