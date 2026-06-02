class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_len = landStartTime.size();
        int water_len = waterStartTime.size();
        int res = INT_MAX;

        for (int i = 0 ; i < land_len; i++) {
            for (int j = 0 ; j < water_len; j++) {
                int option1 = landStartTime[i] + landDuration[i];
                int option2 = waterStartTime[j] + waterDuration[j];

                if (option1 >= waterStartTime[j]) option1 += waterDuration[j];
                else option1 = waterStartTime[j] + waterDuration[j];

                if (option2 >= landStartTime[i]) option2 += landDuration[i];
                else option2 = landStartTime[i] + landDuration[i];

                res = min(res, min(option1, option2));
            }
        }

        return res;
    }
};
