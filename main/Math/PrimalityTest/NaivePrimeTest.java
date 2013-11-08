package main.Math.PrimalityTest;

import java.util.*;

public class NaivePrimeTest {
	public boolean primalityTest(long n) {
		// less than two isn't prime
		if (n < 2) {
			return false;
		}
		
		for (long i = 3; i <= Math.sqrt((double)n) + 1; i += 2) {
			if (n % i == 0) {
				return false;
			}
		}

		return true;
	}
}
