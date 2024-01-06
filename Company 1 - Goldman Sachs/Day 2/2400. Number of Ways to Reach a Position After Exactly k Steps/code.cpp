#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Modular exponentiation function
    long long modularExponentiation(long long base, long long exponent, long long modulus) {
        
        // Implements fast exponentiation using repeated squaring
        // Time complexity: O(log n)
        
        long long result = 1; 
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % modulus; // Multiply result by base if exponent is odd
            }
            base = (base * base) % modulus; // Square the base
            exponent = exponent / 2; // Halve the exponent
        }
        return result;
    }

    // Modular multiplicative inverse function
    long long modularMultiplicativeInverse(long long number, long long modulus) {
        
        // Uses Fermat's Little Theorem:
        // inverse(n) = n^(modulus - 2) (mod modulus)
        // Runs in O(log n) time
        
        return modularExponentiation(number, modulus - 2, modulus); 
    }

    // Combination function using factorial 
    long long combination(int n, int r, int modulus) {
        
        // Calculates nCr = n! / (r! * (n - r)!) (mod modulus)
        // Uses precomputed factorials to improve efficiency
        
        if (n < r) return 0; 
        if (r == 0) return 1;
        
        long long factorial[n+1];
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i-1] * i) % modulus; // Calculate factorials modulo modulus
        }

        long long numerator = factorial[n];
        long long denominator = (factorial[r] * factorial[n-r]) % modulus;
        long long moduloInverse = modularMultiplicativeInverse(denominator, modulus);
        return (numerator * moduloInverse) % modulus; // Divide using modular inverse
    }

    int numberOfWays(int startPos, int endPos, int k) {
        
        // Overall algorithm runs in O(1) time
        
        int distance = abs(endPos - startPos);
        
        if (k < distance) return 0; // Not enough steps
        else if (distance == k) return 1; // Only 1 way if steps = distance
        else if ((k - distance) % 2 != 0) return 0; // Odd steps remaining means no solution

        long long forwardSteps = distance + (k - distance) / 2; 
        long long backwardSteps = (k - distance) / 2;
        long long modulus = 1000000007;

        return combination(forwardSteps + backwardSteps, forwardSteps, modulus); // Use combination function
    }
};