#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string line;
    cin>>line;

    stack<char> st;

    int ans=0;
    int tmp=1;
    for (int i=0;i<line.length();i++) {
        //delete and multiply
        if (line[i]=='(') {
            tmp*=2;
            st.push('(');
        }
        else if (line[i]=='[') {
            tmp*=3;
            st.push('[');
        }
        else if (line[i]==')') {
            if (st.empty() || st.top()!='(') {
                ans=0;
                break;
            }
            if (line[i-1]=='(') {
                ans+=tmp;
                tmp/=2;
                st.pop();
            }
            else {
                tmp/=2;
                st.pop();
            }
        }
        else if (line[i]==']') {
            if (st.empty() || st.top()!='[') {
                ans=0;
                break;
            }
            if (line[i-1]=='[') {
                ans+=tmp;
                tmp/=3;
                st.pop();
            }
            else {
                tmp/=3;
                st.pop();
            }
        }
    }

    if (!st.empty()) ans=0;

    cout<<ans;
}