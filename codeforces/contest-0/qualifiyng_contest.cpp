#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, region, score;
    string name;
    vector<vector<pair<int, string>>> regions((int)1e6, vector<pair<int, string>>());

    cin >> n >> m;
    
    for(int i = 0; i < n; ++i) {
        cin >> name >> region >> score;
        regions[region].push_back({score, name});
    }

    for(auto &region: regions) {
        sort(region.begin(), region.end(), [](auto a, auto b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });
    }

    for(auto &region: regions) {
        if(region.size() == 2) {
            cout << region[0].second << " " << region[1].second << endl;
        } else if(region.size() > 2) {
            if(region[1].first == region[2].first) {
                cout << "?" << endl;
            } else {
                cout << region[0].second << " " << region[1].second << endl;
            }
        }
    }
 }
