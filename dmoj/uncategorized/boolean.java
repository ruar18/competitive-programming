import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
	    Scanner s = new Scanner(System.in);
	    String val = s.next();
	    int count = 0;
	    int result = 0;
	    while(val.equals("not"))
        {
            count++;
            val = s.next();
        }
        if (val.equals("True")){
	        if (count % 2 == 0)
	            System.out.println("True");
	        else
	            System.out.println("False");
        }
        else
        {
            if (count % 2 == 0)
                System.out.println("False");
            else
                System.out.println("True");
        }
        return;
    }
}