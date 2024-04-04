import java.util.*;
import java.io.*;
public class FileIOFunction {
    public static void main(String[] args)  {
        Scanner sc = new Scanner (System.in);
        System.out.println();
        //String Filename = sc.next();
        File dir = new File("doremon");
        File myfile = new File("C:\\Users\\dharm\\Desktop\\New GIT update\\MCA\\MCA Semester 2\\OOPS-2 JAVA\\Practice JAVA\\Endterm Finally");
        File myfile2 = new File(myfile, "oonooga.txt");
        try {
            //myfile.createNewFile();
            FileWriter writer = new FileWriter(myfile2);
            // for (int i = 0; i < 3; i++) {
            //     writer.write(sc.next() + "\n"); 
            // }
            writer.write("oogabooga");
            writer.close();
            System.out.println(myfile2.getName());
            System.out.println(myfile2.getParent());
            System.out.println(myfile2.getPath());
            System.out.println(myfile2.getAbsolutePath());
            System.out.println(myfile2.length());
            System.out.println(myfile2.isFile());
            System.out.println(myfile.isDirectory());
            dir.mkdir();

            File newFile = new File("haat.txt");

            newFile.createNewFile();

           if( myfile2.renameTo(newFile)){
            System.out.println("renamed");
           }else {
            System.out.println("nope");
           }


       } catch (Exception e) {
          e.printStackTrace();
       }
        sc.close();
    }
}