import java.util.*;
import java.io.*;

public class rename {
    public static void main(String[] args) {
        File ogfile = new File("Kuctohai.txt");
        File newFile = new File("KuchnaiHai.txt");
        try {
            ogfile.createNewFile();

            if (ogfile.renameTo(newFile)) {
                System.out.println("Renamed");
            }else{
                System.out.println("No");
            }

            System.out.println(ogfile.delete());

        } catch (Exception e) {
            e.getStackTrace();
        }
    }


    
}
