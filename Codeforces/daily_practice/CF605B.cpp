#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct edge{
    int w;
    bool ismst;
    int index;
};
bool cmp1(edge& a, edge& b) {
    if(a.w != b.w) return a.w < b.w;
    return a.ismst > b.ismst;
}
bool cmp2(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<edge> e(m);
    for(int i = 0; i < m; i++) {
        cin >> e[i].w;
        cin >> e[i].ismst;
        e[i].index = i + 1;
    }
    sort(e.begin(), e.end(), cmp1);
    vector<pair<pair<int, int>, int> > ans;
    int totn = 1, l = 2, r = 3;
    for(int i = 0; i < m; i++) {
        if(e[i].ismst) ans.push_back({{1, ++totn}, e[i].index});
        else {
            if(r > totn) {
                cout << - 1 << '\n';
                return 0;
            }
            ans.push_back({{l++, r}, e[i].index});
            if(l == r) {
                r++;
                l = 2;
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp2);
    for(auto& i : ans) {
        cout << i.first.first << ' ' << i.first.second << '\n';
    }

    return 0;
}