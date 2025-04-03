#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cin.tie(nullptr);

using namespace std;

bool cmp(const pair<int,int>&a, const pair<int,int>& b) {
    if  (a.second==b.second) return a.first<b.first;
    return a.second < b.second;
}

int main () {
    long long l;
    int n,k;
    cin>>l>>n>>k;
    long long jax[n]; //가로등 위치

    for (int i=0;i<n;i++) {
        cin>>jax[i];
    }

    set<long long> visit; //bfs용 방문 가로등 위치
    deque<long long> deq; //bfs용 큐
    map<long long,long long> light; //밝기별 개수

    for (int i=0;i<n;i++) {
        visit.insert(jax[i]);
        light[jax[i]]=0;
        deq.push_back(jax[i]);
    }

    int count=0;
    long long tmp; //큐의 첫 값 받는곳
    while (!deq.empty()) {
        tmp=deq.front();
        deq.pop_front();
        count++;
        if (tmp-1>=0 && visit.find(tmp-1)==visit.end()) {
            light[tmp-1]=light[tmp]+1;
            visit.insert(tmp-1);
            deq.push_back(tmp-1);
        }
        if (tmp+1<=l && visit.find(tmp+1)==visit.end()) {
            light[tmp+1]=light[tmp]+1;
            visit.insert(tmp+1);
            deq.push_back(tmp+1);
        }
        if (count == k) break;
    }
    vector<pair<long long,long long>> vec(light.begin(), light.end());
    sort(vec.begin(),vec.end(),cmp);

    for (int i=0;i<k;i++) {
        cout<<vec[i].second<<'\n';
    }
}