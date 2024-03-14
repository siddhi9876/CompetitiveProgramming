#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll vec[101][100005];

ll findMin(int row, int d, int col) {

    vector<ll>ans;
    deque<ll>dq;

    ll minInLastd = 1;

    for(int i = 0; i < d; i++) {

        int temp = vec[row][i] + 1;
        if(i != 0) temp = temp + minInLastd;  //Need to include index 0;
        ans.push_back(temp);

        while(!dq.empty() && ans[i] <= ans[dq.back()]) {
            //cout<<"i : "<<i <<"vec[row][i] : "<<vec[row][i]<<"dq.back() : "<< dq.back()<<"vec[row][dq.back()]: "<<vec[row][dq.back()]<<endl;
            dq.pop_back();
        }
        dq.push_back(i);

        //cout<<"dp.front(): "<<dq.front()<<"ans "<<i << "val: "<<ans[i]<<endl;
    }

    minInLastd = ans[dq.front()];

    //cout<<"minInLastD "<<dq.front()<<" "<<ans[dq.front()]<<endl;

    for(int i = d; i < col; i++) {

        //find minm if current is included
        ans.push_back(vec[row][i] + 1 + minInLastd);

        // remove elements out of current window
        while(!dq.empty() && dq.front() <= i - d)
            dq.pop_front();

        while(!dq.empty() && ans[i] <= ans[dq.back()]) dq.pop_back();
        dq.push_back(i);

        minInLastd = ans[dq.front()];

        //cout<<"ans "<<i << "val: "<<ans[i]<<" minInlastd : " <<minInLastd<< endl;
    }
    return ans[col-1];
}

int main()
{
    int t;
    cin >> t;

    while(t--) {
        ll n, m, k, d;

        cin >> n >> m >> k >> d;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <m; j++) {
                cin >> vec[i][j];
            }
        }

        vector<ll>minRow(n, 0);

        for(int i = 0; i < n;i++) {
            minRow[i] = findMin(i, d+1, m);
            //cout <<"Row: "<<i<<"minRow[i] : "<<minRow[i]<<endl;
        }

        ll sum = 0;

        for(int i = 0; i <k; i++) {
            sum = sum + minRow[i];
        }

        ll ans = sum;


        for(int i = k; i<n;i++) {
            sum = sum + minRow[i] - minRow[i-k];
            ans = min(ans, sum);
        }

        cout <<ans<<endl;
    }
}