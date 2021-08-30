// variant - which player wins card game :  stone game 3



// Two players are playing a card game where the deck of cards are layed out in a straight line and each card value is visible to both the players.
// The value of each card can range from a reasonable [-ve to +ve] number and the length of deck in n.

// The rules of the game are such:

// Player 1 starts the game
// Each player has 3 option:
// (Option 1: Pick 1st card)
// (Option 2: Pick 1st two cards)
// (Option 3: Pick 1st three cards)
// You're only allowed to pick cards from the left side of the deck
// Both players have to play optimally.
// Return the maximum sum of cards Player 1 can obtain by playing optimally.


// O(n) and O(n)    
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


// O(n) and O(1)

//Call your score x, opponent's score y. At the end of the minimax algorithm, you have maximized x-y. Notice the sum of the entire array is x+y. Final line is (x-y+x+y)/2 = x.
//Very clever, most other solutions here return x-y, not x as the problem statement asks for

private int getMaxHeap(int[] nums){
        int sum = 0, n = nums.length;
        for(int num: nums){
            sum += num;
        }
        int[] dp = new int[4];
        for(int i = n - 1; i >= 0 ; i--){
            int cnt = 0, max = Integer.MIN_VALUE;
            for(int j = i, len = 0; j < n && len < 3; j++, len++){
                cnt += nums[j];
                max = Math.max(max, cnt - dp[len]);
            }
            for(int j = 3; j > 0; j--){
                dp[j] = dp[j-1];
            }
            dp[0] = max;
        }
        return (dp[0] + sum) / 2;
    }
