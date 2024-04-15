import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.Serializable;


class  Students {  
     int id; 
     String name;

     Students(int i , String n){
          id = i;
          name = n;
     }
}
//sorting in thread
class Thread_3 implements Runnable{
     Students s1 = new Students(1, "AYush");
     Students s2  = new Students(2, "Dhear");
     Students s3  = new Students(3, "some");
     public void run(){
 

          //try(ObjectOutputStream fw = new ObjectOutputStream(new FileOutputStream("Students.txt")))*/{
               try{
                    File output = new File("new.txt");
                    output.createNewFile();

                    FileWriter objwriter = new FileWriter(output);
                    objwriter.write(s1.id + s1.name + "\n" + s2.id + s2.name + "\n" + s2.id + s2.name + "\n"); 

               System.out.println("Objects written to file successfully.");
               objwriter.close();
          }catch(IOException e){
               System.out.println("THe value is fukced" + e);
          }
     }
}

class Thread_2 implements Runnable{
     public void run(){
          try{
               FileReader rd = new FileReader( "new.txt");
               int k = 0 ;
               while ( (k = rd.read()) != -1) {
                    System.out.println((char)k);
               }
               rd.close();
          }catch(IOException e){
               System.out.println(e);
          }
     }
}

public class Sample3 {

     public static void main(String[] args) {
          Thread t = new Thread(new Thread_3());
          t.start();

          try{
               t.join();
          }catch(Exception e){
               System.out.println(e);
          }


          Thread t1 = new Thread(new Thread_2());
          t1.start();
     }
}