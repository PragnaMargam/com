// 5.Implement LR parser 
// https://educatech.in/program-for-construction-of-lr-parsing-table-using-c/

#include <bits/stdc++.h>
using namespace std;

stack<char> st;

void printStack() {
    stack<char> temp = st;
    cout << "\n\t\t\t $";
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
}

int main() {
    string s1;
    cout << "LR PARSING"<<endl;
    cout << "ENTER THE EXPRESSION: "<<endl;
    cin >> s1;
    
    cout << "\n\t\t\t $";
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == 'i' && s1[i + 1] == 'd') {
            s1[i] = ' ';
            s1[i + 1] = 'E';
            printStack();
            cout << "id";
            st.push('E');
            printStack();
        } else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/' || s1[i] == 'd') {
            st.push(s1[i]);
            printStack();
        }
    }

    printStack();
    while (!st.empty()) {
        char ch1 = st.top();
        st.pop();
        if (ch1 == '+' || ch1 == '/' || ch1 == '*' || ch1 == '-') {
            if (!st.empty() && st.top() == 'E') {
                st.pop();
                st.push('E');
                printStack();
            } else {
                cout << "error";
                exit(0);
            }
        }
    }

    cout << endl;
    return 0;
}

//input: id+id*id-id