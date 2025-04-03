#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string inorder;
    cin>>inorder;
    
    string post="";
    
    stack<char> st;

    for (char c : inorder) {
        if (!isalpha(c)) {
            if (c==')') {
                while (st.top()!='(') {
                    post+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if (c=='+' or c=='-') {
                while (!st.empty() && st.top()!='(') {
                    post+=st.top();
                    st.pop();
                }
                st.push(c);
            }
            else if (c=='*' or c=='/') {
                while (!st.empty() && st.top()!='(' && st.top()!='+' && st.top()!='-') {
                    post+=st.top();
                    st.pop();
                }
                st.push(c);
            }
            else {
                st.push(c);
            }
        }
        else { //alphabet
            post+=c;
        }
    }
    while (!st.empty()) {
        post+=st.top();
        st.pop();
    }

    cout<<post;
}