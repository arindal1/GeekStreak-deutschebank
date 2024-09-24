string smallestWindow(string s, string p) {
    if (s.size() < p.size()) return "-1";

    vector<int> pMap(128, 0);
    for (char c : p) {
        pMap[c]++;
    }
    int start = 0, minLength = INT_MAX, minStart = 0;
    int required = p.size();
    int formed = 0;
    vector<int> windowMap(128, 0);

    for (int end = 0; end < s.size(); end++) {
        char c = s[end];
        windowMap[c]++;
        if (pMap[c] > 0 && windowMap[c] <= pMap[c]) {
            formed++;
        }
        while (formed == required) {
            if (end - start + 1 < minLength) {
                minLength = end - start + 1;
                minStart = start;
            }

            char leftChar = s[start];
            windowMap[leftChar]--;
            if (pMap[leftChar] > 0 && windowMap[leftChar] < pMap[leftChar]) {
                formed--;
            }
            start++;
        }
    }

    return minLength == INT_MAX ? "-1" : s.substr(minStart, minLength);
}