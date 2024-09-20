int countBuildings(vector<int> &height) {
    int count = 1; // The first building can always see the sunrise
    int max_height = height[0]; // The first building's height
    
    // Traverse the array from the second building onwards
    for(int i = 1; i < height.size(); i++) {
        if(height[i] > max_height) {
            count++; // This building can see the sunrise
            max_height = height[i]; // Update the maximum height seen so far
        }
    }
    
    return count;
}
