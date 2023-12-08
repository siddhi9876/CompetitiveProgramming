#include<bits/stdc++.h>
#define ll long long int
using namespace std;

long calculate(int index, int sum_needed)
{
    if(sum_needed == 0) return 0;

    while(index > sum_needed) index--;

    return index + calculate(index-1, sum_needed - index) * 10;
}
int main()
{
    int t;
     cin >> t;
      while(t--)
      {
          int sum;
          cin >> sum;

         cout << calculate(9, sum)<<endl;
    
      }
}