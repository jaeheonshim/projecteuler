package com.jaeheonshim.projecteuler;

public class Euler7 {
    public static void main(String[] args) {
        int iterator = 1;
        int number = 2;
        while(iterator <= 10001) {
            if(isPrime(number)) {
                iterator++;
            }
            number++;
        }
        System.out.println(number - 1);
    }

    public static boolean isPrime(long number) {
        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
}
