#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, m, x;

        cin >> n >> m >> x;

        vector<ll>start;
        start.push_back(x-1);
        while(m--) {
            unordered_set<ll>fin;

            ll hop;
            char c;
            cin >> hop >> c;

            for(int i =0; i < start.size(); i++) {
                hop = hop % n;
                int st = (start[i] + hop)% n;
                int ed = start[i] - hop;
                if(ed < 0) ed = ed + n;
                //cout<<start[i]<< " "<< st<< " "<<ed<<"........."<<endl;
                if( c == '?') {
                    fin.insert(st);
                    fin.insert(ed);
                   // cout<<st<<" "<<ed<<endl;
                }
                else if( c== '0') {
                    fin.insert(st);
                    //cout << st <<endl;
                }
                else {
                    fin.insert(ed);
                    //cout << ed <<endl;
                }
            }
            start.clear();
            for(auto i : fin) {
                start.push_back(i);
                //cout <<i<<" ";
            }
            //cout <<"**********************"<<endl;
        }

        cout << start.size()<<endl;
        sort(start.begin(), start.end());

        for(int i =0; i < start.size(); i++) cout <<(start[i] + 1)<<" ";
        cout <<endl;
    }
}