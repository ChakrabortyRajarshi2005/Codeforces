Pashmak and Flowers
time limit per test1 second
memory limit per test256 megabytes
Pashmak decided to give Parmida a pair of flowers from the garden. There are n flowers in the garden and the i-th of them has a beauty number bi. Parmida is a very strange girl so she doesn't want to have the two most beautiful flowers necessarily. She wants to have those pairs of flowers that their beauty difference is maximal possible!

Your task is to write a program which calculates two things:

The maximum beauty difference of flowers that Pashmak can give to Parmida.
The number of ways that Pashmak can pick the flowers. Two ways are considered different if and only if there is at least one flower that is chosen in the first way and not chosen in the second way.
Input
The first line of the input contains n (2 ≤ n ≤ 2·105). In the next line there are n space-separated integers b1, b2, ..., bn (1 ≤ bi ≤ 109).

Output
The only line of output should contain two integers. The maximum beauty difference and the number of ways this may happen, respectively.

Examples
InputCopy
2
1 2
OutputCopy
1 1
InputCopy
3
1 4 5
OutputCopy
4 1
InputCopy
5
3 1 2 3 1
OutputCopy
2 4
Note
In the third sample the maximum beauty difference is 2 and there are 4 ways to do this:

choosing the first and the second flowers;
choosing the first and the fifth flowers;
choosing the fourth and the second flowers;
choosing the fourth and the fifth flowers.



import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] b = new long[n];
        
        // Read beauty values
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextLong();
        }
        
        // Find max and min beauty
        long maxBeauty = b[0], minBeauty = b[0];
        for (int i = 1; i < n; i++) {
            if (b[i] > maxBeauty) maxBeauty = b[i];
            if (b[i] < minBeauty) minBeauty = b[i];
        }
        
        // Count flowers with max and min beauty
        long maxCount = 0, minCount = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == maxBeauty) maxCount++;
            if (b[i] == minBeauty) minCount++;
        }
        
        // Calculate max difference
        long maxDiff = maxBeauty - minBeauty;
        
        // Calculate number of ways
        long ways;
        if (maxBeauty == minBeauty) {
            // If all flowers have same beauty, choose any 2
            ways = (maxCount * (maxCount - 1)) / 2;
        } else {
            // Number of pairs = (count of max) * (count of min)
            ways = maxCount * minCount;
        }
        
        // Output result
        System.out.println(maxDiff + " " + ways);
        
        scanner.close();
    }
}
