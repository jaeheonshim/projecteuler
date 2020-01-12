package com.jaeheonshim.projecteuler;

public class Euler9 {
    public static void main(String[] args) {
        for(int i = 1; i <= 1000; i++) {
            for(int j = 1; j <= 1000; j++) {
                double sqrt = Math.sqrt(Math.pow(i, 2) + Math.pow(j, 2));
                if(sqrt + i + j == 1000) {
                    System.out.println(i * j * sqrt);
                }
            }
        }
    }
}
