#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main () {
    string text;
    cin>>text;

    string result="";

    stack<char> opers;
    string tmp="";

    for (int i=0;i<text.length();i++) {
        if (isdigit(text[i])) {
            tmp+=text[i];
        }
        else if (text[i]=='<' || text[i]=='>') {
            if (tmp.length()) {
                result+=tmp;
                result+=' ';
                tmp="";
            }

            while (!opers.empty() && (opers.top()=='<' || opers.top()=='>' )) {
                result = result + opers.top() +" ";
                opers.pop();
            }
            opers.push(text[i]);
            i++;
        }
        else if (!opers.empty() && (text[i]=='+' || text[i]=='-')) {
            if (tmp.length()) {
                result+=tmp;
                result+=' ';
                tmp="";
            }

            while (!opers.empty()) {
                result = result + opers.top() + " ";
                opers.pop();
            }
            opers.push(text[i]);
        }
        else if (text[i]=='(') {
            opers.push('(');
        }
        else if (text[i]==')') {
            if (tmp.length()) {
                result+=tmp;
                result+=' ';
                tmp="";
            }

            while (!opers.empty() && opers.top()!='(') {
                result+=opers.top();
                result+=' ';
                opers.pop();
            }
            opers.pop();
        }
    }

    while (!opers.empty()) {
        if (tmp.length()) {
            result+=tmp;
            result+=' ';
            tmp="";
        }
        result+=opers.top();
        result+=' ';
        opers.pop();
    }

    cout<<result;
}

