import java.util.*;
import java.io.*;
public class filehandling{
    public static void main(String[] args) {
        String filename = "myfile.txt";
        File myfile = new File("newfile.txt");
        
        try {
            //myfile.createNewFile();
            FileWriter fileWriter = new FileWriter(filename);
            fileWriter.write("This is our first file content\nOkay now bye");
            fileWriter.close();
            Scanner sc = new Scanner(myfile);
            while(sc.hasNextLine()){
                String line = sc.nextLine();
                System.out.println(line);
            }
            sc.close();
        } catch (IOException e) {
            System.out.println("Unabble to create file");
            e.printStackTrace();
        }
        if (myfile.delete()) {
            System.out.println("deleted");
        }
        else{
            System.out.println("Not deleted");
        }

    }

}