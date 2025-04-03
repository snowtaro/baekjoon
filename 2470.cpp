#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    
    vector<long> lid;
    long id;

    for (int i=0;i<n;i++) {
        cin>>id;
        lid.push_back(id);
    }
    sort(lid.begin(),lid.end());

    // two pointer
    int left=0, right=n-1;
    
    long result=abs(lid[0]+lid[n-1]);
    long idsum;
    long leftid=lid[0], rightid=lid[n-1];

    while (left<right) {
        idsum=lid[left]+lid[right];

        if (idsum==0) {
            leftid=lid[left];
            rightid=lid[right];
            break;
        }
        if (abs(idsum)<result) {
            result=abs(idsum);
            leftid=lid[left];
            rightid=lid[right];
        }
        else if (idsum>0) {
            right--;
        }
        else if (idsum<0) {
            left++;
        }
    }
    cout<<leftid<<' '<<rightid;

    return 0;
}