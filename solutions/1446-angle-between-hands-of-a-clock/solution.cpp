class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_angle = (360.0 * (double)minutes) / 60.0;
        double hour_angle = ((360.0 * (double)hour) / 12.0) + (((double)minutes * 30.0) / 60.0);

        return min(max(hour_angle,min_angle) - min(hour_angle,min_angle), 360 - max(hour_angle,min_angle) + min(hour_angle,min_angle));
    }
};
