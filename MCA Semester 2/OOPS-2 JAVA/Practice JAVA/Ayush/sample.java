import java.io.*;
import java.security.spec.ECFieldF2m;
import java.util.*;

class my_exception extends Exception{
    public String toString(){
        return "BKL";
    }           
}

class Thread_1 implements Runnable{
    public void run(){
        Scanner sc = new Scanner(System.in);
        File myFile2 = new File("input.txt");
        
    try{
        myFile2.createNewFile();
        FileWriter wr = new FileWriter(myFile2);
        char arr[] = new char[10];
        char temp;
        for(int i = 0 ; i < 5; i++){
        System.out.println("Enter the  character : ");
        temp = sc.next().charAt(0);
        if((temp >= 65 && temp <=91) || (temp >= 97 && temp <= 122)){
        arr[i] = temp;
                    wr.write(arr[i] + " ");
                } else{
                    throw new my_exception();
                }
                    
                }
    wr.close();
    sc.close();

    }
    catch(my_exception e){
        System.out.println("something went wrond" + e);
    }
    catch(IOException e){
        System.out.println("IOI EXCEPTION");
    }
}
}

class Thread_2 implements Runnable{
    public void run(){
        File enc = new File("Enc.txt");
        
        try{
            enc.createNewFile();
            FileWriter fr = new FileWriter(enc);
            FileReader rd = new FileReader("input.txt");
            int k = 0;
            while((k = rd.read()) != -1){
               //read value encyrpt karn ahi voh sotre enc 
               //encrpyt karnke ke liye 2 dabaye 
               char c= (char)(k + 2);
               fr.write(c );
            }          

            fr.close();
            rd.close();
        }catch(IOException e){
            System.out.println(e);
        }

    }

}

class Thread_3 implements Runnable{
    public void run(){
        File dec = new File("dec.txt");
        
        try{
            dec.createNewFile();
            FileWriter g = new FileWriter(dec);
            FileReader r = new FileReader("Enc.txt");
            int k = 0;
            while((k = r.read()) != -1){
                
               char c= (char)(k - 2);
               g.write(c);
              
            }          

            g.close();
            r.close();
        }catch(IOException e){
            System.out.println(e);
        }

    }

}


public class sample{
    public static void main(String [] args){
    
        Thread_1 obj = new Thread_1();
        Thread t = new Thread(obj);
        
        Thread_2 obj2 = new Thread_2();
        Thread t2 = new Thread(obj2);

        Thread_3 obj3 = new Thread_3();
        Thread t3 = new Thread(obj3);

        t.start();
        
        try{ t.join();}
        catch(Exception e ){
            System.out.println(e);
        }
        
        
        t2.start();
        try{ t2.join();}
        catch(Exception e ){
            System.out.println(e);
        }
        

        t3.start();
        try{ t3.join();}
        catch(Exception e ){
               System.out.println(e);
           }


           //print the dec.txt
           try{
            FileReader rd2 = new FileReader("dec.txt");
            int k = 0 ; 
            while( (k = rd2.read()) != -1){
                    System.out.print((char)k);
            }
            rd2.close();
           }catch(Exception e){
            System.out.println(e);
           }
    }

}