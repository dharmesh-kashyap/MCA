import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class QuizApp extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;
    private String[] correctAnswers = {
            "Game development",
            "Bytecode and JVM",
            "By using classes and objects",
            "Within classes",
            "Declared with data types"
    };

    public QuizApp() {
        setTitle("Admission Entrance Test");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 200);
        setLocationRelativeTo(null);

        JLabel titleLabel = new JLabel("Welcome to the Java Quiz");
        titleLabel.setFont(new Font("Arial", Font.BOLD, 18));
        titleLabel.setForeground(Color.BLUE);
        titleLabel.setHorizontalAlignment(SwingConstants.CENTER);
        add(titleLabel, BorderLayout.NORTH);

        JPanel loginPanel = new JPanel();
        loginPanel.setLayout(new GridLayout(3, 2));
        loginPanel.setBackground(Color.LIGHT_GRAY);

        JLabel usernameLabel = new JLabel("Username:");
        JLabel passwordLabel = new JLabel("Password:");
        usernameField = new JTextField(20);
        passwordField = new JPasswordField(20);
        JButton loginButton = new JButton("Login");
        loginButton.setBackground(Color.GREEN);
        loginButton.setForeground(Color.WHITE);

        loginPanel.add(usernameLabel);
        loginPanel.add(usernameField);
        loginPanel.add(passwordLabel);
        loginPanel.add(passwordField);
        loginPanel.add(new JLabel());
        loginPanel.add(loginButton);

        add(loginPanel, BorderLayout.CENTER);

        loginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());

                if (username.equals("JavaUser") && password.equals("1234")) {
                    openMCQPage();
                } else {
                    JOptionPane.showMessageDialog(null, "Invalid credentials. Try again.");
                }
            }
        });

        setVisible(true);
    }

    private void openMCQPage() {
        JFrame mcqFrame = new JFrame("Java Quiz");
        mcqFrame.setSize(700, 500);
        mcqFrame.setLocationRelativeTo(null);
        mcqFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel mcqPanel = new JPanel();
        mcqPanel.setLayout(new BoxLayout(mcqPanel, BoxLayout.Y_AXIS));

        JLabel titleLabel = new JLabel("Simple Java Quiz");
        titleLabel.setFont(new Font("Arial", Font.BOLD, 16));
        titleLabel.setForeground(Color.BLUE);
        titleLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        mcqPanel.add(titleLabel);

        addMCQ(mcqPanel,
                "Question 1: What is Java primarily used for?",
                new String[] {
                        "Web development",
                        "Game development",
                        "Scripting language",
                        "Mobile apps" });

        addMCQ(mcqPanel, "Question 2: What makes Java platform-independent?",
                new String[] {
                        "Dynamic typing",
                        "Open-source nature",
                        "Platform-dependent libraries",
                        "Bytecode and JVM" });

        addMCQ(mcqPanel, "Question 3: How does Java handle web development?",
                new String[] {
                        "By using classes and objects",
                        "By interpreting HTML code",
                        "By using Python scripts",
                        "By compiling web pages" });

        addMCQ(mcqPanel, "Question 4: Where are Java methods defined?",
                new String[] {
                        "Within classes",
                        "Outside classes",
                        "Inheritance hierarchy",
                        "Database tables" });

        addMCQ(mcqPanel, "Question 5: What is a characteristic of Java variables?",
                new String[] {
                        "Declared with data types",
                        "Dynamically typed",
                        "Unlimited size",
                        "Constant values" });

        JScrollPane scrollPane = new JScrollPane(mcqPanel);
        mcqFrame.add(scrollPane);

        JButton submitButton = new JButton("Submit");
        submitButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        submitButton.setBackground(Color.GREEN);
        submitButton.setForeground(Color.WHITE);
        mcqPanel.add(submitButton);

        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int score = calculateScore(mcqPanel);
                String username = usernameField.getText();
                JOptionPane.showMessageDialog(null, "Your score: " + score);
                storeScoreInDatabase(username, score);
            }
        });

        mcqFrame.setVisible(true);
        setVisible(false);
    }

    private void addMCQ(JPanel panel, String question, String[] options) {
        JLabel questionLabel = new JLabel(question);
        questionLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        panel.add(questionLabel);
        ButtonGroup group = new ButtonGroup();
        for (String option : options) {
            JRadioButton radioButton = new JRadioButton(option);
            radioButton.setFont(new Font("Arial", Font.PLAIN, 12));
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
                if (radioButton.isSelected() && isCorrectAnswer(radioButton.getText())) {
                    score++;
                }
            }
        }
        return score;
    }

    private boolean isCorrectAnswer(String selectedAnswer) {
        for (String correctAnswer : correctAnswers) {
            if (selectedAnswer.equals(correctAnswer)) {
                return true;
            }
        }
        return false;
    }

    private void storeScoreInDatabase(String username, int score) {
        String url = "jdbc:mysql://localhost:3306/studentMarks";
        String user = "root";
        String password = "Deeraj@8898";
        try {
            Connection connection = DriverManager.getConnection(url, user, password);
            String checkTableExistsSQL = "SHOW TABLES LIKE 'scores'";
            PreparedStatement checkTableExistsStatement = connection.prepareStatement(checkTableExistsSQL);
            ResultSet resultSet = checkTableExistsStatement.executeQuery();
            if (!resultSet.next()) {
                String createTableSQL = "CREATE TABLE scores (id INT AUTO_INCREMENT PRIMARY KEY, username VARCHAR(255), score INT)";
                Statement createTableStatement = connection.createStatement();
                createTableStatement.executeUpdate(createTableSQL);
            }
            String insertScoreSQL = "INSERT INTO scores (username, score) VALUES (?, ?)";
            PreparedStatement insertStatement = connection.prepareStatement(insertScoreSQL);
            insertStatement.setString(1, username);
            insertStatement.setInt(2, score);
            insertStatement.executeUpdate();
            JOptionPane.showMessageDialog(null, username + " Your score has successfully submitted", "System Message",
                    JOptionPane.INFORMATION_MESSAGE);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new QuizApp();
            }
        });
    }
}
