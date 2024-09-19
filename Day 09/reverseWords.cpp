vector<string> words;
    string word;
    stringstream ss(str);

    // Split the string by '.' and store words in the vector
    while (getline(ss, word, '.')) {
        words.push_back(word);
    }

    // Reverse the order of words and form the result string
    string result;
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) {
            result += '.';
        }
    }

    return result;