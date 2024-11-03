#include <string>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {

        if (s.length() != goal.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s == goal) return true;
            std::rotate(s.begin(), s.begin()+1, s.end()); 
        }

        return false;        
    }
};