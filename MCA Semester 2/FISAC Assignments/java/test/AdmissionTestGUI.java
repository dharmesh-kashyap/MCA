import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class AdmissionTestGUI extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;

    public AdmissionTestGUI() {
        setTitle("Admission Entrance Test");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 200);
        setLocationRelativeTo(null);

        JLabel usernameLabel = new JLabel("Username:");
        JLabel passwordLabel = new JLabel("Password:");
        usernameField = new JTextField(20);
        passwordField = new JPasswordField(20);
        JButton loginButton = new JButton("Login");

        JPanel loginPanel = new JPanel();
        loginPanel.setLayout(new GridLayout(3, 2));
        loginPanel.add(usernameLabel);
        loginPanel.add(usernameField);
        loginPanel.add(passwordLabel);
        loginPanel.add(passwordField);
        loginPanel.add(new JLabel());
        loginPanel.add(loginButton);

        loginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());
                // Perform authentication logic here
                if (username.equals("admin") && password.equals("password")) {
                    openMCQPage(); // Open MCQ page on successful login
                } else {
                    JOptionPane.showMessageDialog(null, "Invalid credentials. Try again.");
                }
            }
        });

        add(loginPanel);
        setVisible(true);
    }

    private void openMCQPage() {
        JFrame mcqFrame = new JFrame("MCQ Page");
        mcqFrame.setSize(600, 400);
        mcqFrame.setLocationRelativeTo(null);
        mcqFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel mcqPanel = new JPanel();
        mcqPanel.setLayout(new BoxLayout(mcqPanel, BoxLayout.Y_AXIS));

        JLabel titleLabel = new JLabel("Multiple-Choice Questions");
        mcqPanel.add(titleLabel);

        // Example MCQs (replace with actual questions)
        addMCQ(mcqPanel, "Question 1: What is the capital of France?", new String[]{"Paris", "Berlin", "London", "Rome"});
        addMCQ(mcqPanel, "Question 2: Who is the author of 'Hamlet'?", new String[]{"Shakespeare", "Dickens", "Twain", "Hemingway"});
        addMCQ(mcqPanel, "Question 3: What is the chemical symbol for gold?", new String[]{"Au", "Ag", "Fe", "Cu"});
        addMCQ(mcqPanel, "Question 4: What is the tallest mountain in the world?", new String[]{"Mount Everest", "K2", "Kangchenjunga", "Makalu"});
        addMCQ(mcqPanel, "Question 5: What is the capital of Japan?", new String[]{"Tokyo", "Beijing", "Seoul", "Bangkok"});

        JScrollPane scrollPane = new JScrollPane(mcqPanel);
        mcqFrame.add(scrollPane);

        JButton submitButton = new JButton("Submit");
        submitButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        mcqPanel.add(submitButton);

        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int score = calculateScore(mcqPanel);
                String username = usernameField.getText();
                JOptionPane.showMessageDialog(null, "Your score: " + score);

                // Store score in database
                storeScoreInDatabase(username, score);
            }
        });

        mcqFrame.setVisible(true);
        setVisible(false); // Hide login window
    }

    private void addMCQ(JPanel panel, String question, String[] options) {
        JLabel questionLabel = new JLabel(question);
        panel.add(questionLabel);
        ButtonGroup group = new ButtonGroup();
        for (String option : options) {
            JRadioButton radioButton = new JRadioButton(option);
            group.add(radioButton);
            panel.add(radioButton);
        }
    }

    private int calculateScore(JPanel panel) {
        int score = 0;
        Component[] components = panel.getComponents();
        for (Component component : components) {
            if (component instanceof JRadioButton) {
                JRadioButton radioButton = (JRadioButton) component;
                if (radioButton.isSelected()) {
                    // Logic to check correct answers (not implemented in this example)
                    score++; // Increment score for each correct answer
                }
            }
        }
        return score;
    }

    private void storeScoreInDatabase(String username, int score) {
        String url = "jdbc:mysql://localhost:3306/your_database_name";
        String user = "root";
        String password = "Dkashyap@467";

        try (Connection connection = DriverManager.getConnection(url, user, password)) {
            String sql = "INSERT INTO scores (username, score) VALUES (?, ?)";
            try (PreparedStatement statement = connection.prepareStatement(sql)) {
                statement.setString(1, username);
                statement.setInt(2, score);
                statement.executeUpdate();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new AdmissionTestGUI();
            }
        });
    }
}
