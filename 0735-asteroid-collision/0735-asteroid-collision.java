class Solution {
    public int[] asteroidCollision_(int[] asteroids) {
        Deque<Integer> stack = new ArrayDeque<>();

        for (int asteroid : asteroids) {
            // first asteroid
            if (stack.isEmpty()) {
                stack.push(asteroid);
                continue;
            }

            // asteroids which never meet
            if (asteroid > 0 && stack.peek() > 0 || asteroid < 0 && stack.peek() < 0 || asteroid > 0 && stack.peek() < 0) {
                stack.push(asteroid);
                continue;
            }

            // current asteroid destroys previous asteroids
            while (!stack.isEmpty() && stack.peek() > 0 && Math.abs(asteroid) > stack.peek()) {
                stack.pop();
            }

            // both asteroids explode
            if (!stack.isEmpty() && Math.abs(asteroid) == stack.peek()) {
                stack.pop();
                continue;
            }

            // check if the current asteroid survived all collisions
            if (stack.isEmpty() || !stack.isEmpty() && stack.peek() < 0) {
                stack.push(asteroid);
            }
        }

        int[] result = new int[stack.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stack.pop();
        }

        return result;
    }

    public int[] asteroidCollision(int[] asteroids) {
        Deque<Integer> stack = new ArrayDeque<>();

        for (int asteroid : asteroids) {
            boolean alive = true;

            // current asteroid goes left && prev asteroid goes right => collision
            while (alive && asteroid < 0 && !stack.isEmpty() && stack.peek() > 0) {
                int prevMass = stack.peek();

                // the current asteroid stays alive if its mass is greater
                // than the mass of the previous asteroid
                alive = prevMass < -asteroid;

                if (prevMass <= -asteroid) {
                    stack.pop();
                }
            }

            if (alive) {
                stack.push(asteroid);
            }
        }

        int[] result = new int[stack.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stack.pop();
        }
        return result;
    }
}