import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        double N, M, answer;
        answer = 0;
        M = read.nextDouble();
        N = read.nextDouble();
        ArrayList<Double> safes = new ArrayList<>((int) N);
        double avg = M;
        // Calculate average
        for (int i = 0; i < N; i++) {
            safes.add(read.nextDouble());
            avg += safes.get(i);
        }
        // Calculate rich-poor gap
        double max = M - (avg / (N + 1));
        // Sort arraylist
        Collections.sort(safes);

        // pop back max elements
        while (!safes.isEmpty()) {
            avg -= safes.get(safes.size() - 1);
            safes.remove(safes.size() - 1);

            // Check if it's empty again!
            // Calculate rich poor gap again
            if (!safes.isEmpty() && (M - (avg / (safes.size() + 1)) > max)) {
                max = M - (avg / (safes.size() + 1));
                answer = N - safes.size();
            }

        }

        System.out.println((int)answer);
    }
}