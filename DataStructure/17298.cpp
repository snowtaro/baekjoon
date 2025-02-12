#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int N;
	int ans[1000001];
	int seq[1000001];
	stack<int> s;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}
	
	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= seq[i]) s.pop();

		if (s.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();
		}
		s.push(seq[i]);
	}
	
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
}