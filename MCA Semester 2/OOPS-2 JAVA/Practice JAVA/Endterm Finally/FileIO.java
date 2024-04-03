import java.util.*;
import java.io.*;
public class FileIO {
    public static void main(String[] args)  {
        Scanner sc = new Scanner (System.in);
        System.out.println();
        //String Filename = sc.next();
        File myfile = new File("C:\\Users\\dharm\\Desktop\\New GIT update\\MCA\\MCA Semester 2\\OOPS-2 JAVA\\Practice JAVA\\Endterm Finally", "practice.txt");
        try {
            //myfile.createNewFile();
            FileWriter writer = new FileWriter(myfile);
            for (int i = 0; i < 3; i++) {
                writer.write(sc.next() + "\n"); 
            }
            //writer.write("oogabooga");
            writer.close();
            System.out.println(myfile.getName());
            System.out.println(myfile.getParent());
            System.out.println(myfile.getPath());
            System.out.println(myfile.getAbsolutePath());
            System.out.println(myfile.length());
       } catch (Exception e) {
          e.printStackTrace();
       }
        sc.close();
    }
}