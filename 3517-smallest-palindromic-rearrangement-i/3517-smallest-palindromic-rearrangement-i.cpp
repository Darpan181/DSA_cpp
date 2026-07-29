class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(256, 0);
        for (char c : s)
            freq[c]++;

        string firstHalf = "";
        string middle = "";

        for (int i = 0; i < 256; i++) {
            firstHalf.append(freq[i] / 2, char(i));

            if (freq[i] % 2 == 1)
                middle = char(i);
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + middle + secondHalf;
    }
};