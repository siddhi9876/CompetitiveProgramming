#include<bits/stdc++.h>
#define ll long long int
using namespace std;

//Trnasforms to lowercase : transform(s1.begin(), s1.end(),s1.begin(), ::tolower);

int main()
{
    ios_base :: sync_with_stdio(0);

    int n;
    cin >> n;

    string s;
    cin>> s;
    int ans = 0;

    for(int i= 1; i<= s.length()-1; i++) {
        if(s[i] == s[i-1]) ans++;
    }
    cout<< ans <<endl;
}