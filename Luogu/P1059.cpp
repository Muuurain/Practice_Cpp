#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int ret[1010];
int main() {
    int M;
    cin >> M;
    while(M--) {
        int t;
        scanf("%d", &t);
        ret[t]++;
    }
    int cnt = 0;
    for(int i = 1; i <= 1000; i++) {
        if(ret[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    cout << endl;

    return 0;
}