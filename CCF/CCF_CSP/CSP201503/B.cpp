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


struct NUM{
    int num = -1;
    int time = 0;
};
bool cmp(NUM& a, NUM& b) {
    if(a.time != b.time) return a.time > b.time;
    else return a.num < b.num;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<NUM> number(1010);
    for(int i = 0; i <= 1000; i++) {
        number[i].num = i;
    }
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        number[t].time++;
    }
    sort(number.begin(), number.end(), cmp);
    for(int i = 0; i <= 1000; i++) {
        if(number[i].time) {
            cout << number[i].num << " " << number[i].time << '\n';
        }
        else break;
    }

    return 0;
}