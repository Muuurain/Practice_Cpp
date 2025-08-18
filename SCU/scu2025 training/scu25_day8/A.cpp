#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> A(n), B(n);
    for(auto &i : A) {
        string s;
        cin >> s;
        i = s;
    }
    for(auto &i : B) {
        string s;
        cin >> s;
        i = s;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == B[i][j]) cnt1++;
            else cnt2++;
        }
    }
    if(cnt1 >= cnt2) {
        for(auto i : A) {
            for(auto j : i) cout << j;
            cout << endl;
        }
    }
    else {
        for(auto i : A) {
            for(auto j : i) {
                if(j == '.') cout << 'X';
                else cout << '.';
            }
            cout << endl;
        }
    }

    return 0;
}