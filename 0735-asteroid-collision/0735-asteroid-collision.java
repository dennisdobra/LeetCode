class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        List<Integer> stack = new ArrayList<>();

        for (int asteroid : asteroids) {
            // first asteroid
            if (stack.isEmpty()) {
                stack.add(asteroid);
                continue;
            }

            // asteroids which never meet
            if ((asteroid > 0 && stack.getLast() > 0) || (asteroid < 0 && stack.getLast() < 0) ||
                stack.getLast() < 0 && asteroid > 0) {
                stack.add(asteroid);
                continue;
            }

            // asteroid collision
            while (!stack.isEmpty() && stack.getLast() > 0 && stack.getLast() < Math.abs(asteroid)) {
                stack.remove(stack.size() - 1);
                continue;
            }

            // asteroid collision - both explode
            if (!stack.isEmpty() && stack.getLast() == Math.abs(asteroid)) {
                stack.remove(stack.size() - 1);
                continue;
            }

            if (stack.isEmpty() || !stack.isEmpty() && stack.getLast() < 0) {
                stack.add(asteroid);
            }
            
        }

        int[] arr = new int[stack.size()];
        for (int i = 0; i < stack.size(); i++) {
            arr[i] = stack.get(i);
        }

        return arr;
    }
}