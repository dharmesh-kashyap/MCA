import java.util.*;
import java.io.*;
public class StringSorting{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String filename1 = "file1.txt";
        //String filename2 = "file2.txt";
        File myfile = new File(filename1);
        System.out.println("Enter the number of strings to be entered: ");
        int n = sc.nextInt();

        try {

            myfile.createNewFile();
            FileWriter fileWriter = new FileWriter(myfile);
            System.out.println("Enter the strings : ");
            for (int i = 0; i < n; i++) {
                String S = sc.next();
                fileWriter.write(S + "\n");
            }
            fileWriter.close();
            Scanner filescan = new Scanner (myfile);
            System.out.println("\nThe strings that you've entered : ");
            while (filescan.hasNextLine()) {
                String line = filescan.nextLine();
                System.out.println(line); 
            }    
        filescan.close();
        } catch (Exception e) {
            System.out.println("File not created");
            System.out.println(e);
        }

        sc.close();
    }
}