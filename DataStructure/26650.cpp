#include <iostream>
#include <string>
#include <vector>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

int main () {
    fastio;
    string s;

    cin>>s;
    auto idx=s.find('A'); int cnt=1; bool chk=false;
    if (idx==string::npos) {
        cout<<0;
        return 0;
    }
    
    vector<int> idxlst;
    for (int i=idx+1;i<s.length();i++) {
        if (s[i]-s[i-1]>1 or s[i]-s[i-1]<0) {
            idx++;
            cnt=1;
        }
        else if (s[i]=='Z') {
            chk=true;
            cnt=1;
            idxlst.push_back(idx);
        }
        else cnt++;
    }
    int front=idx, end=idx+cnt;

    while (s[front]=='A' && front>=0) {
        front++;
    }
    while (s[end]=='Z' && end<s.length()) {
        end++;
    }
    if (chk) {
        cout<<(front-idx)*(end-idx-cnt);
    }
    else cout<<0;
    return 0;
}