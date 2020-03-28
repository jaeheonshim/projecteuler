package com.jaeheonshim.projecteuler;

import java.util.Arrays;

public class Euler18 {
    static final int[][] triangle = {
            {75},
            {95, 64},
            {17, 47, 82},
            {18, 35, 87, 10},
            {20, 4, 82, 47, 65},
            {19, 1, 23, 75, 3, 34},
            {88, 2, 77, 73, 7, 63, 67},
            {99, 65, 4, 28, 6, 16, 70, 92},
            {41, 41, 26, 56, 83, 40, 80, 70, 33},
            {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
            {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
            {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
            {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
            {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
            {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
    };

    static final int[][] demoTriangle = {
            {3},
            {7, 4},
            {2, 4, 6},
            {8, 5, 9, 3}
    };

    public static void main(String[] args) {
        int[][] newTriangle = triangle;
        while(newTriangle.length > 1) {
            newTriangle = updateTriangle(newTriangle.length - 2, newTriangle);
        }

        System.out.println(Arrays.deepToString(newTriangle));
    }

    public static int[][] updateTriangle(int top, int[][] triangle) {
        int newTriangleDepth = triangle.length - (triangle.length - top) + 1;

        int[][] newTriangle = new int[newTriangleDepth][];

        for(int i = 0; i < newTriangleDepth - 1; i++) {
            newTriangle[i] = triangle[i];
        }

        newTriangle[newTriangleDepth - 1] = calculateLayer(top, triangle);

        return newTriangle;
    }

    public static int[] calculateLayer(int top, int[][] triangle) {
        int layerLength = 0;
        for(int digit : triangle[top]) {
            if(digit != 0) {
                layerLength++;
            } else {
                break;
            }
        }
        int[] layer = triangle[top];
        int[] calculatedLayer = new int[layerLength];

        for(int i = 0; i < layerLength; i++) {
            int candidate1 = triangle[top + 1][i];
            int candidate2 = triangle[top + 1][i + 1];

            calculatedLayer[i] = Math.max(layer[i] + candidate1, layer[i] + candidate2);
        }

        return calculatedLayer;
    }
}