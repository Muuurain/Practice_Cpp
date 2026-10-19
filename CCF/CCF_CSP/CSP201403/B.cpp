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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<pair<int, int> > win1(N + 5), win2(N + 5);
    for(int i = 1; i <= N; i++) {
        pair<int, int> t1, t2;
        cin >> t1.first >> t1.second;
        win1[i] = t1;
        cin >> t2.first >> t2.second;
        win2[i] = t2;
    }

    vector<int> po1(N + 5), po2(N + 5);
    for(int i = 1; i <= N; i++) {
        po1[i] = N - i + 1;
    }

    int turn = 1;
    while(M--) {
        int x, y;
        cin >> x >> y;
        if(turn == 1) {
            for(int i = 1; i <= N; i++) {
                int id = po1[i];
                if(win1[id].first <= x && win1[id].second <= y && win2[id].first >= x && win2[id].second >= y) {
                    po2[1] = id;
                    for(int j = 2; j <= i; j++) {
                        po2[j] = po1[j - 1];
                    }
                    for(int j = i + 1; j <= N; j++) {
                        po2[j] = po1[j];
                    }
                    turn = 2;
                    cout << id << '\n';
                    break;
                }
            }
            if(turn == 1) cout << "IGNORED" << '\n';
        }
        else {
            for(int i = 1; i <= N; i++) {
                int id = po2[i];
                if(win1[id].first <= x && win1[id].second <= y && win2[id].first >= x && win2[id].second >= y) {
                    po1[1] = id;
                    for(int j = 2; j <= i; j++) {
                        po1[j] = po2[j - 1];
                    }
                    for(int j = i + 1; j <= N; j++) {
                        po1[j] = po2[j];
                    }
                    turn = 1;
                    cout << id << '\n';
                    break;
                }
            }
            if(turn == 2) cout << "IGNORED" << '\n';
        }
    }

    return 0;
}