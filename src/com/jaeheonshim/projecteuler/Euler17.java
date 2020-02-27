package com.jaeheonshim.projecteuler;

import java.util.StringJoiner;

public class Euler17 {
    public static void main(String[] args) {
        int count = 0;
        for(int i = 1; i <= 1000; i++) {
            System.out.println(numberToString(i));
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
        String output = "";

        if(number < 10) {
            output = ones[number];
        } else if(number == 10) {
            output = "ten";
        } else if(number > 10 && number < 20) {
            output = special[number - 11];
        } else if(number >= 20 && number < 100) {
            String[] numberString = Integer.toString(number).split("");
            StringJoiner numberJoiner = new StringJoiner(" ");

            numberJoiner.add(tens[Integer.parseInt(numberString[0])]);
            numberJoiner.add(ones[Integer.parseInt(numberString[1])]);

            output = numberJoiner.toString();
        } else if(number >= 100 && number < 1000) {
            String[] numberString = Integer.toString(number).split("");
            StringJoiner numberJoiner = new StringJoiner(" ");

            numberJoiner.add(ones[Integer.parseInt(numberString[0])]);
            numberJoiner.add("hundred");
            if(Integer.parseInt(numberString[1]) != 0 || Integer.parseInt(numberString[2]) != 0) {
                numberJoiner.add("and");
                if(Integer.parseInt(numberString[1] + numberString[2]) > 10 && Integer.parseInt(numberString[1] + numberString[2]) < 20) {
                    numberJoiner.add(special[Integer.parseInt(numberString[1] + numberString[2]) - 11]);
                } else {
                    numberJoiner.add(tens[Integer.parseInt(numberString[1])]);
                    numberJoiner.add(ones[Integer.parseInt(numberString[2])]);
                }
                output = numberJoiner.toString();
            } else {
                output = numberJoiner.toString();
            }
        } else if(number == 1000) {
            output = "one thousand";
        }

        return output;
    }
}
