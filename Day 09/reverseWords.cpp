string reverseWords(string str) {
    vector<string> words;
    string word;
    stringstream ss(str);

    while (getline(ss, word, '.')) {
        words.push_back(word);
    }
    string result;
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) {
            result += '.';
        }
    }
    return result;
}