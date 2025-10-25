#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 1) {
            return false;
        }

        stack<char> myStack;
        int s_len = s.length();

        for (int i = 0; i < s_len; i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                myStack.push(s[i]);
            }

            else if ((s[i] == '}' || s[i] == ']' || s[i] == ')') && myStack.empty()) {
                return false;
            }

            else {
                if (myStack.top() == '{' && (s[i] == ']' || s[i] == ')')) {
                    return false;
                }

                else if (myStack.top() == '[' && (s[i] == ')' || s[i] == '}')) {
                    return false;
                }

                else if (myStack.top() == '(' && (s[i] == ']' || s[i] == '}')) {
                    return false;
                }

                else if ((myStack.top() == '(' && s[i] == ')') ||
                         (myStack.top() == '[' && s[i] == ']') ||
                         (myStack.top() == '{' && s[i] == '}')) {
                    myStack.pop();
                }
            }
        }

        return myStack.empty() == 1;
    }
};
