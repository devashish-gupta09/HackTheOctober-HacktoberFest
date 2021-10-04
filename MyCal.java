package codingExamples;

import java.util.Scanner;

// This Java program performs operations of a basic calculator
public class MyCal {

	public static void main(String[] args) {
		
		// take user input
		Scanner reader = new Scanner(System.in);
		System.out.print("Enter any two numbers: ");
		
		double first = reader.nextDouble();
		double second = reader.nextDouble();
		
		System.out.print("Enter an operator (+, -, *, /): ");
		char operator = reader.next().charAt(0);
		
		double result;
		
		//To perform the calculation operation for each operator
		switch(operator)
		{
		case '+':
		result = first + second;
		break;
		case '-':
		result = first - second;
		break;
		case '*':
		result = first * second;
		break;
		case '/':
		result = first / second;
		break;
		
		// if operator doesn't match any case
		 
		 
		default:
		System.out.printf("Error! invalied operator. Please try again.");
		return;
		}
		//printing the result of the operations
		System.out.printf("%.1f %c %.1f = %.1f", first, operator, second, result);

	}

}
