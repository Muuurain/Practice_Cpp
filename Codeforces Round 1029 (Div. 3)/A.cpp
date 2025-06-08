#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        int door[20] = {0};
        for(int i = 0; i < n; i++) {
            scanf("%d", &door[i]);
        }
        int used = 0;
        for(int i = 0; i < n;) {
            if(door[i] == 1) {
                if(used ==  0)  {
                    i += x;
                    used = 1;
                    if(i >= n) {
                        printf("YES\n");
                        break;
                    }
                }
                else {
                    printf("NO\n");
                    break;
                }
            }
            else {
                i++;
                if(i == n ) {
                    printf("YES\n");
                    break;
                }
            }
        }
    }

    return 0;
}