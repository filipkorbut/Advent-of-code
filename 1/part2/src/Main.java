import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Objects;
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

            int sum = 0;
            for (int i = 0; i < data.size(); i++) {
                String[] leftNumbers = data.get(i).split("\\s+");
                int numberCounter = 0;
                for(int j = 0; j < data.size(); j++){
                    String[] rightNumbers = data.get(j).split("\\s+");
                    if(Objects.equals(rightNumbers[1], leftNumbers[0])){
                        numberCounter++;
                    }
                }
                leftNumbers[0] = String.valueOf(Integer.parseInt(leftNumbers[0] )* numberCounter);
                sum += Integer.parseInt(leftNumbers[0]);
            }
            System.out.println(sum);

            input.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred: File not found.");
        }
    }


}
