public class FeesIncremet{

	public static void main (String[] args){
		float fees = 50000;
		float incr = 5f * fees /100f ;
		for (int i = 0; i <= 10; i++){
			   fees += incr;
			    System.out.println( "The Fees after" +  i +  "Year is: " + fees);


			}

		}

	}