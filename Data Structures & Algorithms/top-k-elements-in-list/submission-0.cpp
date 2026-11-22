class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());


        int *values  = new int[n]{};
        int *lengths = new int[n]{};
        int runs = 0;

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == nums[i]) {
                j++;                     
            }
            values[runs]  = nums[i];
            lengths[runs] = j - i;      
            runs++;
            i = j;                       
        }

        vector<int> result;
        for (int pick = 0; pick < k; pick++) {
            int best = 0;
            for (int r = 1; r < runs; r++) {
                if (lengths[r] > lengths[best]) {
                    best = r;
                }
            }
            result.push_back(values[best]);
            lengths[best] = 0;           
        }

        delete[] values;
        delete[] lengths;
        return result;
    }
};