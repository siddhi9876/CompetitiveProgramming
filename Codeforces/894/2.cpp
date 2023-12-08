#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin>> t;

    while(t--) {
        int m;
        cin >> m;

        vector<ll>b;
        for(ll i=0; i < m; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }

        vector<int> ans;
        ans.push_back(b[0]);

        for(ll i = 1; i < b.size(); i++) {
            if(b[i] >= b[i-1]) ans.push_back(b[i]);
            else {
                ans.push_back(b[i]);
                ans.push_back(b[i]);
            }
        }

        cout << ans.size()<<endl;
        for(ll i=0; i < ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}