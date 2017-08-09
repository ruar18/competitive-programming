import java.util.HashMap;

public class Main {

    // Recursive, naive solution
    private static int countRoutes(int r, int c)
    {
        if (r == 0 || c == 0)
            return 1;
        return countRoutes(r-1, c) + countRoutes(r, c-1);
    }

    static HashMap cache = new HashMap();
    // Recursive solution with memoization
    // Fast
    private static int countMemoRoutes(int r, int c){
        if(r == 0 || c == 0)
            return 1;
        String cacheKey = "" + r + " " + c;
        if(cache.containsKey(cacheKey))
            return (int)cache.get(cacheKey);
        cache.put(cacheKey, countMemoRoutes(r-1,c) + countMemoRoutes(r, c-1));
        return (int)cache.get(cacheKey);
    }


    private static long dp(int r, int c)
    {
        long[][] grid = new long[r+1][c+1];
        for(int i = 0; i <= r; i++)
            grid[i][0] = 1;
        for(int j = 0; j <= c; j++)
            grid[0][j] = 1;

        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++)
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
        return grid[r][c];
    }
    public static void main(String[] args) {
        System.out.println(dp(30,30));
    }
}
