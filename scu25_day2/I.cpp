#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    set<int> op1, op2, op3, op4;
    
    for (int i = 0; i < q; ++i) {  
        char x, y;
        cin >> x >> y;
        if (x == 'b' && y == 'a') {
            op1.insert(i);
        } else if (x == 'b' && y == 'c') {
            op2.insert(i);
        } else if (x == 'c' && y == 'a') {
            op3.insert(i);
        } else if (x == 'c' && y == 'b') {
            op4.insert(i);
        }
    }
    
    for (char &c : s) { 
        if (c == 'b') {
            if (!op1.empty()) {
                op1.erase(op1.begin()); 
                c = 'a';
            } 
            else if (!op2.empty() && !op3.empty()) {
                int x = *op2.begin();  
                auto it = op3.lower_bound(x); 
                if (it != op3.end()) { 
                    op2.erase(op2.begin());  
                    op3.erase(it); 
                    c = 'a';
                }
            }
        } 
        else if (c == 'c') {
            if (!op3.empty()) {
                op3.erase(op3.begin()); 
                c = 'a';
            } 
            else if (!op4.empty() && !op1.empty()) {
                int x = *op4.begin(); 
                auto it = op1.lower_bound(x); 
                if (it != op1.end()) { 
                    op4.erase(op4.begin()); 
                    op1.erase(it); 
                    c = 'a';
                }
                else {
                    op4.erase(op4.begin()); 
                    c = 'b';
                }
            }
            else if (!op4.empty()) {
                op4.erase(op4.begin()); 
                c = 'b';
            }
        }
    }
    
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}