#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int countSubstring(string a) {

    if(a.length() < 3) return 0;
    int ans = 0, i= 0;
    while(i <=a.length()-3) {
        if( i<= a.length() - 5 && (a[i] == 'm' && a[i+1] == 'a' && a[i+2] == 'p' && a[i+3] == 'i' && a[i+4] == 'e')) {
            ans++;
            i = i + 5;
        }
        else if(a[i] == 'm' && a[i+1] == 'a' && a[i+2] == 'p') {
            ans++;
            i = i + 3;
        }
        else if(a[i] == 'p' && a[i+1] == 'i' && a[i+2] == 'e') {
            ans++;
            i = i + 3;
        }
        else {
            i++;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {

        ll n;
        cin >> n;
        string s;

        cin >> s;

        cout <<countSubstring(s)<<endl;
    }
}