#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!(n % i)) { cnt++; }
	}
	cout << cnt;
}