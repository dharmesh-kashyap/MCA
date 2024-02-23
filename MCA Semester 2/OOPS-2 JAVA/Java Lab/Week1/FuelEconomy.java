import java.util.Scanner;

public class FuelEconomy {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		float distance, fuel, feco;
		System.out.print("Enter the Distance in KM: ");
		distance = sc.nextFloat();

		System.out.print("Enter the Fuel consumed in litres: ");
		fuel = sc.nextFloat();

		feco = distance / fuel;

		System.out.println("The average Fuel Economy is: " + feco);

		float nDistance, nFuel, newe;
		boolean cond = true;

		do {
			System.out.println("\nEnter the Choice \n 1 Distance Estimation \n 2 for Fuel Estimation \n 3. Exit  \t");
			int choice;
			choice = sc.nextInt();

			switch (choice) {
				case 1:

					System.out.print("Enter the Fuel Consumed in litres: ");
					newe = 0;
					nFuel = sc.nextFloat();
					newe = nFuel * feco;
					System.out.println("The Estimated Distance: " + newe);

					break;

				case 2:
					System.out.print("Enter the Distance covered: ");
					newe = 0;
					nDistance = sc.nextFloat();
					newe = nDistance / feco;
					System.out.println("The Estimated Fuel Consumption: " + newe);

					break;

				case 3:
					System.out.println("Exiting the program.");
					cond = false;
					break;

				default:
					System.out.println("Invalid choice.");
			}
		} while (cond == true);

	}

}