import java.io.*;
import java.util.*;
class Extractor implements FilenameFilter {
    String extension;

    public Extractor(String extension){
        this.extension = "." +  extension;
    }

    public boolean accept(File dir, String name){
        return name.endsWith(extension);
    }
};
public class sample {
    public static void main(String[] args) {

        String dirname = "C:\\Users\\dharm\\Desktop\\New GIT update\\MCA\\MCA Semester 2\\OOPS-2 JAVA\\Practice JAVA\\Endterm Finally";

        File dir = new File(dirname);

        FilenameFilter extracted = new Extractor("txt");

        String[] s = dir.list(extracted);
        for (String string : s) {
            System.out.println(string);
        }
        
    }
}
