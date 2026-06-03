class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landCount = landDuration.size();
        int waterCount = waterDuration.size();

        int option1, option2;

        int firstLandEnd = INT_MAX;
        for (int i = 0; i < landCount; i++) {
            firstLandEnd = min(firstLandEnd, landStartTime[i] + landDuration[i]);
        }
        int secondWaterEnd = INT_MAX;
        for (int i = 0; i < waterCount; i++) {
            secondWaterEnd = min(secondWaterEnd, max(firstLandEnd, waterStartTime[i]) + waterDuration[i]);
        }
        option1 = secondWaterEnd;

        int firstWaterEnd = INT_MAX;
        for (int i = 0; i < waterCount; i++) {
            firstWaterEnd = min(firstWaterEnd, waterStartTime[i] + waterDuration[i]);
        }
        int secondLandEnd = INT_MAX;
        for (int i = 0; i < landCount; i++) {
            secondLandEnd = min(secondLandEnd, max(firstWaterEnd, landStartTime[i]) + landDuration[i]);
        }
        option2 = secondLandEnd;

        return min(option1, option2);
    }
};
