import java.io.*;
import java.util.*;
public class file_rscanner {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of string you want to input");
        int n = sc.nextInt();
        String arr[] = new String[n];

        File newFile = new  File("filename.txt");

        try{
            newFile.createNewFile();
            FileWriter writer = new FileWriter(newFile);
            for (int i = 0; i < n; i++) {
                writer.write(sc.next() + "\n");
            }
            writer.close();
            Scanner scan = new Scanner(newFile);
            int k = 0;
            while(scan.hasNextLine()){
                arr[k] = scan.nextLine();
                k++;
            }
            scan.close();
            for(String string : arr ){
                System.out.println(string);
            }
        }
        catch(Exception e){
            e.printStackTrace();
        }

        sc.close();
        
    }
}
