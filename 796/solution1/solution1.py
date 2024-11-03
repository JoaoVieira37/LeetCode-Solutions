class Solution:
    def rotateString(self, s: str, goal: str) -> bool:

        if len(s) != len(goal):
            return False

        if len(s) >= 1 and len(goal) <= 100:
            
            new_str = s[1:] + s[0]
            while new_str != s:
                if new_str == goal:
                    return True
                new_str = new_str[1:] + new_str[0]

        return False
        