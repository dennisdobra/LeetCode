class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for (int num : asteroids) {
            if (stack.empty()) {
                stack.push_back(num);
                continue;
            }

            if (num < 0 && stack.back() < 0) {
                // only asteroids going left so far => can't colide
                stack.push_back(num);
                continue;
            }

            if (num > 0) {
                stack.push_back(num);
            } else {
                // both explode
                if (stack.back() - abs(num) == 0) {
                    stack.pop_back();
                    continue;
                }

                // the one going left is bigger
                while (!stack.empty() && abs(num) > abs(stack.back()) && stack.back() > 0) {
                    stack.pop_back();
                }
                
                if (!stack.empty() && abs(num) >= stack.back()) {
                    if (abs(num) - stack.back() == 0) {
                        stack.pop_back();
                        continue;
                    } 
                    
                    stack.push_back(num);
                }

                if (stack.empty()) {
                    stack.push_back(num);
                }
            }
        }

        return stack;
    }
};