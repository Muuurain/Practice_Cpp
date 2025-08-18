#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
long long ans;
int n, k;
bool st[N];
bool visit[30];
void setprime() {
    st[0] = 1;
    st[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!st[i]){
            for(int j = 2; j * i < N; j++) {
                st[i * j] = 1;
            }
        }
    }
}
void dfs(int cnt, vector<int> &arr, int ret, int t) {
    if(cnt == k) {
        if(!st[ret]) {
            ans++;
        }
        return;
    }
    for(int i = t; i < n; i++) {
            dfs(cnt + 1, arr, ret + arr[i], i + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    setprime();
    cin >> n >> k;
    vector<int> arr(n);
    for(int &it : arr) cin >> it;
    dfs(0, arr, 0, 0);
    cout << ans << endl;

    return 0;
}