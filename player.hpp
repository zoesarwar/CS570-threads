/*
 * Members: Zoe Sarwar, Patrick Perrine
 * Red IDs: 820523074, 820496635
 * Class Accounts: cssc0802, cssc0801
 * CS 570 - Operating Systems, Summer 2019
 * Assignment #1, Player
 * Filename player.hpp
 * Purpose: The header for the driver program
 *
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;
sem_t FLAG;		// Semaphore for critical section handling
ofstream myfile;	// Output file, "STACK.txt"

const char *cards[] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; // Card deck values

// Thread methods for each card type
void *DIAMOND(void *abs);
void *CLUB(void *abs);
void *HEART(void *abs);
void *SPADE(void *abs);

// Helper method for initializing file
void initialize_file();

