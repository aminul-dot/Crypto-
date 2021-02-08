# Cryptopp Library

Platform to be used: UNIX (Mandatory)
Background Knowledge Required: C++ Programming on UNIX System

Download and Learn CRYPTO++ Library.
Download Link: https://www.cryptopp.com/

Measure Execution Times for the following Algorithms. Run an algorithm 50 times in an iteration each
time with random inputs, and then measure the avg. execution time. Repeat the whole experiment for 5-6
times and again take the average of all the avg. execution times. (Disable CPU interrupt in your system
before your algorithm execution starts and enable again after the program execution, if possible [Ref:
https://linux-kernel-labs.github.io/master/labs/interrupts.html] ):-

# 1. AES: Encryption time & Decryption Time
# 2. 2-Key Triple-DES: Encryption time & Decryption Time
# 3. SHA-1
# 4. SHA-512

# Installation Crypto++ library

1- Open your terminal 

2- run the following commands:    
   
     sudo apt-get update
     sudo apt-get install libcrypto++-dev libcrypto++-doc libcrypto++-utils
    
3- congrat, you have intsalled crypto++ on your ubuntu

4- now, for the AES example 

6- now, open your terminal and go to the directory where u have stored the program

7- now type the following command: 

     g++ AES.cpp -o AesOutput -lcryptopp

8- now write the following: ./AesOutput

