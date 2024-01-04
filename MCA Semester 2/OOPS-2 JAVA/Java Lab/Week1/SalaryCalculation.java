import java.util.Scanner;
public class SalaryCalculation{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int hrs, newh ;
		float rate, total, total1;



		System.out.print("Enter the Hour Worked In factory(in Hours): ");
		hrs = sc.nextInt();

		System.out.print("Enter the Hourly rate: ");
		rate = sc.nextFloat();
		total = rate * hrs;

			if(hrs>40){
				newh = hrs - 40;
				total1 = (rate*0.5f)*newh;
				total += total1;
				System.out.print("The Gross salary is: " + total);
				}
			else{

				System.out.print("The Gross salary is: " + total);


				}

		}

	}