// template_pre_standard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template <typename T>
void debug_impl(const T& val) {
    cout << val;
}
template <typename T>
void debug_impl(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) cout << ", ";
        debug_impl(vec[i]);
    }
    cout << "]";
}
#define debug(x) do { \
    cout << "debug(" << #x << "): "; \
    debug_impl(x); \
    cout << '\n'; \
} while(0)

ll r;

struct dot{
    ll x, y;
    ll id;
};

bool con(dot d1, dot d2) {
    return pow((d1.x - d2.x), 2) + pow((d1.y - d2.y), 2) <= pow(r, 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k >> r;
    ll sumd = n + m;
    vector<dot> dots(sumd + 5);

    for(int i = 1; i <= sumd; i++) {
        dots[i].id = i;
        cin >> dots[i].x >> dots[i].y;
    }

    vector<vector<ll> > step(n + m + 10, vector<ll>(k + 10, -1));
    step[1][0] = 0;
    queue<pair<dot, int> > q;
    q.push({dots[1], 0});

    while(!q.empty()) {
        auto td = q.front();
        q.pop();
        for(int i = 2; i <= sumd; i++) {
            if(i <= n) {
                if(step[i][td.second] != -1) continue;
            }
            else {
                if(step[i][td.second + 1] != -1) continue;
            }
            if(con(td.first, dots[i])) {
                if(i == 2) {
                    step[i][td.second] = step[td.first.id][td.second];
                    cout << step[i][td.second] << '\n';
                    return 0;
                }
                else if(i <= n) {
                    step[i][td.second] = step[td.first.id][td.second] + 1;
                    q.push({dots[i], td.second});
                }
                else {
                    if(td.second + 1 > k) continue;
                    step[i][td.second + 1] = step[td.first.id][td.second] + 1;
                    q.push({dots[i], td.second + 1});
                }
            }
        }
    }

    return 0;
}