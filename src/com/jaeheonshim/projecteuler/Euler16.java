package com.jaeheonshim.projecteuler;

import java.math.BigInteger;

public class Euler16 {
	 public static void main (String[] args) {
		  BigInteger integer = new BigInteger("2");
		  integer = integer.pow(1000);

		  int sum = 0;
		  for(String i : integer.toString().split("")) {
		  	 sum += Integer.parseInt(i);
		  }

		  System.out.println(sum);
		  // there's got to be a better way to do this
	 }
}
