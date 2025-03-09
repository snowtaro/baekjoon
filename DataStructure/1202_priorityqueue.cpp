#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> max_pq;

// global value is initialized 0 automatically
int N, K;
int p;
vector<pair<int, int>> gems;
vector<int> bag;

int findJem(int i) {
    while (p < N && gems[p].first <= bag[i])  {    // all jewel that satisfy condition pushed in priority queue.
        max_pq.push(gems[p++].second);
    }
    
    if (max_pq.empty()) {
        return 0;
    }
    else {
        int ret = max_pq.top(); max_pq.pop();   // highest value jewel returns
        return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int w, v, c;
	
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        gems.push_back({w, v});
    }
    
    for (int i = 0; i < K; i++) {
        cin >> c;
        bag.push_back(c);
    }
    
    sort(gems.begin(), gems.end()); // sort weight asc
    sort(bag.begin(), bag.end());   // sort bag capacity asc
    
    long long sum = 0;
    
    for (int i = 0; i< K; i++) {
        sum += (long long)findJem(i);
    }
    
    cout << sum;

    return 0;
}
