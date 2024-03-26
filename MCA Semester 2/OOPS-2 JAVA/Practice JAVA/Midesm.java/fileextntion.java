import java.util.*;
class Invalid_File_Extn extends Exception {
        @Override
        public String toString(){
            return "Invalid Extenstion";
        }
}
public class fileextntion {

    public static String getExtension(String file){
        int lastindex = file.lastIndexOf('.');
        String extn = file.substring(lastindex);
        return extn;

    }

   public static void Filenamechecker(String[] Str) throws Invalid_File_Extn {
            String Extn = getExtension(Str[0]);
            for (String string : Str) {
                if (!getExtension(string).equalsIgnoreCase(Extn)) {
                    throw new Invalid_File_Extn();
                }
            }
       
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String fileNames[];
        System.out.println("Enter the no. of files: ");
        int x = sc.nextInt();

        fileNames = new String[x];
        System.out.println("Enter the file names: ");
        for (int i = 0; i < x; i++) {
            fileNames[i] = sc.next();
        }
        try {
            Filenamechecker(fileNames);
            
        } catch (Invalid_File_Extn e) {
            System.out.println(e);
        }


        sc.close();
        
    }
    
}
