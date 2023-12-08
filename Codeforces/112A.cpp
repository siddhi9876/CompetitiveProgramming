#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    transform(s1.begin(), s1.end(),s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(),s2.begin(), ::tolower);

    int ans = 0;
    for(int i=0; i< s1.length(); i++) {

        if(s1[i] == s2[i]) continue;

        ans = s1[i] > s2[i] ? 1 : -1;
        break;
    }
    cout<<ans<<endl;
}