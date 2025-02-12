#include <bits/stdc++.h>

using namespace std;

/*
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);  // vector<int> graph[n];
    stack<int> st;
    unordered_set<int> visit;

    int chk;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> chk;
            if (chk) {
                graph[i].push_back(j);
            }
        }
    }

    // DFS
    int place;
    cin >> place;
    st.push(place);
    visit.insert(place);

    while (!st.empty()) {
        place = st.top();
        st.pop();

        for (int v : graph[place]) {
            if (visit.find(v) == visit.end()) {
                st.push(v);
                visit.insert(v);
            }
        }
    }

    bool check = false;
    for (int i = 1; i < m; i++) {
        cin >> place;
        if (visit.find(place) == visit.end()) {
            check = true;
            break;
        }
    }

    if (check) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
*/

int city[201];

int Find(int i) {
    if (city[i]<0) return i;
    return city[i]=Find(city[i]); //update city[i] to Find(city[i]) and return Find(city[i])
}

void Union(int i, int j) {
    int a=Find(i);
    int b=Find(j);

    if (a<b) {
        city[j]=a;
        city[a]-=city[b];
    }
    else {
        city[i]=b;
        city[b]-=city[a];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++) {
        city[i]=-1;
    }

    int isCon;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>isCon;
            if (isCon && j>=i) {
                Union(i,j);
            }
        }
    }


    int chkCity;
    bool chk = true;

    cin >> chkCity;
    int parent = Find(chkCity);
    for (int i = 1; i < m; i++) {
        cin >> chkCity;
        if (parent != Find(chkCity)) {
            chk = false;
            break;
        }
    }
    cout << (chk ? "YES" : "NO") ;

    return 0;
}