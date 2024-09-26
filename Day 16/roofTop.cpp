int maxStep(vector<int>& arr) {
    int max_steps = 0, current_steps = 0;
    for (int i = 1; i < arr.size(); i++) {
        current_steps = (arr[i] > arr[i - 1]) ? current_steps + 1 : 0;
        max_steps = max(max_steps, current_steps);
    }
    return max_steps;
}