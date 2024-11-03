////////////////////////////////////////////////
//                                            //
// Simple implementation of the KMP algorithm //
//                                            //
////////////////////////////////////////////////

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length())
            return false;

        string doubleString = s + s;

        return kmpSearch(doubleString, goal);
    }

private:
    bool kmpSearch(string& text, string& pattern) {

        vector<int> lps = computeLPS(pattern);
        int textIndex = 0, patternIndex = 0;
        int textLength = text.size(), patternLength = pattern.size();

        while (textIndex < textLength) {

            if (text[textIndex] == pattern[patternIndex]) {
                textIndex++;
                patternIndex++;

                // This means that we matched the whole pattern
                if (patternIndex == patternLength)
                    return true;
            }

            else if (patternIndex > 0) {
                patternIndex = lps[patternIndex - 1];
            }

            else {
                textIndex++;
            }
        }
        return false;
    }

    vector<int> computeLPS(string& pattern) {
        // Longest Prefix Suffix Array ?
        int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);
        int length = 0, index = 1;

        while (index < patternLength) {
            if (pattern[index] == pattern[length]) {
                length++;
                lps[index++] = length;
            } else if (length > 0) {
                length = lps[length - 1];
            } else {
                lps[index++] = 0;
            }
        }
        return lps;
    }
};