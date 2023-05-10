# Vigenere-Cypher

Vigenere Cypher project for CIS-7 Discrete Structures Class.

# Development Branch

# 05/04/2023 - Anthony Truong and Nour Siwar

- Reviewed git flow commands.

# 05/09/2023 - Anthony Truong

- Write up initial main and encrypt function.
- Finished encrypt function pseudocode / flowchart.

## What problems are you solving?

- The main problem when starting this project was to figure out how the encryption works under the hood. How does the plaintext get encrypted with the user provided keyword? How does the encryption itself work? What is vigenere cipher?

## Provide explanation of calculations and algorithm implementation.

- The program takes utilizes the encryption formula of: E = (P + K) mod 26.
- In order to achieve the encryption, this formula must be implemented into the program. The encrypted message takes the "P" array of ASCII values and adds to it the "K" (keyword) array of ASCII values. After the sum if found, we do mod 26 to obtain a new ASCII value. After this ASCII value is found, you can add 65 to obtain all uppercase letters.
- "E" represents the encrypted message array of ASCII values.
- "P" represents the plain text array of ASCII values.
- "K" represents the keyword array of ASCII values.
- Must convert the encrypted message array characters. Failure to do so will present a blank output (due to the array holding ASCII values instead of actual char values).
