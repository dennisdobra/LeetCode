class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long planetmass = mass;
        for (int asteroid : asteroids) {
            if (asteroid > planetmass) return false;

            planetmass += asteroid;
        }

        return true;
    }
};