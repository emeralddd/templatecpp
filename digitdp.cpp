/*
Problem Statement
Find count of numbers in range [L, R] such that sum of its digits is a prime number.

1<=L,R<=10^18

dp[i][0][sum]→ count of suffixes that can be formed starting from index i, whose digits add up to sum

dp[i][1][sum]→ count of suffixes that can be formed starting from index i, whose digits add up to sum
such that the formed suffix is not greater than corresponding suffix in input string

Base Cases dp[n][0][0] = dp[n][1][0] = 1
There exists 1 empty suffix with sum of its digits =0
*/

int digit_dp(string ss) {
    int n = ss.size();

    //empty suffixes having sum=0
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;

    for(int i = n-1; i >=0 ; i--) {
        for(int tight = 0; tight < 2 ; tight++) {
            for(int sum = 0; sum < 200 ; sum++) {
                if(tight) {
                    for(int d = 0; d <= ss[i] - '0' ; d++) {
                        dp[i][1][sum] += (d == ss[i]-'0') ? dp[i+1][1][sum-d] : dp[i+1][0][sum-d];
                    }
                }
                else {
                    for(int d = 0; d < 10 ; d++) {
                        dp[i][0][sum] += dp[i+1][0][sum-d];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 200; i++) {
        if(isPrime(i))
        ans += dp[0][1][i];
    }
    return ans;
}
