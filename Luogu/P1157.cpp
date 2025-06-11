#include <bits/stdc++.h>
using namespace std;

int n, r;
vector<int> ret;
void dfs(int cnt, int num) {
    if(cnt == r) {
        for(int i : ret) cout << setw(3) << i;
        cout << endl; 
        return;
    }
    for(int i = num; i <= (n - r + cnt + 1); i++) {
        ret.push_back(i);
        dfs(cnt + 1, i + 1);
        ret.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r;
    dfs(0, 1);

    return 0;
}