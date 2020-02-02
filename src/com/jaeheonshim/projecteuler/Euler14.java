package com.jaeheonshim.projecteuler;

public class Euler14 {
	 public static void main (String[] args) {
		  int longestLength = 0;
		  int longestNumber = 0;

		  for (int i = 2; i < 1_000_000; i++) {
				long number = i; // this NEEDS to be a long
				int length = 1;
				while (number > 1) {
					 if (number % 2 == 0) {
					 	 number = number / 2;
					 } else {
					 	 number = (number * 3) + 1;
					 }
					 length += 1;
				}

				if(length > longestLength) {
					 longestLength = length;
					 longestNumber = i;
				}
		  }

		  System.out.println(longestNumber);
	 }
}
