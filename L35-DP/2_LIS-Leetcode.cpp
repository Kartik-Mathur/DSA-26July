class Solution {
public:
	int solve(vector<int> &a) {
		vector<int> v;
		int n = a.size();
		for (int i = 0; i < n; ++i)
		{
			if (v.size() == 0 or a[i] > v.back()) {
				v.push_back(a[i]);
			}
			else {
				int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
				v[pos] = a[i];
			}
		}

		return v.size();
	}

	int lengthOfLIS(vector<int>& nums) {
		return solve(nums);
	}
};