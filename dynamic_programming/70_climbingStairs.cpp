class Solution {
public:
    // map<int, int> memory;

    // int climbStairs(int n) {
    //     /*
    //         Top down approach
    //     */
    //     if (n <= 2) {
    //         return (n);
    //     }
    //     else if (memory[n] == 0) {
    //         memory[n] = climbStairs(n - 1) + climbStairs(n - 2);
    //     }

    //     return (memory[n]);
    // }

    int climbStairs(int n) {
        /*
            Bottom up approach
        */
        if (n <= 2)
            return (n);

        int result;

        int dp[2] = {0, 1};

        while (n != 0) {
            result = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = result;
            n--;
        }

        return (dp[1]);
    }


};