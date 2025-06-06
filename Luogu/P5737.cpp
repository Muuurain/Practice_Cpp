#include <bits/stdc++.h>

using namespace std;

bool isry(int x) {
    return ((x % 4  == 0 && x % 100 != 0) || x % 400 == 0);
}

int main() {
    int x, y;
    cin >> x >> y;
    string ret = "";
    for(int i = x; i <= y; i++) {
        char ans[10] = {'\0'};
        if(isry(i)) {
            sprintf(ans, "%d ", i);
            ret += ans;
        }
    }
    cout << (ret.length() / 5) << endl << ret << endl;

    return 0;
}