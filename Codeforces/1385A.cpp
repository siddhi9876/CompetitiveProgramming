#include<bits/stdc++.h>
#define ll long long int
using namespace std;

//Trnasforms to lowercase : transform(s1.begin(), s1.end(),s1.begin(), ::tolower);

int main()
{
    ios_base :: sync_with_stdio(0);

    ll t;
    cin >> t;
    while(t--)
    {
        ll x, y, z;

        cin >> x >> y>> z;

        if( x!=y && y!=z && z!= x)
        {
            cout<< "NO"<< endl;
        }
        else if( x == y && y==z)
        {
            cout << "YES"<<endl;
            cout<<x<<" "<<x<<" "<<x<<endl;
        }
        else if( x==y)
        {
            if(y < z) cout<<"NO"<<endl;
            else
            {
                cout << "YES"<<endl;
                cout << x <<" "<< z <<" "<< z <<endl;
            }
        }
        else if(y==z)
        {
            if( x > y) cout<<"NO"<<endl;
            else{
                cout << "YES"<<endl;
                cout<<x<<" "<<x<<" "<<y<<endl;
            }
        }
        else if(x == z)
        {
            if( y > x) cout<<"NO"<<endl;
            else
            {
                cout << "YES"<<endl;
                cout<<y<<" "<<x<<" "<<y<<endl;
            }
        }
    }
 
}