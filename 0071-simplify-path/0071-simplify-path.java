class Solution {
    public String simplifyPath(String path) {
        String[] dirs = path.split("/");
        
        List<String> canonical = new ArrayList<>();
        for (String dir : dirs) {
            if (dir.equals("..") && canonical.size() == 0) {
                continue;
            }

            if (canonical.size() > 0 && dir.equals("..")) {
                canonical.remove(canonical.size() - 1);
            } else if (!dir.isEmpty() && !dir.equals(".")) {
                canonical.add(dir);
            }

            for (String d : canonical) {
                System.out.print(d.toString() + " ");
            }
            System.out.println();
        }
        
        StringBuilder sb = new StringBuilder("/");
        for (String s : canonical) {
            sb.append(s);
            sb.append("/");
        }
        
        if (sb.length() > 1) {
            sb.deleteCharAt(sb.length() - 1);
        }
        
        return sb.toString();
    }
}