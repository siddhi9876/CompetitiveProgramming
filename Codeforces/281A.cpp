#include<bits/stdc++.h>
#define ll long long int
using namespace std;

//Trnasforms to lowercase : transform(s1.begin(), s1.end(),s1.begin(), ::tolower);

int main()
{
    ios_base :: sync_with_stdio(0);

    string s;

    cin >> s;

    char ch = toupper(s[0]);

    string ans = string(1, ch);
    if(s.length() > 1) 
    {
        ans = ans + s.substr(1, s.length() - 1);
    }

    cout<< ans <<endl;
}