/ https://dmoj.ca/problem/ccc00j1
// 13-4-2017

import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
	    Scanner s = new Scanner(System.in);
	    int day = s.nextInt();
	    int num = s.nextInt();
	    int newLine = 7 - day + 1;
	    int count = 0;
	    boolean countOn = false;
	    System.out.println("Sun Mon Tue Wed Thr Fri Sat");
	    for(int i = 0; i < day; i++)
        {
            System.out.print("   ");
        }
        System.out.print(" ");
        for (int i = 1; i <= num; i++)
        {
            if (i == newLine)
            {
                System.out.println(i);
                if (i >= 9)
                    System.out.print(" ");
                else
                    System.out.print("  ");
                countOn = true;
                continue;
            }

            if (countOn)
                count++;

            if (count == 7)
            {
                System.out.println(i);
                if (i >= 9)
                    System.out.print(" ");
                else
                    System.out.print("  ");
                count = 0;
                continue;
            }

            if (i >= 9)
                System.out.print(i + "  ");
            else
                System.out.print(i + "   ");
        }
    }
}