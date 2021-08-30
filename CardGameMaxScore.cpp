// variant - which player wins card game :  stone game 3


public static int find(int[] cards) {
    if (cards == null || cards.length == 0) {
        return 0;
    }

    int sum = 0;
    int n = cards.length;
    int[] dp = new int[n+3];        // dp[i] means the max possible score the 1st player can get starting from index i
    for (int i = n-1; i>=0; i--) {
        sum += cards[i];        // sum is the post-sum
        int min = Integer.MAX_VALUE;
        for (int j=1; j<=3; j++) {
            if (dp[i+j] < min) {  // best strategy means we take the option that minimizes the max possible score for our opponent
                min = dp[i+j];
            }
        }
        dp[i] = sum - min;  // we then get (total - the minimized possible score for our opponent)
    }
    return dp[0];
}
