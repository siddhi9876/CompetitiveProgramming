#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n = 100000000;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        string s;

        cin >> s;

        vector<int> a;
        a.push_back(0);
        for(int i = 0; i < s.length(); i++) a.push_back(s[i] - '0');

        int marker = s.length() + 1;
        for(int i = a.size()-1; i > 0; i--) {
            if(a[i] >= 5)  {
                a[i-1]++; 
                marker = i;
            }
        }

        int index = 0;
        if(a[0] == 0) index++;
        
        for( int i = index; i< marker; i++) cout <<a[i];
        for(int i = marker; i < a.size(); i++ ) cout<<"0";
        cout<<endl;
    }
}