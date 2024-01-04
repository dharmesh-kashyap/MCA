import java.util.Scanner;
public class javafirst
{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter your Age: ");
		float height, weight, bmi, con;

		System.out.print("Enter your Height in cm: ");
		height = sc.nextFloat();

		System.out.print("Enter your weight in kgs: ");
		weight = sc.nextFloat();

		con = height/100;

		bmi = weight / (con*con);

		if(bmi<18.5f){
			System.out.println( bmi + "\nUnder Weight !!\n" );
			}
			else if(bmi>=18.5f && bmi<=24.9f ){
				System.out.println( "BMI: " + bmi + "\nNormal !!\n" );
				}
				else if(bmi>=25 && bmi<=29.9f ){
								System.out.println( "BMI: " + bmi + "\nover weight !!\n" );
				}
				else if(bmi>30){
								System.out.println( "BMI: " + bmi + "\nObese !!\n" );
				}
		}
	}