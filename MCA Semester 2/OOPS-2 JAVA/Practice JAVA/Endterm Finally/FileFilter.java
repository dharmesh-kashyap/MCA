//import java.util.*;
import java.io.*;

class exte implements FilenameFilter {
    String extension;
    public exte(String extension){
        this.extension = "." + extension;
    }
    public boolean accept(File dir, String name){
        return name.endsWith(extension);
    }
};
public class FileFilter {
    public static void main(String[] args) {
        String Dirname = "C:\\Users\\dharm\\Desktop\\New GIT update\\MCA\\MCA Semester 2\\OOPS-2 JAVA\\Practice JAVA\\Endterm Finally";
        File dir = new File(Dirname);
        FilenameFilter only = new exte("txt");
        String[] s1 = dir.list(only);

        for (String string : s1) {
            System.out.println(string);
        }
    }
}
