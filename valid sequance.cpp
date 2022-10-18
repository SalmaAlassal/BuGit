#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    	string s; cin >> s; 
	stack<char>st;
	for (auto it : s) {
		if (it == '(') { st.push(it); }
		else { st.pop(); }
	}
	cout << (st.empty() ? "YES" : "NO");
}