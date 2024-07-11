class Solution {
public:
    static bool sortsec(const pair<int, int> &a, const pair<int, int> &b) {
        return (a.second < b.second);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp(nums.size());
        for (int i=0; i<nums.size(); i++) {
            temp[i] = {i, nums[i]};
        }
        sort(temp.begin(), temp.end(), sortsec);
        int l=0;
        int r=nums.size()-1;
        int sum;
        while (l<r) {
            sum = temp[l].second+temp[r].second;
            if (sum == target) {
                return {temp[l].first, temp[r].first};
            } else if (sum > target) {
                r-=1;
            } else {
                l+=1;
            }
        }
        return {};
    }
};