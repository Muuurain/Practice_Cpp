#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    set<int> num;
    while(n--) {
        int i;
        cin >> i;
        num.insert(i);
    }
    if(k > num.size()) {
        cout << "NO RESULT" << endl;
    }
    else {
        auto it = num.begin();
        advance(it, k - 1);
        cout << *it << '\n';
    }
    
    return 0;
}