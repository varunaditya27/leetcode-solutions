class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        vector<pair<int,int>> diff;
        vector<int> res;

        for (int i = 0; i < len; i++) {
            diff.push_back({abs(x - arr[i]), arr[i]});
        }

        sort(diff.begin(), diff.end());

        for (int i = 0; i < k; i++) {
            res.push_back(diff[i].second);
        }

        sort(res.begin(), res.end());

        return res;
    }
};
