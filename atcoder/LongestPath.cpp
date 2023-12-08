#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>child[100005];
vector<ll>visited(100005, 0);
vector<ll>depth(100005, 0);
ll dfs(ll root) {

    
    if(visited[root]) return depth[root];
    visited[root] = 1;
    ll ans = 0;
    for(int i=0; i< child[root].size(); i++)
    {
        ans = max(ans, dfs(child[root][i]));
    }

    depth[root] = ans + 1;

    return depth[root];
}
int main()
{
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++)
    {
        int x, y;
         cin >> x >> y;
         child[x].push_back(y);
    }

    ll ans = 0;
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            ans = max(ans, dfs(i));
        }
    }

    cout << ans - 1 <<endl;
}