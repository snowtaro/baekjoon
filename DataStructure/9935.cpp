#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string text;
    string bomb;
    cin>>text>>bomb;

    stack<char> s;

    for (char c : text) {
        s.push(c);
        
        if (c == bomb[bomb.length()-1] && s.size() >= bomb.length()) {
            string tmp;
            for (int j=0;j<bomb.length();j++) {
                tmp.push_back(s.top());
                s.pop();
            }
            reverse(tmp.begin(),tmp.end());

            if (tmp.compare(bomb)!=0) {
                for (char c: tmp) {
                    s.push(c);
                }
            }
        }
    }

    if (s.empty()) {
        cout<<"FRULA";
        return 0;
    }
    else {
        string ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        cout<<ans;
    }

    return 0;
}