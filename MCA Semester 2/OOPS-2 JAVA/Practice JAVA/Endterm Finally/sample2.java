import java.io.*;
//import java.util.*;
class extensionExtractor implements FilenameFilter {
    String extension;

    public extensionExtractor(String extension){
        this.extension = "." + extension;
    }

    public boolean accept(File dir, String name){
        return name.endsWith(extension);
    }
}
public class sample2 {
    public static void main(String[] args) {
        String dirName = "C:\\Users\\dharm\\Desktop\\New GIT update\\MCA\\MCA Semester 2\\OOPS-2 JAVA\\Practice JAVA\\Endterm Finally";
        File dir = new File(dirName);

        FilenameFilter noice = new extensionExtractor("txt");
        String[] S = dir.list(noice);

        for(String string : S){
            System.out.println(string);
        }

    }
}
