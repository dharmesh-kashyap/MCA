import java.util.Scanner;
public class SpeedConvert {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean cond = true;
        do{
            float temp1, temp2;
            float kmph;
            float mps;
            System.out.println("\n--------Menu-------");
            System.out.println("1. Kilometer per hour to Meter per second");
            System.out.println("2. Meter per second to kilometer per hour\n3. Exit ");

            int choice;
            choice = sc.nextInt();
            switch(choice){
                case 1:
                    System.out.print("\nEnter the Speed in Kilometer per Hour: ");
                    kmph = sc.nextFloat();
                    temp1 = kmph*3.6f ;
                    System.out.print("\nSpeed in Meter per second: " + temp1);
                    break;

                case 2:
                    System.out.print("\nEnter the Speed in Meter per Second: ");
                    mps = sc.nextFloat();
                    temp2 = mps/3.6f ;
                    System.out.print("\nSpeed in kilometer per Hour: " + temp2);
                    break;


                case 3:
                    System.out.println("\nGetting out");
                    cond = false;
            }


        }while(cond == true);
    }
}
