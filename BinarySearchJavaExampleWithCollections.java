import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// import com.google.common.collect.Lists;

class JavaExample {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter numbers limit : ");

    int limit = scanner.nextInt();

    System.out.println("\nEnter numbers press enter after input : ");

    List<Integer> inputList = new ArrayList<>();

    for (int a = 0; a < limit; a++) {

      inputList.add(scanner.nextInt());

    }

    System.out.print("Enter number you want to search : ");

    int searchNum = scanner.nextInt();

    int indexOfSearchNum = Collections.binarySearch(inputList, searchNum);

    System.out.println("index of " + searchNum + " is : " + indexOfSearchNum);

    scanner.close();

  }

}
