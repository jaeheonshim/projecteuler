package com.jaeheonshim.projecteuler;

public class Euler3 {
    static long number = 600851475143L;

    public static void main(String[] args) {
        long largestFactor = 1;
        long num = 1;
        while (num * num < number) {
            if (number % num == 0 && num > largestFactor) {
                if (isPrime(num)) {
                    largestFactor = num;
                }
            }
            num++;
        }
        System.out.println(largestFactor);
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
