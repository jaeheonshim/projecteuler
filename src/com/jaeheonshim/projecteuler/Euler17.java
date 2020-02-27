package com.jaeheonshim.projecteuler;

import java.util.StringJoiner;

public class Euler17 {
    public static void main(String[] args) {
        int count = 0;
        for(int i = 1; i <= 1000; i++) {
            count += numberToString(i).replace(" ", "").split("").length;
        }

        System.out.println(count);
    }

    private static String[] tens = new String[] {
            "",
            "ten",
            "twenty",
            "thirty",
            "forty",
            "fifty",
            "sixty",
            "seventy",
            "eighty",
            "ninety"
    };

    private static String[] ones = {
            "",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"
    };

    private static String[] special = {
            "eleven",
            "twelve",
            "thirteen",
            "fourteen",
            "fifteen",
            "sixteen",
            "seventeen",
            "eighteen",
            "nineteen"
    };

    public static String numberToString(int number) {
        if(number < 10) {
            return ones[number];
        } else if(number == 10) {
            return "ten";
        } else if(number < 20) {
            return calculateSpecialNumbers(number);
        } else if(number < 100) {
            return calculateTwoDigit(number);
        } else if(number < 1000) {
            String[] numberString = Integer.toString(number).split("");
            StringJoiner numberJoiner = new StringJoiner(" ");

            numberJoiner.add(ones[Integer.parseInt(numberString[0])]);

            numberJoiner.add("hundred");
            if(Integer.parseInt(numberString[1]) != 0 || Integer.parseInt(numberString[2]) != 0) {
                numberJoiner.add("and");
                String lastTwo = numberString[1] + numberString[2];

                if(Integer.parseInt(lastTwo) > 10 && Integer.parseInt(lastTwo) < 20) {
                    numberJoiner.add(calculateSpecialNumbers(Integer.parseInt(lastTwo)));
                } else {
                    numberJoiner.add(calculateTwoDigit(Integer.parseInt(lastTwo)));
                }
            }
            return numberJoiner.toString();
        } else if(number == 1000) {
            return "one thousand";
        } else {
            return null;
        }
    }

    public static String calculateSpecialNumbers(int number) {
        return special[number - 11];
    }

    public static String calculateTwoDigit(int number) {
        String[] numberString = Integer.toString(number).split("");
        StringJoiner numberJoiner = new StringJoiner(" ");

        if(numberString.length > 1) {
            numberJoiner.add(tens[Integer.parseInt(numberString[0])]);
            numberJoiner.add(ones[Integer.parseInt(numberString[1])]);
        } else {
            numberJoiner.add(ones[Integer.parseInt(numberString[0])]);
        }

        return numberJoiner.toString();
    }
}
