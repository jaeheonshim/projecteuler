package com.jaeheonshim.projecteuler;

public class Euler10 {
    public static void main(String[] args) {
        long sum = 0;
        long prime = 2;
        while(prime < 2_000_000) {
            if(isPrime(prime)) {
                sum += prime;
            }
            prime++;
        }

        System.out.println(sum);
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
