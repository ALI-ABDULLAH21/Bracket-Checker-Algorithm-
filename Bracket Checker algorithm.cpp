#include<iostream>
#include<stack>
using namespace std;

class BracketChecker {
public:
    bool pairChecker(char cl, char op) {
        if (op == '[' && cl == ']') {
            return true;
        } else if (op == '{' && cl == '}') {
            return true;
        } else if (op == '(' && cl == ')') {
            return true;
        } else {
            return false;
        }
    }

    bool checkBrackets(string n) {
        stack<char> s;
        for (int i = 0; i < n.length(); i++) {
            if (n[i] == '[' || n[i] == '{' || n[i] == '(') {
                s.push(n[i]);
                
            } else if (n[i] == ']' || n[i] == '}' || n[i] == ')') {
                if ( !pairChecker(n[i], s.top())) {
                	
                    cout << "Expression is not balanced" << endl;
                    cout<<"Bracket at position  "<<i<<"cause an Error"<<endl;
                    return false;
                } else {
                    s.pop();
                }
            }
        }
        if (s.empty()) {
            cout << "Expression is balanced" << endl;
            return true;
        } else {
            cout << "Expression is not balanced" << endl;
            return false;
        }
    }
};

int main() {
    BracketChecker b;
    cout << "Enter the expression for the brackets:" << endl;
    string expression;
    cin >> expression;
    b.checkBrackets(expression);
    
    return 0;
}

