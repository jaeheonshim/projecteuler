package com.jaeheonshim.projecteuler;

public class Euler4 {
    static final int MAX = 999;
    public static void main(String[] args) {
        int largestPalindromeProduct = 0;
        for(int i = 1; i <= MAX; i++) {
            for(int j = 1; j <= MAX; j++) {
                int product = j * i;
                String productString = String.valueOf(product);
                StringBuilder productReversed = new StringBuilder();
                productReversed.append(productString);
                productReversed.reverse();
                if(productReversed.toString().equals(productString) && product > largestPalindromeProduct) {
                    largestPalindromeProduct = product;
                }
            }
        }

        System.out.println(largestPalindromeProduct);
    }
}
