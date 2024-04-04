import java.util.*;
import java.lang.*;
import java.io.*;

class Invalid_Text_Exception extends Exception{
	public String toString(){
			return "Invalid Text Exception";
		}
	}

	class thread1 implements Runnable {

		File myfile = new File("Input.txt");
		Scanner sc = new Scanner(System.in);



		public void run(){

			System.out.print("Input the length: ");
			int n = sc.nextInt();

			try{

							myfile.createNewFile();

							FileWriter writer = new FileWriter(myfile);

							 System.out.println("Enter the Letters individually");
							 for(int i = 0 ; i < n; i++){
								Scanner sc = new Scanner(System.in);
								char X = sc.next();
								if ( ((X >= 65) && ( X <= 91  )) || (( X >= 97 ) &&  ( X <= 123 ))){
										writer.write(X + " ");
								}
								else{
									throw new Invalid_Text_Exception();
									}

							}
							writer.close();
							}catch(Exception e){
								e.printStackTrace();
							}

			}
		}


class thread2 implements Runnable {
	File NewFile = new File("encrypted_file.txt");
	public void run(){

		try{
			NewFile.createNewFile();
			FileWriter Writer = new FileWriter(NewFile);
			FileReader Reader = new FileReader("input.txt");

			int k = 0;
			while((k = reader.read) != -1){
				char Inputchar = (char)k + 19;
				Writer.write(Inputchar + " ");
				}

				Reader.close();
				Writer.close();

			}catch(Exception e){
				e.printStackTrace();
				}


		}
	}

class thread3 implements Runnable {
	File NewFile2 = new File("Decrypted_file.txt");
	public void run(){

		try{
			NewFile2.createNewFile();
			FileWriter Writer1 = new FileWriter(NewFile2);
			FileReader reader1 = new FileReader("encrypted_file.txt");

			int k = 0;
			while((k = reader.read) != -1){
				char Inputchar = (char)k - 19;
				Writer1.write(Inputchar + " ");
				}

				reader1.close();
				Writer1.close();


			}catch(Exception e){
				e.printStackTrace();
				}


		}
	}

	public class Document1 {
		public static void main(String[] args){

			thread1 t1 = new thread();
			thread2 t2 = new thread();
			thread3 t3 = new thread();

			Thread T1 = new Thread(t1);
			Thread T2 = new Thread(t2);
			Thread T2 = new Thread(t3);


			T1.start();

			try{
				T1.join();
				}catch(Exception e){
					e.printStackTrace();
					}
			T2.start();

			try{
				T2.join();
				}catch(Exception e){
					e.printStackTrace();
					}
			T3.start();

			try{
				T3.join();
				}catch(Exception e){
					e.printStackTrace();
					}
			try{
				FileReader reader = new FileReader("encrypted_file.txt");
				int k = 0;
				while((k = reader.read) != -1){
						System.out.println((char)k + " ");
				}

				FileReader reader1 = new FileReader("Decrypted_file.txt");
				int l = 0;
				while((l = reader1.read) != -1){
				System.out.println((char)l + " ");
				}
				}catch(Exception e){

					}


				reader.close();
				reader1.close();


		}
}