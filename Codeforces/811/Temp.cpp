#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool compareInterval(pair<int, int> i1, pair<int, int> i2)
{
    if( i1.first == i2.first) return i1.second < i2.second;
    else return i1.first < i2.first;
}

void calculate (pair<int, int> greater, pair<int, int> smaller)
{
    //cout << greater << " " << smaller<< endl;
    //int greater_temp = greater * 100;
     int hr_g = greater.first; //greater_temp / 100;
     int min_g =  greater.second; // greater_temp % 100;
     //int min_g = min_gT;

    //int smaller_temp = smaller * 100;
     int hr_s = smaller.first; //smaller_temp /100;
     int min_s = smaller.second; // smaller_temp % 100;
    // int min_s = min_sT;

     //cout <<hr_g <<" " <<min_g <<" "<<hr_s<<" "<< min_s<<endl;

    if(greater < smaller)
    {
        hr_g = hr_g + 24;
    }

     if(min_g < min_s)
     {
         min_g = min_g + 60;
         hr_g--;
     }

     int diff_m = min_g - min_s;
     int diff_hr = hr_g - hr_s;

    //cout <<hr_g <<" " <<min_g <<" "<<hr_s<<" "<< min_s<<endl;
     cout <<diff_hr<< " " << diff_m<< endl;

}
int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        int n, H, M;

        cin >> n >> H >> M;

        vector<pair<int, int>> alarms;

        pair<int, int> sleepTime = make_pair(H, M);

        while(n--)
        {
            int h, m;
            cin >> h >> m;
            alarms.push_back(make_pair(h, m));
        }

        sort(alarms.begin(), alarms.end(), compareInterval);

        int ans = -1;

        if(alarms[alarms.size() - 1] < sleepTime)
        {
            calculate(alarms[0], sleepTime);
        }
        else
        {
            int i = 0;
            while (alarms[i] < sleepTime ) i++;

            calculate (alarms[i], sleepTime);
        }
    }
}