import java.math.BigInteger;
import java.util.Scanner;

public class StirlingNumberOne {
    public static void main(String[] args) {
        // 제 1 스털링 수.
        // S(r, n) = S(r - 1, n - 1) + (r - 1) * S(r - 1, n);
        BigInteger[][] dp = new BigInteger[201][201];
        BigInteger zero = new BigInteger("0");
        BigInteger one = new BigInteger("1");
        for (int j = 0; j <= 200; j++) {
            for (int i = 0; i <= 200; i++) {
                dp[j][i] = zero;
            }
        }
        dp[0][0] = one;
        for (int i = 1; i <= 200; i++) {
            for (int j = 1; j <= 200; j++) {
                BigInteger tmp = new BigInteger("" + (i - 1));
                tmp = tmp.multiply(dp[i - 1][j]);
                dp[i][j] = dp[i - 1][j - 1].add(tmp);
            }
        }
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(dp[a][b]);
        sc.close();
    }
}