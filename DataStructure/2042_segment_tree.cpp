#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    int num[n+1];
    for (int i=1;i<=n;i++) { 
        cin>>num[i];
    }

    int a,b,c;
    for (int i=0;i<m+k;i++) {
        cin>>a>>b>>c;
        if (a==1) {
            num[b]=c;
        }
        else { //a==2
            int sum=0;
            for (int i=b;i<=c;i++) {
                sum+=num[i];
            }
            cout<<sum<<'\n';
        }
    }
    return 0;
}