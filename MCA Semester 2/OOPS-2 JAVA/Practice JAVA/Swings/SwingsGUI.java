import java.awt.Color;
import java.util.*;
import javax.swing.*;
public class SwingsGUI {

   public  SwingsGUI(){
        JFrame frame = new JFrame(); // creates frame
        frame.setSize(720,720); // sets the size of the frame 
        frame.setVisible(true); // Set the visibility of the frame
        frame.setResizable(true);//Let you resize or restrict resize 
        frame.setTitle("Sample School Management Application"); // set title of the frame
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//exit on close
        ImageIcon image = new ImageIcon("Logo.jpg");
        frame.setIconImage(image.getImage());
        //frame.getContentPane().setBackground(Color.darkGray);
        frame.getContentPane().setBackground(new Color(12,12,12));
         String S = "Fuck You";
        JLabel label = new JLabel();
        label.setText(S);
        label.setIcon(image);

        frame.add(label);


        //JPanel panel = new JPanel();

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new SwingsGUI();
        sc.close();
        
    }
}
