import java.util.Scanner;
public class Matrixtracing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        System.out.println("Enter the row and column of matrix: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        float[][] Matrix = new float[m][n];
        System.out.print("\n");

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                System.out.print("Enter the Elements on "+i+j+" : " );
                Matrix[i][j] = sc.nextFloat();
            }

        }
        System.out.print("\nThe matrix is: \n");
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                System.out.print(Matrix[i][j]+" ");
            }
            System.out.print("\n");
        }

        float maxnum = Matrix[0][0];
        int rowindex = 0, columnindex = 0; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (Matrix[i][j]>maxnum){
                    maxnum = Matrix[i][j];
                    rowindex = i;
                    columnindex = j;
                }
            }
        }

        System.out.println("\nThe Maximum value in the matrix is: "+maxnum+" and the location is: "+rowindex+" "+columnindex);

        float minnum = Matrix[0][0];
        int rowindex1 = 0, columnindex1 = 0; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (Matrix[i][j]<minnum){
                    minnum = Matrix[i][j];
                    rowindex1 = i;
                    columnindex1 = j;
                }
            }
        }

        System.out.println("The Minimum value in the matrix is: "+minnum+" and the location is: "+rowindex1+" "+columnindex1);






        
    }
    
}
