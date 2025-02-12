#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main () {
    int n,k;
    cin>>n;

    bool apple[n+2][n+2]={false};
    bool visit[n+2][n+2]={false};

    //apple position
    cin>>k;
    int x,y;
    for (int i=0;i<k;i++) {
        cin>>x>>y;
        apple[x][y]=true;
    }
    
    //moving direction
    int dir=0;
    int dx[4]={0,-1,0,1};
    int dy[4]={1,0,-1,0};

    //snake body
    x=1; y=1;    
    deque<pair<int,int>> deq;
    deq.push_front({1,1});
    visit[1][1]=true;
    
    //main movement
    int ans=0;
    int l,t;
    char LD;
    cin>>l;
    for (int i=0;i<l;i++) {
        cin>>t>>LD;
        while (ans<t || i==l-1) {
            ans++;
            int nx=x+dx[dir];
            int ny=y+dy[dir];

            if (nx>=1 && ny>=1 && nx<=n && ny<=n && !visit[nx][ny]) {
                deq.push_front({nx,ny});
                if (apple[nx][ny]) {
                    apple[nx][ny]=false;
                    visit[nx][ny]=true;
                } else {
                    visit[nx][ny]=true;
                    visit[deq.back().first][deq.back().second]=false;
                    deq.pop_back();
                }
            } else {
                cout<<ans;
                return 0;
            }
            // cout<<"now : "<<ans<<nx<<ny<<endl;
            // cout<<"8;1 : "<<visit[8][1]<<endl;
            x=nx;
            y=ny;
            //dir change
            if(ans==t) {
                if (LD=='L') {
                    dir=(dir+1)%4;
                } else {
                    dir=(dir+3)%4;
                }
            }
        }
    }
    return 0;
}