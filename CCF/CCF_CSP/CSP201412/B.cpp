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

    int n;
    cin >> n;
    vector<vector<int> > num(n + 5, vector<int>(n + 5));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }
    int i = 1, j = 1;
    int op = 0;
    int mx = n * n;
    while(mx--) {
        cout << num[i][j] << (mx ? " " : "\n");
        if(op ==  0) {
            j++;
            op = 1;
        }
        else if(op == 1) {
            if(j > 1) {
                i++;
                j--;
            }
            else {
                if(i < n) {
                    i++;
                    op = 2;
                }
                else {
                    j++;
                    op = 3;
                }
            }
        }
        else if(op == 2) {
            if(i > 1) {
                i--;
                j++;
            }
            else {
                if(j < n) {
                    j++;
                    op = 1;
                }
                else {
                    i++;
                    op = 4;
                }
            }
        }
        else if(op == 3) {
            if(j < n) {
                i--;
                j++;
            }
            else {
                i++;
                op = 4;
            }
        }
        else {
            if(i < n) {
                i++;
                j--;
            }
            else {
                j++;
                op = 3;
            }
        }
    }

    return 0;
}