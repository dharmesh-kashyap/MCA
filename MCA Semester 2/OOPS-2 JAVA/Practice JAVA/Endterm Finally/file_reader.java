import java.io.*;
import java.util.*;
public class file_reader {
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
            FileReader reader = new FileReader(newFile);
            int k = 0;
            int l = 0;
            while((k = reader.read()) != -1){
                char s = ((char)k);
                arr[l] = Character.toString(s) ;
                l++;
            }
            reader.close();
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
