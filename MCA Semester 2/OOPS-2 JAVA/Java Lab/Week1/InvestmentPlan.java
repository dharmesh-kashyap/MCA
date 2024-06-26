import java.util.Scanner;
import java.lang.Math;

public class InvestmentPlan {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float loanAmt, timePeriod, monthlyPayment, TotalPayment, monthlyInterest;
        System.out.print("Enter the Loan Amount you want to borrow: ");
        loanAmt = sc.nextFloat();
        System.out.print("Enter the Time Period: ");
        timePeriod = sc.nextFloat();
        System.out.println("Interest rate\t\tMonthly Payment\tTotal Payment");
        for (float i = 5; i <= 8; i += (1 / 8f)) {
            monthlyInterest = (i / 100) / 12f;  
            float temp2 = (float) Math.pow((1f + monthlyInterest), (timePeriod * 12f));
            float temp = 1f - (1f / temp2);
            monthlyPayment = (loanAmt * monthlyInterest) / temp;
            TotalPayment = monthlyPayment * timePeriod * 12;
            System.out.printf("%.2f%%\t\t\t\t%.2f\t\t\t%.2f\n", i, monthlyPayment, TotalPayment);
        }
    }
}
