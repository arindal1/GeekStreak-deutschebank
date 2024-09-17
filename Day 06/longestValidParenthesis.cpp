#include <iostream>
#include <stack>
#include <string>
using namespace std;

int maxLength(string& str) {
    stack<int> s;
    s.push(-1);  // Base index for valid parentheses
    int maxLen = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(i);  // Push index of '('
        } else {
            s.pop();  // Pop the top
            if (!s.empty()) {
                maxLen = max(maxLen, i - s.top());
            } else {
                s.push(i);  // Base for next valid substring
            }
        }
    }
    return maxLen;
}

int main() {
    string str = ")()())";
    cout << maxLength(str) << endl;  // Output: 4
    return 0;
}
