import java.util.*;

public class Main{

     public static void main(String []args){
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for(int i = 1; i <= cases; i++){
            String fName = in.next();
            int rows = in.nextInt();
            int cols = in.nextInt();
            int[][] grid = new int[rows][cols];
            boolean[][] visited = new boolean[rows][cols];
            for(int r = 0; r < rows; r++) {
               for(int c = 0; c < cols; c++) {
                   grid[r][c] = in.nextInt();
               }
            }
			int lPath = 1;
			for(int r = 0; r < rows; r++) {
               for(int c = 0; c < cols; c++) {
                    if(!visited[r][c]) {
                       lPath = Math.max(lPath,dfs(grid,visited,r,c));
                   }
               }
            }
            System.out.println(fName + ": " + lPath);
        }
        System.out.println();
     }
     
     public static int dfs(int[][] grid,boolean[][] visited,int curR,int curC) {
         int max = 1;
         int lDepth = 0;
         if(isValid(grid,curR,curC)) {
             visited[curR][curC] = true;
             Pair[] adj = getAdj(grid,curR,curC);
             for(Pair p : adj) {
                 if(p == null) {
                     break;
                 } else if(grid[curR][curC] > grid[p.x][p.y]) {
                     lDepth = Math.max(lDepth,dfs(grid,visited,p.x,p.y));
                 }
             }
         }
         return (isValid(grid,curR,curC)) ? 1 + lDepth : 0;
     }
     
     public static boolean isValid(int[][] grid,int curR,int curC) {
         return curR >= 0 && curR < grid.length && curC >= 0 && curC < grid[curR].length;
     }
     
     public static Pair[] getAdj(int[][] grid,int curR,int curC) {
         int size = 0;
         Pair[] p = new Pair[4];
         if(isValid(grid,curR-1,curC)){
             p[size++] = new Pair(curR-1,curC);
         }
         if(isValid(grid,curR,curC+1)){
             p[size++] = new Pair(curR,curC+1);
         }
         if(isValid(grid,curR+1,curC)){
             p[size++] = new Pair(curR+1,curC);
         }
         if(isValid(grid,curR,curC-1)){
             p[size++] = new Pair(curR,curC-1);
         }
         return p;
     }
}

class Pair {
    int x;
    int y;
    
    public Pair(int x,int y) {
        this.x = x;
        this.y = y;
    }
}