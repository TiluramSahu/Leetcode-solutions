class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Step 1: Find the candidate using Moore's Voting Algorithm
    int candidate = 0, count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Step 2: Verify if the candidate is the majority element
    int frequency = 0;
    for (int num : nums) {
        if (num == candidate) {
            frequency++;
        }
    }

    if (frequency > nums.size() / 2) {
        return candidate;
    } else {
        return -1;
    }
    }
};