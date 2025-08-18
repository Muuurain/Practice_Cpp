#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        int age;
        int scores;
        cin >> s >> age >> scores;
        age++;
        scores *= 1.2;
        scores = min(scores, 600);
        cout << s << " " << age << " " << scores << endl;
    }

    return 0;
}