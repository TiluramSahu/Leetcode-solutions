#include <iostream>
#include <vector>
#include <algorithm> // For sorting

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end()); // Step 1: Sort the array
        
        std::vector<int> occurrences; // Array to store the occurrences of each unique element
        int i = 0;
        int n = arr.size();
        
        // Step 2: Count occurrences of each unique number
        while (i < n) {
            int count = 1; // At least 1 occurrence of the current element
            
            // Count occurrences of arr[i]
            while (i + 1 < n && arr[i] == arr[i + 1]) {
                count++;
                i++;
            }
            
            occurrences.push_back(count); // Store the count
            i++; // Move to the next unique element
        }

        // Step 3: Sort the occurrences array
        std::sort(occurrences.begin(), occurrences.end());

        // Step 4: Check for duplicate occurrences
        for (int j = 1; j < occurrences.size(); j++) {
            if (occurrences[j] == occurrences[j - 1]) {
                return false; // Duplicate frequency found
            }
        }

        return true; // All occurrences are unique
    }
};
