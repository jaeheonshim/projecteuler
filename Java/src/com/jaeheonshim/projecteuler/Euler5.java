package com.jaeheonshim.projecteuler;

public class Euler5 {
    public static void main(String[] args) {
        int[] divisors = new int[] {
                11, 13, 14, 16, 17, 18, 19, 20
        };
        int number = 1;
        boolean perfect;
        do {
            perfect = true;
            number++;
            for(int integer : divisors) {
                if (number % integer != 0) {
                    perfect = false;
                    break;
                }
            }
        } while(!perfect);
        System.out.println(number);
    }
}
