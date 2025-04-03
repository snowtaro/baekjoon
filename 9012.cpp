#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        stack<char> st;
        bool isValid = true;

        for (char c : s) {
            if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    isValid = false;
                    break;
                }
            } else if (c == '(') {
                st.push(c);
            }
        }

        if (isValid && st.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
