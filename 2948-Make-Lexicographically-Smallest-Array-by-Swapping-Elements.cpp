class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({nums[i], i});
        }
        sort(p.begin(), p.end());
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n &&
                   p[j + 1].first - p[j].first <= limit) {
                j++;
            }
            vector<int> values;
            vector<int> indices;
            for (int k = i; k <= j; k++) {
                values.push_back(p[k].first);
                indices.push_back(p[k].second);
            }
            sort(indices.begin(), indices.end());
            for (int k = 0; k < values.size(); k++) {
                nums[indices[k]] = values[k];
            }
            i = j + 1;
        }
        return nums;
    }
};