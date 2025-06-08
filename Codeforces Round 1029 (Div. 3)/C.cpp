#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        int arr[20010]  = {0};
        queue<int> pos[20010];
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            pos[arr[i]].push(i);
        }
        int ret = 1;
        int begin = 0;
        int last = 0;
        while(last != n - 1) {
            int maxp = last;
            int value = 1;
            while(begin <= last) {
                if(!pos[arr[begin]].empty()) {
                    int t = pos[arr[begin]].front();
                    pos[arr[begin]].pop();
                    if(t < last) {
                        continue;
                    }
                    else{
                        maxp = max(maxp, t);
                        begin++;
                    }
                }
                else {
                    value = 0;
                    break;
                }
            }
            if(value) {
                ret++;
                last = maxp;
            }
            else {
                break;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}