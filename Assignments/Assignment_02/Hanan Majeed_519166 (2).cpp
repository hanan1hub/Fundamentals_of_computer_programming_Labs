#include <iostream>
#include <iomanip> // Include for setw
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

// Task 1: Number Pattern

void pattern(int N) {
	for (int i = 1; i <= N; i++) {
		// Print leading spaces for alignment
		for (int j = i; j < N; j++) {
			cout << setw(3) << " "; // Set width for alignment
		}
		// Print increasing numbers
		for (int j = i; j < 2 * i; j++) {
			cout << setw(3) << j; // Set width for numbers
		}
		// Print decreasing numbers
		for (int j = 2 * i - 2; j >= i; j--) {
			cout << setw(3) << j; // Set width for numbers
		}
		cout << endl;
	}
	cout << endl;
}

// Task 2: Calculator

double addition(double f, double b) {
	return f + b; // Return the sum of f and b
}

double subtraction(double f, double b) {
	return f - b; // Return the difference of f and b
}

double multiplication(double f, double b) {
	return f * b; // Return the product of f and b
}

double division(double f, double b) {
	if (b == 0) {
		cout << "Error: Division by zero is not allowed." << endl; // Error message for division by zero
		return 0; // Return 0 if division by zero
	}
	return f / b; // Return the result of division
}

double remainder(double f, double b) {
	return fmod(f, b); // Return the remainder of f divided by b
}

double exponentiation(double f, double b) {
	return pow(f, b); // Return f raised to the power of b
}

// Calculator function to handle user interactions
void calculator() {
	double num1 = 0, num2 = 0; // Initialize numbers
	char option;

	while (true) {
		// Display current values of num1 and num2
		cout << "Current values - First number: " << num1 << "| Second number: " << num2 << endl;

		// Display operation menu
		cout << "Select An Operation:\n";
		cout << "\nn - Enter new numbers\n\n";
		cout << "a - Addition\n";
		cout << "s - Subtraction\n";
		cout << "m - Multiplication\n";
		cout << "d - Division\n";
		cout << "r - Remainder\n";
		cout << "e - Exponentiation\n";
		cout << "x - Exit\n";
		cout << "Select an option: ";
		cin >> option;

		if (option == 'x') {
			cout << "Exiting program..." << endl << endl;
			break;
		}

		if (option == 'n') {
			// Input new numbers
			cout << "Enter first number: ";
			cin >> num1;
			cout << "Enter second number: ";
			cin >> num2;
			continue;
		}

		// Perform the chosen operation based on user input
		switch (option) {
		case 'a':
			cout << "\nThe sum of " << num1 << " and " << num2 << " = " << addition(num1, num2) << endl << endl; // Addition result
			break;
		case 's':
			cout << "\nThe subtraction of " << num1 << " and " << num2 << " = " << subtraction(num1, num2) << endl << endl; // Subtraction result
			break;
		case 'm':
			cout << "\nThe multiplication of " << num1 << " and " << num2 << " = " << multiplication(num1, num2) << endl << endl; // Multiplication result
			break;
		case 'd':
			cout << "\nThe division of " << num1 << " and " << num2 << " = " << division(num1, num2) << endl << endl; // Division result
			break;
		case 'r':
			cout << "\nThe remainder of " << num1 << " divided by " << num2 << " is: " << remainder(num1, num2) << endl << endl; // Remainder result
			break;
		case 'e':
			cout << "\nThe exponentiation of " << num1 << " and " << num2 << " = " << exponentiation(num1, num2) << endl << endl; // Exponentiation result
			break;
		default:
			cout << "\nInvalid input! Please choose a valid option." << endl;
			break;
		}
	}
}

// Task 3: Number Guessing Game

void guessing_game() {
	srand(static_cast<unsigned int>(time(0))); // Seed random number generator
	int secretNumber = rand() % 1000 + 1; // Generate a secret number between 1 and 1000
	cout << "Welcome to the Number Guessing Game!" << endl;
	cout << "I have chosen a secret number for you to guess!" << endl;
	cout << "\tLet's start!" << endl;
	int attempts = 0; // Counter for attempts
	int guess;
	int total_points = 1000; // Starting points for the game

	while (true) {
		cout << "Enter your guess (between 1 and 1000):";
		cin >> guess;

		// Input validation for guess
		if (guess < 1 || guess > 1000) {
			cout << "invalid input::Please enter a number between 1 and 1000." << endl;
			continue;
		}

		attempts++; // Increment attempt count after valid input

		// Check if the guess is correct
		if (guess == secretNumber) {
			cout << "Congratulation! You guessed the number in " << attempts << " attempts." << endl;
			break; // Exit loop if guessed correctly
		}
		// Provide feedback based on the guess
		else if (guess > secretNumber + 200) {
			cout << "Your guess is too high!" << endl;
		}
		else if (guess > secretNumber + 10) {
			cout << "Your guess is high!" << endl;
		}
		else if (guess > secretNumber) {
			cout << "Your guess is slightly high!" << endl;
		}
		else if (guess < secretNumber - 200) {
			cout << "Your guess is too low!" << endl;
		}
		else if (guess < secretNumber - 10) {
			cout << "Your guess is low!" << endl;
		}
		else {
			cout << "Your guess is slightly low!" << endl;
		}

		int difference = guess - secretNumber;
		if (difference < 0) {
			difference *= -1; // Make difference positive if negative
		}

		// Apply penalties based on the difference
		if (difference >= 500) {
			cout << "Penalty Applied ::";
			cout << "100 points deducted because difference is greater than 500." << endl;
			total_points -= 100;
			cout << "Remaining points: " << total_points << endl; // Display remaining points
		}
		else if ((difference <= 500) && (difference >= 301)) {
			cout << "Penalty Applied::";
			cout << "50 points deducted because difference is between 301 and 500." << endl;
			total_points -= 50;
			cout << "Remaining points: " << total_points << endl; // Display remaining points
		}
		else if ((difference <= 300) && (difference >= 201)) {
			cout << "Penalty Applied::";
			cout << "30 points deducted because difference is between 201 and 300." << endl;
			total_points -= 30;
			cout << "Remaining points: " << total_points << endl; // Display remaining points
		}
		else if ((difference <= 200) && (difference >= 101)) {
			cout << "Penalty Applied::";
			cout << "20 points deducted because difference is between 101 and 200." << endl;
			total_points -= 20;
			cout << "Remaining points: " << total_points << endl; // Display remaining points
		}
		else if ((difference <= 100) && (difference >= 11)) {
			cout << "Penalty Applied::";
			cout << "10 points deducted because difference is between 11 and 100." << endl;
			total_points -= 10;
			cout << "Remaining points: " << total_points << endl; // Display remaining points
		}

		// Additional penalty based on number of attempts
		cout << "Additional Penalty Applied for  attempts ::";
		if ((attempts <= 2) && (attempts <= 5)) {
			cout << "10 points subtracted" << endl; // Penalty for fewer attempts
			total_points -= 10;
			cout << "Remaining points: " << total_points << endl;
		}
		else if ((attempts <= 6) && (attempts <= 10)) {
			cout << "20 points subtracted" << endl; // Penalty for more attempts
			total_points -= 20;
			cout << "Remaining points: " << total_points << endl;
		}
		else {
			cout << "50 points subtracted" << endl; // Penalty for many attempts
			cout << "remaining points" << total_points << endl;
			total_points -= 50;
			cout << "Remaining points: " << total_points << endl; // Display remaining points
		}
	}

	// Award bonus points based on attempts
	if (attempts <= 3) {
		cout << "bonus points awarded for fewer attempts::";
		cout << "200 bonus points awarded." << endl;
		total_points += 200; // Add bonus points
	}
	if ((attempts > 3) && (attempts <= 6)) {
		cout << "bonus points awarded for fewer attempts::";
		cout << "100 bonus points awarded." << endl;
		total_points += 100; // Add bonus points
	}

	// Display final points and thank the user
	cout << "final remaining points=" << total_points << endl;
	cout << "Thanks For Playing!\n" << endl;
}

int main() {
	while (true) {
		int option;
		cout << "welcome to Hanan Majeed's Assignment 2:" << endl; // Welcome message
		cout << "\tMain SELECTION MENU\n";
		cout << "1- Task 1 (Number Pattern)\n";
		cout << "2- Task 2 (Calculator)\n";
		cout << "3- Task 3 (Guessing Game)\n";
		cout << "4- Exit The Whole Program \n"; // Option to exit
		cout << "select an option to evaluate a task :";
		cin >> option;

		if (option == 4) {
			cout << "Exiting The Program ...\n";
			break;
		}


		switch (option) {
		case 1: {
			cout << "\n\tEvaluating Task 1\n\n";
			int N; // Variable to store user input for pattern size
			cout << "Enter a number : ";
			cin >> N;
			pattern(N); // Call pattern function
			break;
		}
		case 2: {
			cout << "\n\tEvaluating Task 2\n\n";
			calculator(); // Call calculator function
			break;
		}
		case 3: {
			cout << "\n\tEvaluating Task 3\n\n";
			guessing_game(); // Call guessing game function
			break;
		}
		default: {
			cout << "invalid input please select from following menu ";
			break;
		}
		}
	}
	return 0;
}
