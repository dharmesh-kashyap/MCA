import java.io.*;

public class FileCopyExample {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Enter the content to be written to the source file:\n");
            String sourceContent = reader.readLine();

            System.out.print("Enter the name of the source file: ");
            String sourceFileName = reader.readLine();
            createSourceFile(sourceFileName, sourceContent);

            System.out.print("Enter the name of the destination file: ");
            String destFileName = reader.readLine();
            copyFileContents(sourceFileName, destFileName);

            System.out.println("File copied successfully.");

        } catch (IOException e) {
            System.err.println("Error occurred: " + e.getMessage());
        }
    }

    private static void createSourceFile(String fileName, String content) {
        try (FileWriter fileWriter = new FileWriter(fileName)) {
            fileWriter.write(content);
            System.out.println("Source file created successfully.");
        } catch (IOException e) {
            System.err.println("Error occurred while creating the source file: " + e.getMessage());
        }
    }

    private static void copyFileContents(String sourceFileName, String destFileName) {
        try (FileReader fileReader = new FileReader(sourceFileName);
             FileWriter fileWriter = new FileWriter(destFileName)) {

            int data;
            while ((data = fileReader.read()) != -1) {
                fileWriter.write(data);
            }

        } catch (IOException e) {
            System.err.println("Error occurred while copying file contents: " + e.getMessage());
        }
    }
}
