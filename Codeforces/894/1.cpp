#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;

    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int>vec[n];

        vector<string>ans(m, "");
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for(int j = 0; j< m ;j++) {
                ans[j] = ans[j] + s[j];
            }
        }

        int found = 0;

        for(int i = 0; i < m; i++) {
            if(found == 0) {  
                size_t temp = ans[i].find("v"); 
                if(temp!= string::npos) { found = 1; continue;}
            }
            if(found == 1) {
                size_t temp = ans[i].find("i");
                if(temp != string::npos) { found = 2; continue;}
            }
            if(found == 2) {
                size_t temp = ans[i].find("k");
                if(temp != string:: npos) { found = 3; continue; }
            }
            if(found == 3) {
                size_t temp = ans[i].find("a");
                if(temp != string::npos) {found = 4; continue;}
            }
        }

        if(found == 4) cout <<"YES"<<endl;
        else cout << "NO"<<endl;
    }
}
