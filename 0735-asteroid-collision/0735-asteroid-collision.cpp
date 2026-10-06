class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survivors;

        for (int asteroid : asteroids) {
            bool alive = true;

            while (alive && asteroid < 0 && !survivors.empty() && survivors.back() > 0) {
                if (survivors.back() < abs(asteroid)) {
                    survivors.pop_back();
                }
                else if (survivors.back() == abs(asteroid)) {
                    survivors.pop_back();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }

            if (alive) {
                survivors.push_back(asteroid);
            }
        }

        return survivors;
    }
};