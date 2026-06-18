class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double hr = hour * 30 + minutes * 0.5;
        double minu = minutes * 6 ;

        double ans = min(abs(hr - minu), 360 - (abs(hr-minu)));
        return ans;
    }
};