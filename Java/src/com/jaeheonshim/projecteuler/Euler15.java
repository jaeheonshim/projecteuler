package com.jaeheonshim.projecteuler;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class Euler15 {
	 static HashMap<List<Integer>, Long> cache = new HashMap<>();

	 public static void main (String[] args) {
		  System.out.println(countRoutes(20, 20));
	 }

	 public static long countRoutes (int m, int n) {
		  if (m == 0 || n == 0) {
				return 1;
		  } else if (cache.get(Arrays.asList(m, n)) != null) {
				return cache.get(Arrays.asList(m, n));
		  } else {
				cache.put(Arrays.asList(m, n), countRoutes(m, n - 1) + countRoutes(m - 1, n));
				return cache.get(Arrays.asList(m, n));
		  }
	 }
}
