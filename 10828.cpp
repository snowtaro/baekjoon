#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main () {
    stack<int> s;
    int line;
    string command;
    int num;
    int result = 0;

    cin >> line;
    for (int i=0;i<line;i++) {
        cin>>command;

        if (command == "push") {
            cin >> num;
            s.push(num);
        }
        else if (command == "top") {
            if (s.empty()) cout<<-1<<endl;
            else cout<<s.top()<<endl;
        }
        else if (command == "size") {
            cout<<s.size()<<endl;
        }
        else if (command == "empty") {
            if (s.empty()) cout<<1<<endl;
            else cout<<0<<endl;
        }
        else if (command == "pop") {
            if (s.empty()) cout<<-1<<endl;
            else {
                cout<<s.top()<<endl;
                s.pop();
            }
        }
    }
}