#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n = 100000000;

string addTwoStrings (string a, string b) {


    if(a.length() < b.length()) return addTwoStrings(b, a);

    string ans = "";
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < a.length(); i++)
    {
            int x = a[i] - '0';
            int y =  b.length() - 1 >= i ? (b[i] - '0') : 0;

            int sum = x + y + carry;
            char c = char((sum % 10) + 48);

            ans = ans + c;
            carry = sum / 10;
    }

    if(carry != 0) {
        char c = char(carry + 48);
        ans = ans + c;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
  string a;
  string b;

  cin >>a >> b;

  cout << addTwoStrings(a, b) <<endl;
}