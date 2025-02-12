#include <bits/stdc++.h>

using namespace std;

int city[201];

int Find(int i) {
    if (city[i]<0) return i;
    return city[i]=Find(city[i]); //update city[i] to Find(city[i]) and return Find(city[i])
}

void Union(int i, int j) {
    int a=Find(i);
    int b=Find(j);

    if (a==b) return;

    if (city[a]<city[b]) {
        city[a]+=city[b];
        city[b]=a;
    }
    else {
        city[b]+=city[a];
        city[a]=b;
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