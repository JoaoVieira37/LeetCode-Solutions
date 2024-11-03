#include <string>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {

        if (s.length() != goal.length()) {
            return false;
        }
        s.append(s);
        size_t len = goal.length();
        for (size_t i = 0; i < len; i++) {
            std::string new_str = s.substr(i, len);
            if (new_str == goal) return true;
        }
        return false;
    }

    bool rotateString2(std::string s, std::string goal) {
        
        if (s.length() != goal.length()) return false;

        std::string doubleString = s + s;

        return doubleString.find(goal) < doubleString.length();
    }
};