import java.io.*;
import java.util.*;

// Custom exception class
class MyException extends Exception {
    @Override
    public String toString() {
        return "Custom Exception: Invalid Input";
    }
}

// Runnable class for Thread_1
class Thread_11 implements Runnable {
    @Override
    public void run() {
        Scanner sc = new Scanner(System.in);
        File inputFile = new File("input.txt");

        try {
            inputFile.createNewFile(); // Create a new file if it doesn't exist
            FileWriter writer = new FileWriter(inputFile);

            for (int i = 0; i < 5; i++) {
                System.out.println("Enter a character: ");
                char temp = sc.next().charAt(0);
                if ((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z')) {
                    writer.write(temp); // Write valid characters to the file
                } else {
                    throw new MyException(); // Throw custom exception for invalid input
                }
            }

            writer.close();
            sc.close();
        } catch (MyException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println("IO Exception: " + e.getMessage());
        }
    }
}

// Runnable class for Thread_2
class Thread_21 implements Runnable {
    @Override
    public void run() {
        File encryptedFile = new File("Enc.txt");

        try {
            encryptedFile.createNewFile();
            FileWriter writer = new FileWriter(encryptedFile);
            FileReader reader = new FileReader("input.txt");

            int k;
            while ((k = reader.read()) != -1) {
                char c = (char) (k + 2); // Encrypting characters
                writer.write(c);
            }

            writer.close();
            reader.close();
        } catch (IOException e) {
            System.out.println("IO Exception: " + e.getMessage());
        }
    }
}

// Runnable class for Thread_3
class Thread_31 implements Runnable {
    public void run() {
        File dec = new File("dec.txt");

        try {
            dec.createNewFile();
            FileWriter g = new FileWriter(dec);
            FileReader r = new FileReader("Enc.txt");
            int k;
            while ((k = r.read()) != -1) {
                char c = (char) (k - 2);
                g.write(c); // Writing decrypted characters
            }

            g.close();
            r.close();
        } catch (IOException e) {
            System.out.println("IO Exception: " + e.getMessage());
        }
    }
}

public class Sample2 {
    public static void main(String[] args) {
        Thread_11 thread1 = new Thread_11();
        Thread t1 = new Thread(thread1);

        Thread_21 thread2 = new Thread_21();
        Thread t2 = new Thread(thread2);

        Thread_31 thread3 = new Thread_31();
        Thread t3 = new Thread(thread3);

        t1.start();
        t2.start();
        t3.start();

        try {
            t1.join();
            t2.join();
            t3.join();

            // Print the decrypted content from "dec.txt"
            FileReader reader = new FileReader("dec.txt");  
            int ch;
            while ((ch = reader.read()) != -1) {
                System.out.print((char) ch);
            }
            reader.close();
        } catch (IOException | InterruptedException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
