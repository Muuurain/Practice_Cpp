#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

int n, k;

string s;


int cal(char aim) {

int ret = 0;

int l = 0, r = 0;

int ch = 0;

while(r < n) {

if(s[r] == aim) {

if(ch == k) {

ret = max(ret, r - l);

if(s[l] == aim) {

l++;

}

else {

while(s[l] != aim) l++;

l++;

}

}

else {

ch++;

}

}

r++;

}

ret = max(ret, r - l);

return ret;

}


int main() {

ios::sync_with_stdio(false);

cin.tie(nullptr);

cout.tie(nullptr);

cin >> n >> k;

cin >> s;

int ret = cal('0');

ret = max(ret, cal('1'));


cout << ret << '\n';


return 0;

}

