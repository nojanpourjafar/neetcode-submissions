class Solution {
public:
    bool isPalindrome(string s) {
        std::string front;
        std::string back;

        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                front += tolower(s[i]);
            }
        }

        for (int j = s.length() - 1; j >= 0; j--) {
            if (isalnum(s[j])) {
                back += tolower(s[j]);
            }
        }

        return front == back;
    }
};