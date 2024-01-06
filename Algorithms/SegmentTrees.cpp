#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>a, tree;

// segment tree root start at index 1
void build(int node, int st, int end) {
    if(st == end) {
        tree[node] = a[st];
        return;
    }

    ll mid = (st + end) / 2;

    build(2*node, st, mid);
    build(2*node + 1, mid + 1, end);

    tree[node] = tree[2*node] + tree[2*node + 1];
}

ll query(ll node, ll st, ll end, ll query_low, ll query_high) {
    
    //if current range outside query range return 0;
    if(query_high < st || query_low > end) return 0;

    //if current range completely inside query range return node value
    if(query_low <= st && end <= query_high) return tree[node];

    //iterate for left and right
    ll mid = (st + end) / 2;

    return query(2*node, st, mid, query_low, query_high) + query( 2*node + 1, mid + 1, end, query_low, query_high);
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
            update(2*node, st, mid, idx, val);
        else    
            update(2*node + 1, mid+ 1, end, idx, val);

        tree[node] = tree[2*node] + tree[2*node + 1];
    }

    return;
}

int main() {
    int n = 6;
    a = { 0, 1, 3, 5, -2, 3 };
 
    // Create a segment tree of size 4*n
    tree.resize(4 * n);
 
    // Build a segment tree
    build(1, 0, n - 1);
    cout << "Sum of values in range 0-4 are: "
         << query(1, 0, n - 1, 0, 4) << "\n";
 
    // Update the value at idx = 1 by
    // 100 thus becoming 101
    update(1, 0, n - 1, 1, 100);
    cout << "Value at index 1 increased by 100\n";
    cout << "sum of value in range 1-3 are: "
         << query(1, 0, n - 1, 1, 3) << "\n";
 
    return 0;
}

//Why 4*n
    //https://www.quora.com/Why-does-4-*-N-space-have-to-be-allocated-for-a-segment-tree-where-N-is-the-size-of-the-original-array#:~:text=The%20reason%204%20*%20N%20space,in%20an%20array%2Dbased%20representation.


