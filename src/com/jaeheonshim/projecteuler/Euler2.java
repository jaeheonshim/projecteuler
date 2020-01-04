package com.jaeheonshim.projecteuler;

public class Euler2 {
    public static void main(String[] args) {
        int n1 = 0;
        int n2 = 1;
        int sum = 0;
        while(n2 < 4_000_000) {
            int result = n1 + n2;
            if(result % 2 == 0)
                sum += result;

            n1 = n2;
            n2 = result;
        }
        System.out.println(sum);
    }
}
