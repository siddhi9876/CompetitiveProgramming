#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>a, tree;

// segment tree root start at index 0
void build(int node, int st, int end) {
    if(st == end) {
        tree[node] = a[st];
        return;
    }

    ll mid = (st + end) / 2;

    build(2*node + 1, st, mid);
    build(2*node + 2, mid + 1, end);

    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

ll query(ll node, ll st, ll end, ll query_low, ll query_high) {
    
    //if current range outside query range return 0;
    if(query_high < st || query_low > end) return 0;

    //if current range completely inside query range return node value
    if(query_low <= st && end <= query_high) return tree[node];

    //iterate for left and right
    ll mid = (st + end) / 2;

    return query(2*node +1, st, mid, query_low, query_high) + query( 2*node + 2, mid + 1, end, query_high, query_low);
}

void update(ll node, ll st, ll end, ll idx, ll val) {

    if(st == end) {
        a[idx] += val;
        tree[node] += val;
    }
    else {
        ll mid = (st + end) /2;

        //if index is on left go left
        if(idx <= mid)
            update(2*node + 1, st, mid, idx, val);
        else    
            update(2*node + 2, mid+ 1, end, idx, val);

        tree[node] = tree[2*node +1] + tree[2*node + 2];
    }

    return;
}

int main() {
    
}
