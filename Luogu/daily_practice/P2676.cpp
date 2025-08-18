#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int cow[21000];
int main() {
    int n, b;
    cin >> n >> b;
    for(int i = 0; i < n; i++) {
        scanf("%d", &cow[i]);
    }
    sort(cow, cow + n, cmp);
    int sum = 0;
    int cnt = 0;
    while(sum < b) {
        sum += cow[cnt++];
    }
    cout << cnt << endl;

    return 0;
}