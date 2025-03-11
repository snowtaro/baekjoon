#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int s,e;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;

    vector<pair<int,int>> con; // end, start pair

    for (int i=0;i<n;i++) {
        cin>>s>>e;
        con.push_back({e,s});
    }

    sort(con.begin(), con.end());
    
    int idx=-1;
    int result=0;

    for (auto i : con) {
        if (idx<=i.second) {
            idx=i.first;
            result++;
        }
    }
    cout<<result;
}