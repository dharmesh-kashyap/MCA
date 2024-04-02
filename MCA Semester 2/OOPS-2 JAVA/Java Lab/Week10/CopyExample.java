import java.util.*;
import java.io.*;

public class CopyExample{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the file name to be created: ");
		String filename = sc.next();
		File myfile = new File(filename);
				try{
					myfile.createNewFile();
					FileWriter writer = new FileWriter(myfile);
					System.out.println("Enter the strings: ");
					sc.nextLine();
					String temp = sc.nextLine();
					writer.write(temp + "\n");
					writer.close();

					System.out.print("Enter the file name to be created: ");
					String fileDest = sc.next();
					File myfile2 = new File(fileDest);
					myfile2.createNewFile();

					FileWriter writer2 = new FileWriter(myfile2);
					FileReader reader = new FileReader(myfile);
					int k = 0;
					while((k = reader.read()) != -1){
						writer2.write((char)k);
						System.out.print((char)k);
						}
					reader.close();
					writer2.close();

			} catch(Exception e){
					System.out.println("An error has occur");
					System.out.println(e);
				}

		}

	}