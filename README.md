# RSA-Algorithm Implementation
#### CP 460: Applied Cryptography Group-11

### Group Members:
- Yash Rojiwadia 
- Jay Vora 
- Owen Milne 
- Dhruv Sagar 

## Project Objective
The objective of this project is to implement the RSA algorithm in C++. The implementation includes key generation, encryption, decryption, and 2^32 base arithmetic operations. The program can generate random public and private keys for RSA encryption, and it can encrypt and decrypt messages up to 3072 bits.

## Implementation Details
The implementation uses BigInteger numbers in C++ to perform basic operations on N-bit numbers. The project includes a script file, build.bash, that can be run to generate a random set of public and private keys and encrypt/decrypt a randomly generated message. The executable is generated in the /bin folder. If no input value is given, the program assumes the value of N to be 960 bits, but the input value can be changed from the script file.

## How to Run the Code
- The source files are in the /RSA-Implementation folder.
- Run the script file, build.bash, with the command `./build.bash` to run the code.
- The executable will take an input N where N represents the number of bits of the Algorithm (e.g., 1920). If no input value is given, the program assumes the value of N to be 960 bits.
- The input value can be changed from the script file by changing the last line of the build.bash file. (`./obj <desired value of N>`)

## References
- RSA Algorithm Example: https://www.cs.utexas.edu/~mitra/honors/soln.html
- Donald E. Knuth The Art Of Computer Programming 4.3.1 pages 266-273
- Sanjoy Dasgupta Algorithms
- Md Jubaer Hossain Pantho: https://github.com/jubaer-pantho/RSA-Implementation-Cpp 
