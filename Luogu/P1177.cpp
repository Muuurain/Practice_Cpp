#include <bits/stdc++.h>

using namespace std;

int ret[110000];
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        scanf("%d", &ret[i]);
    }
    sort(ret, ret + N);
    for(int i = 0; i < N; i++) {
        printf("%d ", ret[i]);
    }
    cout << endl;

    return 0;
}