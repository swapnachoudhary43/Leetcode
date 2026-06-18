class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute_angle = minutes * 6;
        double hour_angle = (hour % 12) * 30 + minutes * 0.5;
        
        double angle = abs(hour_angle - minute_angle);
        
        return min(angle, 360 - angle);

    }
};