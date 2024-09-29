int totalCount(int k, const vector<int>& arr) {
    int total = 0;
    for (int num : arr)
        total += (num + k - 1) / k;
    return total;
}