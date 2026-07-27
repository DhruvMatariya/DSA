class Solution {
public:
    bool isPal(int x) {
    string s = "";

    while (x) {
        s += (x & 1) + '0';
        x >>= 1;
    }

    string t = s;
    reverse(t.begin(), t.end());

    return s == t;
}
    vector<int> minOperations(vector<int>& nums) {
        vector<int> pal;
        vector<int>ans;

for (int i = 1; i <= 5000; i++) {
    if (isPal(i))
        pal.push_back(i);
}
for (int x : nums) {

    int idx = lower_bound(pal.begin(), pal.end(), x) - pal.begin();

    if (idx == 0)
        ans.push_back(pal[0] - x);

    else if (idx == pal.size())
        ans.push_back(x - pal.back());

    else
        ans.push_back(min(x - pal[idx - 1],
                          pal[idx] - x));
}
return ans;
    }
};