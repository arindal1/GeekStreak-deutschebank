bool ispar(const std::string &x) {
    std::stack<char> s;
    for (char c : x) {
        if (c == '{' || c == '(' || c == '[') {
            s.push(c);
        }
        else {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if (c == '}' && top != '{') return false;
            if (c == ')' && top != '(') return false;
            if (c == ']' && top != '[') return false;
        }
    }
    return s.empty();
}
