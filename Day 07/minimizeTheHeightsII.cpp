#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int>& arr, int k) {
    int n = arr.size();
    
    // If there is only one tower, no difference can exist
    if (n == 1)
        return 0;

    // Sort the array to process in an ordered manner
    sort(arr.begin(), arr.end());

    // Initial difference without any changes
    int ans = arr[n - 1] - arr[0];

    // The smallest and largest after considering adding/subtracting k
    int smallest, largest;

    // Update the heights of the first and last towers
    for (int i = 1; i < n; i++) {
        // Ignore cases where the subtraction results in negative values
        if (arr[i] - k < 0)
            continue;

        // Calculate the new smallest and largest heights after adding/subtracting k
        smallest = min(arr[0] + k, arr[i] - k);
        largest = max(arr[n - 1] - k, arr[i - 1] + k);

        // Update the minimum difference
        ans = min(ans, largest - smallest);
    }

    return ans;
}

int main() {
    // Example usage:
    vector<int> arr = {380, 705, 706, 177, 710, 416, 853, 147, 957, 693}; // Add full input array
    int k = 494;
    cout << getMinDiff(arr, k) << endl;  // Expected output: 973
    return 0;
}
