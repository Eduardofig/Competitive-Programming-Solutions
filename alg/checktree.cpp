#include <bits/stdc++.h>

using namespace std;

long long to, from;

unordered_map<long long, vector<long long>> g;
unordered_map<long long, int> refs;
unordered_set<long long> nodes;

int k = 1;

void solve()
{
    long long root = -1;

    for(auto node: nodes) {
        //check 1
        if(refs[node] == 0) {
            if(root != -1) {
                cout << "is not a tree." << endl;
                return;
            }

            root = node;
        }

        //check 2
        if(refs[node] > 1) {
            cout << "is not a tree." << endl;
            return;
        }
    }


    //check 3:
    unordered_set<long long> vis;
    queue<long long> q;
    long long curr;

    q.push(root);
    while(!q.empty()) {
        curr = q.front();
        q.pop();

        vis.insert(curr);
        for(long long next: g[curr]) {
            if(vis.find(next) == vis.end()) {
                q.push(next);
            }
        }
    }

    for(auto node: nodes) {
        if(vis.find(node) == vis.end()) {
            cout << "is not a tree." << endl;
            return;
        }
    }

    cout << "is a tree." << endl;
}

int main()
{
    while(cin >> from) {
        cin >> to;

        if(to == -1 && from == -1) break;

        if(to == 0 && from == 0) {
            cout << "Case " << k++ << " ";
            solve();

            for(auto vec = g.begin(); vec != g.end(); ++vec) (*vec).second.clear();

            nodes.clear();
            refs.clear();

            continue;
        }

        nodes.insert(from);
        nodes.insert(to);
        g[from].push_back(to);
        refs[to]++;
    }
}
