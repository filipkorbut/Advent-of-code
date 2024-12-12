import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        try {
            File file = new File("src/input.txt");
            Scanner input = new Scanner(file);
            ArrayList<String> data = new ArrayList<>();
            while (input.hasNextLine()) {
                data.add(input.nextLine());
            }

            data = sort(data);
            int sum = 0;
            int distance = 0;
            for (int i = 0; i < data.size(); i++) {
                String[] line = data.get(i).split("\\s+");
                distance = Integer.parseInt(line[0]) - Integer.parseInt(line[1]) > 0 ? Integer.parseInt(line[0]) - Integer.parseInt(line[1]) : Integer.parseInt(line[1]) - Integer.parseInt(line[0]);
                sum += distance;
            }
            System.out.println(sum);
            input.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred: File not found.");
        }
    }

    public static ArrayList<String> sort(ArrayList<String> data) {
        for (int i = 0; i < data.size(); i++) {
            for (int j = 1; j < data.size(); j++) {
                String[] previousLine = data.get(j - 1).split("\\s+");
                String[] currentLine = data.get(j).split("\\s+");

                int previousLeft = Integer.parseInt(previousLine[0]);
                int previousRight = Integer.parseInt(previousLine[1]);
                int currentLeft = Integer.parseInt(currentLine[0]);
                int currentRight = Integer.parseInt(currentLine[1]);

                int leftSmallest = Math.min(previousLeft, currentLeft);
                int leftLargest = Math.max(previousLeft, currentLeft);

                int rightSmallest = Math.min(previousRight, currentRight);
                int rightLargest = Math.max(previousRight, currentRight);

                data.set(j - 1, leftSmallest + "   " + rightSmallest);

                data.set(j, leftLargest + "   " + rightLargest);
            }
        }
        return data;
    }
}

