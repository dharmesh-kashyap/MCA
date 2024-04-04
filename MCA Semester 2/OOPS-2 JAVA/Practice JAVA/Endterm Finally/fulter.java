import java.io.*;
class extensionExt implements FilenameFilter {
    String extension;

    extensionExt(String ext){
        extension = "."+ext;
    }

    public boolean accept(File dir, String name){
        return name.endsWith(extension);
    }
}
public class fulter {
    public static void main(String[] args) {

        String Dirname = "C:\\Users\\dharm\\Desktop\\New GIT update\\MCA\\MCA Semester 2\\OOPS-2 JAVA\\Practice JAVA\\Endterm Finally";
        File dir = new File(Dirname);
        FilenameFilter extractor = new extensionExt("java");
        String[] S = dir.list(extractor);
        for(String string : S){
            System.out.println(string);
        }
    }
}
