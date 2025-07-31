#include <bits/stdc++.h>
using namespace std;

int trie[100010 * 31][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int maxn = 0;
    int tot = 1;
    cin >> N;
    vector<int> num(N);
    for(int &it : num) {
        cin >> it;
        int p = 0;
        for(int i = 30; i >= 0; i--) {
            if(!trie[p][(it >> i) & 1]) {
                trie[p][(it >> i) & 1] = tot++;
            }
            p = trie[p][(it >> i) & 1];
        }
    }
    for(int it : num) {
        int ret = 0;
        int p = 0;
        for(int i = 30; i >= 0; i--) {
            if(trie[p][!((it >> i) & 1)]) {
                p = trie[p][!((it >> i) & 1)];
                ret += (!((it >> i) & 1)) << i;
            }
            else {
                p = trie[p][(it >> i) & 1];
                ret += ((it >> i) & 1) << i;
            }
        }
        maxn = max(maxn, it ^ ret);
    }

    cout << maxn << endl;
    
    return 0;
}