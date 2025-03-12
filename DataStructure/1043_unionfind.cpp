#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
int parent[51];

int Find(int x) {
    if (parent[x] < 0) return x;
    return parent[x]=Find(parent[x]);
}

void Union(int a, int b) {
    a=Find(a); b=Find(b);
    if (a != b) {
        if (parent[a] < parent[b]) {
            parent[a] += parent[b];
            parent[b] = a;
        } else {
            parent[b] += parent[a];
            parent[a] = b;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for (int i=0;i<=n;i++) {
        parent[i]=-1;
    }

    int numknows;
    cin>>numknows;
    set<int> knows;
    for (int i=0;i<numknows;i++) {
        int kidx;
        cin>>kidx;
        knows.insert(Find(kidx));
    }
    
    vector<vector<int>> parties(m);

    for(int i=0;i<m;i++) {
        int people;
        cin>>people;
        parties[i].resize(people);
        
        for(int j=0;j<people;j++) {
            cin>>parties[i][j];
        }
        
        for(int j=1;j<people;j++) {
            Union(parties[i][0], parties[i][j]);
        }
    }

    set<int> truthGroups;
    for (int person : knows) {
        truthGroups.insert(Find(person));
    }

    int result=0;
    for (int i=0;i<m;i++) {
        bool canLie=true;
        for (int person : parties[i]) {
            if (truthGroups.count(Find(person))) {
                canLie=false;
                break;
            }
        }
        if (canLie) result++;
    }

    cout<<result;
    return 0;
}
