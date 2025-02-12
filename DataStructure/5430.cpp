#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main () {
    
    int T;
    cin>>T;

    int n;
    
    while (T--) {
        string cmd,str;
        bool reverse=false, error=false;
        deque<int> dq;
        cin >> cmd;
        cin >> n;
        cin >> str;
        string s="";
        for (char c:str) {
            if (isdigit(c)) {
                s+=c;
            }
            else {
                if (!s.empty()) {
                    dq.push_back(stoi(s));
                    s="";
                }
            }
        }

        for (char c:cmd) {
            if (c=='R') {
                reverse=!reverse;
            }
            else {
                if (dq.empty()) {
                    cout<<"error"<<endl;
                    error=true;
                    break;
                }
                if (reverse) dq.pop_back();
                else dq.pop_front();
            }
        }
        if (!error) {
            cout<<'[';
            if (reverse && !dq.empty()) {
                for (auto i = dq.rbegin(); i != dq.rend(); i++) {
                    if (i==dq.rend()-1) cout<<*i;
                    else cout<<*i<<',';
                }
            }
            else if (!reverse&&!dq.empty()){
                for (auto i = dq.begin(); i != dq.end(); i++) {
                    if (i == dq.end() - 1)
                        cout << *i;
                    else
                    cout << *i << ',';
                }
            }
            cout <<"]\n";
        }
    }
}