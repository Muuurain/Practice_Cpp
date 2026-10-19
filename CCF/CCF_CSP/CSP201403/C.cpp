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

    string s;
    cin >> s;
    s.push_back(' ');
    map<char, bool> para, nopara;
    map<char, string> m;
    for(int i = 0; i < s.size() - 1; i++) {
        char c = s[i];
        if(c == ':') continue;
        if(s[i + 1] == ':') para[c] = true;
        else nopara[c] = true;
    }
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        m.clear();
        string t;
        cin >> t;
        string si;
        getline(cin, si);
        stringstream ss(si);
        vector<string> sj;
        string ts;
        while(ss >> ts) {
            sj.push_back(ts);
        }
        for(int j = 0; j < sj.size(); j++) {
            if(sj[j].size() == 2) {
                if(sj[j][0] == '-') {
                    if(para[sj[j][1]]) {
                        if(j != sj.size() - 1) {
                            m[sj[j][1]] = sj[j + 1];
                            j++;
                        }
                        else break;
                    }
                    else if(nopara[sj[j][1]]) {
                        m[sj[j][1]] = '#';
                    }
                    else break;
                }
                else break;
            }
            else break;
        }
        cout << "Case " << i << ":";
        for(auto &[key, value] : m) {
            cout << " -" << key;
            if(value != "#") cout << " " << value;
        }
        cout << '\n';
    }

    return 0;
}