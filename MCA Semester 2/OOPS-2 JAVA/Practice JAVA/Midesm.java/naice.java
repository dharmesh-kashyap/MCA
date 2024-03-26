import java.util.Arrays;

// Custom exception class
class InvalidFileExtensionException extends Exception {
    public InvalidFileExtensionException(String message) {
        super(message);
    }
}

public class naice {
    // Method to check if all filenames have the same extension
    public static boolean checkFileExtensions(String[] filenames) throws InvalidFileExtensionException {
        if (filenames == null || filenames.length == 0) {
            throw new IllegalArgumentException("File list is empty");
        }

        // Get the extension of the first filename
        String extension = getFileExtension(filenames[0]);

        // Check if all filenames have the same extension
        for (String filename : filenames) {
            if (!getFileExtension(filename).equals(extension)) {
                throw new InvalidFileExtensionException("Invalid File Extension: " + filename);
            }
        }

        return true;
    }

    // Helper method to get the file extension
    private static String getFileExtension(String filename) {
        int lastIndex = filename.lastIndexOf('.');
        if (lastIndex == -1) {
            return ""; // No extension found
        }
        return filename.substring(lastIndex + 1);
    }

    public static void main(String[] args) {
        String[] filenames = {"file1.txt", "file2.txt", "file3.pdf"};

        try {
            boolean extensionsValid = checkFileExtensions(filenames);
            if (extensionsValid) {
                System.out.println("All filenames have the same extension.");
            }
        } catch (InvalidFileExtensionException e) {
            System.out.println(e.getMessage());
        }
    }
}
