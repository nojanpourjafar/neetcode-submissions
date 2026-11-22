class Solution {
public:
    bool isValid(string s) {
        char stack[1000]{};   // s has at most 1000 chars, so this is big enough
        int top = 0;          // how many brackets are on the stack

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{') {
                // Opening bracket: push it
                stack[top] = c;
                top++;
            } else {
                // Closing bracket with nothing to match
                if (top == 0) {
                    return false;
                }

                // Top of the stack isn't the matching opener
                char open = stack[top - 1];
                if ((c == ')' && open != '(') ||
                    (c == ']' && open != '[') ||
                    (c == '}' && open != '{')) {
                    return false;
                }

                // It matched: pop
                top--;
            }
        }

        // Valid only if every opener was closed
        return top == 0;
    }
};