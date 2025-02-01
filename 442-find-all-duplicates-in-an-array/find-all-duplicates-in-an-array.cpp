class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates; // To store the result

        // Iterate over each element in the array
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; // Calculate the index

            // Check the value at the calculated index
            if (nums[index] < 0) {
                // If negative, the number has been seen before
                duplicates.push_back(index + 1);
            } else {
                // Negate the value to mark it as seen
                nums[index] = -nums[index];
            }
        }
        return duplicates;
    }
};