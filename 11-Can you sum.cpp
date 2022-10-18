#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	int n, q; cin >> n >> q; 
	vector<int>v(n);
	for (auto& it : v) { cin >> it; } 
	while (q--) {
		int a, b;  
		cin >> a >> b;
		a--; b--;
		int sum = 0; 
		for (int i = a; i <= b; i++) {
			sum += v[i];
		}
		cout << sum << "\n";
	}
}