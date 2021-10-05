import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Main {

// Method to reverse a string
public static String reversingMethod(String str) {

// if the string is null or empty
if (str == null || str.equals("")) {
   return str;
}

// create a list of characters
List<Character> sentenceIntoCharList = new ArrayList<Character>();

// push every character of the given string into it
for (char oneCharactorOfTheSentence : str.toCharArray()) {
   sentenceIntoCharList.add(oneCharactorOfTheSentence);
}

// reverse list using java Collection API
Collections.reverse(sentenceIntoCharList);

// convert List into string
StringBuilder builder = new StringBuilder(sentenceIntoCharList.size());
for (Character c : sentenceIntoCharList) {
   builder.append(c);
}

return builder.toString();
}

public static void main(String[] args) {

System.out.println("Plz enter something to reverse: ");

// input of the sentence
Scanner scanner = new Scanner(System.in);

String inputString = scanner.nextLine();

// String is immutable
String reversedInputString = reversingMethod(inputString);

System.out.println(
       "\n***********************\nThe reversed sentence of \' " + inputString + " \' is: " + reversedInputString);

scanner.close();
}
}

