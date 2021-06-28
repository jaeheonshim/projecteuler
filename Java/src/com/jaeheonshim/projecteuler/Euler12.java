package com.jaeheonshim.projecteuler;

public class Euler12 {
	 public static void main (String[] args) {
		  for(int i = 1;; i++) {
		  	 int number = generateTriangularNumber(i);
		  	 int divisors = 0;
		  	 for(int j = 1; j <= Math.sqrt(number); j++) {
		  	 	 if(number % j == 0) {
		  	 	 	 divisors++;
				 }
			 }
		  	 if(divisors * 2 > 500) {
				  System.out.println(number);
				  return;
			 }
		  }
	 }

	 public static int generateTriangularNumber(int n) {
	 	 int sum = 0;
	 	 for(int i = 1; i <= n; i++) {
	 	 	 sum += i;
		 }
	 	 return sum;
	 }
}
