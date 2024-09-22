int lps(string str) {
    int n = str.length();
    vector<int> lpsArray(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (str[i] == str[len]) {
            len++;
            lpsArray[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lpsArray[len - 1];
            } else {
                lpsArray[i] = 0;
                i++;
            }
        }
    }
    return lpsArray[n - 1];
}