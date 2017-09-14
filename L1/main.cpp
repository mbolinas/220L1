/*
 * Marc Bolinas
 * Brian Philips
 *
 * NAME OF TA
 *
 * 9/3/17
 * LAB 1
 *
 * main.cpp :
 *
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <array>
#include <list>
using namespace std;

bool isPrime(int i); //true if passed int is a prime, else false

int sum(int i, int j); //sum of numbers between, but not including, i and j

bool isLeapYear(int year); //true if passed year is a prime, else false

void findLeapYears(int startingYear); //prints out all years that are leap years for the next 400 years starting from passed year

void makePyramid(int i); //prints out "pyramid" of numbers. "size" of pyramid is determined by passed int

void findArmstrongNumbers(int end); //prints out Armstrong Numbers from 1 to the passed int

double findLargestNum(double array[], int arraySize); //returns largest number from the passed array

bool isPalindrome(double array[], int arraySize); //true if elements in the passed array are "mirrored" (i.e. {1,2,3,4,3,2,1}), else false

int NumToInt(list<int> lst, int arraySize); //concatenates a list of ints to a single int

int main() {
	cout << "Hello world!" << " <--- PROBLEM 1" << endl;
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 2" << endl;
	cout << isPrime(2) << endl; //true
	cout << isPrime(7) << endl; //true
	cout << isPrime(6) << endl; //false
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 3" << endl;
	cout << sum(2, 3) << endl; //0
	cout << sum(2, 4) << endl; //3
	cout << sum(0, 3) << endl; //3
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 4" << endl;
	cout << isLeapYear(2016) << endl; //true
	cout << isLeapYear(2017) << endl; //false
	cout << isLeapYear(1900) << endl; //false
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 4.5" << endl;
	findLeapYears(1880); //see output
	cout << endl;
	findLeapYears(2017); //see output
	cout << endl;
	findLeapYears(2100); //see output
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 5" << endl;
	makePyramid(3); //see output
	makePyramid(5); //see output
	makePyramid(2); //see output
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 6" << endl;
	findArmstrongNumbers(80); //1-9
	findArmstrongNumbers(1000); //1-9, 370, 371, 407
	findArmstrongNumbers(10000); //1-9, 370,371, 407, 1634, 8208, 9474
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 7" << endl;
	double ar1[4] = { 1, 3, 3, 1 };
	double ar2[9] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	double ar3[12] = { 345, 6, 23, 426, 235, 6, 2, 46, 234, 6, 23, 4 };
	cout << findLargestNum(ar1, 4) << endl; //3
	cout << findLargestNum(ar2, 9) << endl; //5
	cout << findLargestNum(ar3, 12) << endl; //426
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 8" << endl;
	cout << isPalindrome(ar1, 4) << endl; //true
	cout << isPalindrome(ar2, 9) << endl; //true
	cout << isPalindrome(ar3, 12) << endl; //false
	cout << "********************************************************" << endl
			<< endl;

	cout << "PROBLEM 9" << endl;
	int ar4[8] = { 1, 2, 3, 4, 7, 2, 5, 3 };
	list<int> ls1(ar4, ar4 + 8);
	int ar5[9] = { 3, 3, 7, 2, 7, 2, 8, 3, 8 };
	list<int> ls2(ar5, ar5 + 9);
	int ar6[9] = { 8, 2, 6, 2, 9, 3, 1, 4, 8 };
	list<int> ls3(ar6, ar6 + 9);
	cout << NumToInt(ls1, 8) << endl; //12347253
	cout << NumToInt(ls2, 9) << endl; //337272838
	cout << NumToInt(ls3, 9) << endl; //826293148
	cout << "********************************************************" << endl
			<< endl;

	return 0;
}

//Problem 2

bool isPrime(int i) { //Iterates through all numbers from 1 to i, and uses modulus to see if it's a prime

	if (i == 1) {
		return false;
	}
	for (int c = 2; c < i; c++) {
		if (i % c == 0) {
			return false;
		}
	}
	return true;
}

//Problem 3

int sum(int i, int j) { //Sums all numbers between, but not including, i and j. Switches i and j if i > j

	if (i > j) {
		int temp = i;
		j = i;
		i = temp;
	}

	int sum = 0;
	while (i < (j - 1)) {
		i++;
		sum = sum + i;
	}
	return sum;
}

//Problem 4

bool isLeapYear(int year) { //True if leap year. 3 nested if-statements for all of the leap-year conditions.
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			} else {
				return false;
			}
		} else {
			return true;
		}
	} else {
		return false;
	}
}

void findLeapYears(int startingYear) { //Uses isLeapYear() to calculate the leap years for the next 400 years
	int endl_counter = 0;
	for (int endYear = startingYear + 400; startingYear <= endYear;
			startingYear++) {
		if (isLeapYear(startingYear)) {
			cout << startingYear << ", ";
			endl_counter++;
		}
		if (endl_counter >= 10) { //This is just to make it more legible
			endl_counter = 0;
			cout << endl;
		}
	}
	cout << " are leap years" << endl;
}

//Problem 5

void makePyramid(int i) { //Makes a "pyramid" of numbers, whose size is determined by i
	int offset = i - 1; //How many spaces to put before the numbers
	int spacing = -1; //How many spaces go between the numbers
	for (int start = 1; start <= i; start++) { //Each iteration is one layer of the pyramid

		for (int count = 0; count <= offset; count++) { //Prints out the spaces before the numbers
			cout << " ";
		}

		cout << start;
		for (int count = 0; count < spacing; count++) { //Prints out spaces (or numbers, if it's the last layer) between numbers
			if (start == i) {
				cout << start;
			} else {
				cout << " ";
			}
		}
		if (spacing > 0) { //Print out the second number of the pyramid. This if statement is for the first layer, "1"
			cout << start;
		}

		spacing = spacing + 2;
		offset--;
		cout << endl;
	}
}

//Problem 6

void findArmstrongNumbers(int end) { //Finds all Armstrong numbers from 1 to end
	for (int c = 1; c <= end; c++) {
		int array[100];
		int index = 0;
		int sum = 0;

		/*
		 * Mod 10 gets the rightmost number, which is placed into array
		 * Divide by 10 to shift the number to the right one place
		 * Extracts all individual numbers and places them into an array
		 */
		for (int temp = c; temp; index++) {
			array[index] = temp % 10;
			temp = temp / 10;
		}

		for (int count = 0; count < index; count++) { //Sums up all individual numbers raised to the length of the number
			sum = sum + pow(array[count], index);
		}

		if (sum == c) {
			cout << sum << ", ";
		}
	}
	cout << "are Armstrong Numbers" << endl;
}

//Problem 7

double findLargestNum(double array[], int arraySize) { //Returns largest number from given array

	int largest = array[0];
	for (int count = 1; count <= arraySize; count++) { //If given number is larger than current largest, set that to largest
		if (array[count] > largest) {
			largest = array[count];
		}
	}
	return largest;
}

//Problem 8

bool isPalindrome(double array[], int arraySize) {
	int start = 0;
	arraySize--;
	while (start < arraySize) { //Starting from both ends of the array, compare elements and continue moving to center
		if (array[start] != array[arraySize]) {
			return false;
		}
		//Works for both even and odd length arrays
		start++;
		arraySize--;
	}
	return true;

}

//Problem 9

int NumToInt(list<int> lst, int arraySize) { //takes a list of ints, concatenates them into a single int
	string str = "";
	for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it) { //list iterator
		str = str + to_string(*it); //c++ doesn't like adding an int to a string, so I had to convert to str first
	}
	return stoi(str);
}
