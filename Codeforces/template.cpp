#include<bits/stdc++.h>
#define ll long long int
#define arr_size 1000000
using namespace std;

//Trnasforms to lowercase : transform(s1.begin(), s1.end(),s1.begin(), ::tolower);
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
int main()
{
    ios_base :: sync_with_stdio(0);

 
}