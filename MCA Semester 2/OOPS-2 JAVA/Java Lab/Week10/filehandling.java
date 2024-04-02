import java.util.*;
import java.io.*;

public class filehandling{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the file name to be created: ");
		String filename = sc.next();

		System.out.print("Enter the number of string to be entered: ");
		int n = sc.nextInt();
		File myfile = new File(filename);
		String sort[] = new String[n];

		try{
			myfile.createNewFile();
			FileWriter writer = new FileWriter(myfile);
			System.out.println("Enter the strings: ");
			for(int i = 0; i < n ; i++ ){
					String temp = sc.next();
					writer.write(temp + "\n");
				}
			writer.close();
			Scanner reader = new Scanner(myfile);
			int k = 0;
			while(reader.hasNextLine()){
				String data = reader.nextLine();
				sort[k] = data;
				k++;
				}
			reader.close();
			for (int j = 0; j < n - 1; j++) {
				for (int i = j + 1; i < n; i++) {
				     if (sort[j].compareTo(sort[i]) > 0) {
				         String temp = sort[j];
				         sort[j] = sort[i];
				         sort[i] = temp;
				    }
			   }
		   }

		System.out.print("Enter the Dsination file name to be created: ");
		String fileDest = sc.next();
		File myfile2 = new File(fileDest);
		myfile2.createNewFile();
		FileWriter writer2 = new FileWriter(myfile2);
		for(int i = 0; i < n ; i++ ){
			writer2.write(sort[i] + "\n");
			}
			writer2.close();

		} catch(Exception e) {
			System.out.println("An error has occur");
			System.out.println(e);
			e.printStackTrace();

		}
		sc.close();

		}


	}
