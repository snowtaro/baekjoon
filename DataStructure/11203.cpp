#include <iostream>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h;
    cin>>h;

    string op;
    cin>>op;

    int total=2<<h;
    int target=1;
    for (char c : op) {
        if (c=='R') {
            target=target*2+1;
        }
        else {
            target=target*2;
        }
    }

    cout<<total-target;
}