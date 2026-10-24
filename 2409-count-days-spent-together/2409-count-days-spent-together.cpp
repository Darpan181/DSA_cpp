class Solution {
public:
    int calculateDayOfYear(string str, vector<int> &daysBefore){
        int month = stoi(str.substr(0 , 2));
        int day = stoi(str.substr(3 , 2));

        return daysBefore[month - 1] + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysBefore = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        int arriveAliceDay = calculateDayOfYear(arriveAlice , daysBefore);
        int leaveAliceDay = calculateDayOfYear(leaveAlice , daysBefore);
        int arriveBobDay = calculateDayOfYear(arriveBob , daysBefore);
        int leaveBobDay = calculateDayOfYear(leaveBob , daysBefore);

        return max(0 , min(leaveAliceDay , leaveBobDay) - max(arriveAliceDay , arriveBobDay) + 1);
    }
};