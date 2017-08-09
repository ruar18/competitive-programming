/* https://dmoj.ca/problem/ccc02j2
 * 13-4-2017
 */

import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String word = s.next();
        while (!word.equals("quit!"))
        {
            if (word.indexOf("or") > 0 && word.indexOf("or") == word.length() - 2 && word.length() > 4)
            {
                int pos = word.indexOf("or");
                char before = word.charAt(pos -1 );
                if (!(before == 'e' || before == 'u' || before == 'i' || before == 'a' || before == 'o'))
                    System.out.println(word.substring(0, pos+1) + 'u' + word.substring(word.length()-1, word.length()));
                else
                    System.out.println(word);

            }
            else
                System.out.println(word);
            word = s.next();
        }
    }
}