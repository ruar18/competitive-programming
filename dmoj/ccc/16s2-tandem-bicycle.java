/*
 * CCC '16 S2 - Tandem Bicycle
 * https://dmoj.ca/problem/ccc16s2
 * Greedy algorithms
 */


import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        // Type of question we're asked to solve:
        // 1 to find minimum total speed
        // 2 to find maximum total speed
        int type = read.nextInt();
        // Number of citizens from each country
        int N = read.nextInt();
        int ans = 0;
        // Speeds of dmoj citizens and peg citizens
        ArrayList<Integer> dmoj = new ArrayList<>(N);
        ArrayList<Integer> peg = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            dmoj.add(read.nextInt());
        }
        for (int i = 0; i < N; i++) {
            peg.add(read.nextInt());
        }

        // Sort dmoj ascending
        Collections.sort(dmoj);
        // Sort peg descending
        Collections.sort(peg, Collections.reverseOrder());

        for (int i = 0; i < N; i++) {
            if(type == 1)
                ans += Math.max(dmoj.get(i), peg.get(N - 1 - i));
            else
                ans += Math.max(dmoj.get(i), peg.get(i));
        }

        System.out.println(ans);
    }
}