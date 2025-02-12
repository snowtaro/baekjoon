#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main () {
    int n;
    cin>>n;

    priority_queue<pair<int,int>> que;
    for (int i=0;i<n;i++) {
        int s,t;
        cin>>s>>t;

        que.push({s*-1,t*-1});
    }
    cout<<que.top().first<<' '<<que.top().second;
}