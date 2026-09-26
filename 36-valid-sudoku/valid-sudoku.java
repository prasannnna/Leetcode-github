class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String>row = new HashSet<>();
        Set<String>col = new HashSet<>();
        Set<String>grid = new HashSet<>();
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[i].length; j++) {
                char ch = board[i][j];
                if(ch == '.') continue;
                int k = (i / 3) * 3 + (j / 3);
                String r = ch + " " + i;
                String c = ch + " " + j;
                String g = ch + " " + k;
                if(row.contains(r) || col.contains(c) || grid.contains(g)) {
                    return false;
                }
                row.add(r);
                col.add(c);
                grid.add(g);
            }
        }
        return true;
    }
}