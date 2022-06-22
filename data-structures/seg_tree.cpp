#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MXN = 2e5 + 3;
ll n;
ll tree[MXN * 2];
ll arr[MXN];

ll query_tree_rec(ll node, ll node_low, ll node_high, ll query_low, ll query_high)
{
    if(query_low <= node_low && query_high >= node_high) {
        return tree[node];
    }

    if(node_high < query_low || node_low > query_high) {
        return 0;
    }

    ll node_mid = (node_low + node_high) / 2;
    return query_tree_rec(2 * node, node_low, node_mid, query_low, query_high) +
        query_tree_rec(2 * node, node_mid + 1, node_high, query_low,
                query_high);
}

ll query_tree(ll low, ll high)
{
    return query_tree_rec(0, 0, n - 1, low, high);
}

void make_tree()
{
    while(__builtin_popcount(n) != 1) {
        arr[n++] = 0;
    }

    for(int i = 0; i < n; ++i) {
        tree[n + i] = arr[i];
    }

    for(int i = n - 1; i >= 1; i--) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

void update_tree(ll p, ll val)
{
    tree[p + n] = val;
    p += n;

    for(int i = p; i > 1; i >>= 1) {
        tree[i >> 1] = tree[i] + tree[i - 1];
    }
}

int main()
{
    for(ll i = 0; i < 12; ++i) {
        arr[i] = i;
    }
    n = 12;

    make_tree();
    update_tree(2, 1);

    cout << query_tree(1, 3) << '\n';

}
