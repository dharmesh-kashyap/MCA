import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

/**
 *The QuizApp class represents an application for conducting a multiple-choice quiz.
 * It provides a login page for users to enter their credentials and access the quiz.
 * The quiz consists of multiple questions with options, and the user's score is calculated based on their answers.
 * The score is then stored in a database.
 */
public class QuizApp extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;
    private String[] correctAnswers = {
            "Serializable is a marker interface, Externalizable provides more control over serialization",
            "Java Reflection allows inspection and manipulation of class metadata at runtime",
            "ArrayList uses dynamic arrays, LinkedList uses linked nodes",
            "Java uses threads to achieve multitasking, synchronization is used to control access to shared resources",
            "Java Generics allow type parameterization, providing compile-time type safety"
    };

    /**
     * Constructs a QuizApp object.
     * Initializes the GUI components and sets up the login page.
     */
    public QuizApp() {
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

                if (username.equals("Dharmesh") && password.equals("4562")) {
                    openMCQPage();
                } else {
                    JOptionPane.showMessageDialog(null, "Invalid credentials. Try again.");
                }
            }
        });

        add(loginPanel);
        setVisible(true);
    }

    /**
     * Opens the MCQ page for the quiz.
     * Constructs the GUI components for the MCQ page and sets up the questions and options.
     * Calculates the user's score and stores it in the database.
     */
    private void openMCQPage() {
        JFrame mcqFrame = new JFrame("MCQ Page");
        mcqFrame.setSize(1000, 700); 
        mcqFrame.setLocationRelativeTo(null);
        mcqFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel mcqPanel = new JPanel();
        mcqPanel.setLayout(new BoxLayout(mcqPanel, BoxLayout.Y_AXIS));

        JLabel titleLabel = new JLabel("Multiple-Choice Questions");
        mcqPanel.add(titleLabel);

        // Add questions and options to the MCQ panel
        addMCQ(mcqPanel,
                "Question 1: What is the difference between Serializable and Externalizable interfaces in Java?",
                new String[] {
                        "Serializable is for network communication, Externalizable is for file I/O",
                        "Serializable is a marker interface, Externalizable provides more control over serialization",
                        "Serializable is for multithreaded applications, Externalizable is for single-threaded applications",
                        "Serializable uses default serialization, Externalizable uses custom serialization" });

        addMCQ(mcqPanel, "Question 2: Explain the concept of Java Reflection API and its uses.",
                new String[] {
                        "Java Reflection is used for creating dynamic web pages",
                        "Java Reflection is a design pattern in Java programming",
                        "Java Reflection allows inspection and manipulation of class metadata at runtime",
                        "Java Reflection is used for database connections" });

        addMCQ(mcqPanel, "Question 3: What are the differences between ArrayList and LinkedList in Java?",
                new String[] {
                        "ArrayList is faster for adding elements, LinkedList is faster for removing elements",
                        "ArrayList is synchronized, LinkedList is not synchronized",
                        "ArrayList allows null elements, LinkedList does not allow null elements",
                        "ArrayList uses dynamic arrays, LinkedList uses linked nodes" });

        addMCQ(mcqPanel, "Question 4: How does Java handle multithreading and synchronization?",
                new String[] {
                        "Java uses threads to achieve multitasking, synchronization is used to control access to shared resources",
                        "Java creates multiple instances of classes to achieve multitasking",
                        "Java uses separate processes for each task, synchronization is automatic",
                        "Java relies on the operating system for multithreading" });

        addMCQ(mcqPanel, "Question 5: Explain the concept of Java Generics and its advantages.",
                new String[] {
                        "Java Generics are used for graphical user interface (GUI) development",
                        "Java Generics are similar to exception handling in Java",
                        "Java Generics allow type parameterization, providing compile-time type safety",
                        "Java Generics improve performance of Java applications" });

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
                storeScoreInDatabase(username, score);
            }
        });

        mcqFrame.setVisible(true);
        setVisible(false);
    }

    /**
     * Adds a multiple-choice question to the MCQ panel.
     * The panel to add the question to.
     * The question to be displayed.
     * The options for the question.
     */
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

    /**
     * Calculates the user's score based on their selected answers.
     * The panel containing the MCQ questions and options.
     * return The user's score.
     */
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

    /**
     * Checks if the selected answer is correct.
     * selectedAnswer The selected answer.
     * return true if the selected answer is correct, false otherwise.
     */
    private boolean isCorrectAnswer(String selectedAnswer) {
        for (String correctAnswer : correctAnswers) {
            if (selectedAnswer.equals(correctAnswer)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Stores the user's score in the database.
     */
    private void storeScoreInDatabase(String username, int score) {
        String url = "jdbc:mysql://localhost:3306/student_info";
        String user = "root";
        String password = "Dkashyap@467";
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

    /**
     * The main method that starts the QuizApp application.
     */
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new QuizApp();
            }
        });
    }
}
