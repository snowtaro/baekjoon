#include <iostream>

using namespace std;

int parent[1000001];

int findOper(int x) {
    if (parent[x]<0) return x;
    return parent[x]=findOper(parent[x]); //path compression
}

void unionOper(int a, int b) {
    a=findOper(a); b=findOper(b);
    if (a!=b) {
        if (parent[a]<parent[b]) {
            parent[a]+=parent[b];
            parent[b]=a;
        }
        else {
            parent[b]+=parent[a];
            parent[a]=b;
        }
    }
}

void isSameSet(int a, int b) {
    a=findOper(a); b=findOper(b);
    if (a==b) cout<<"YES\n";
    else cout<<"NO\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin>>n>>m;

    //parent initialize
    for (int i=0;i<=n;i++) {
        parent[i]=-1;
    }

    //operating
    int op,a,b;
    for (int i=0;i<m;i++) {
        cin>>op>>a>>b;
        if (!op) {
            unionOper(a,b);
        }
        else {
            isSameSet(a,b);
        }
    }
    return 0;
}