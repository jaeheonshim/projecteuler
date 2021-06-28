package com.jaeheonshim.projecteuler;

public class Euler6 {
    public static void main(String[] args) {
        int squaresSum = 0;
        int sumSquared = 0;
        for(int i = 1; i <= 100; i++) {
            squaresSum += Math.pow(i, 2);
            sumSquared += i;
        }

        sumSquared = (int) Math.pow(sumSquared, 2);

        System.out.println(Math.abs(sumSquared - squaresSum));
    }
}
