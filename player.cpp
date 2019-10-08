/*
 * Members: Zoe Sarwar, Patrick Perrine
 * Red ID: 820523074, 820486635
 * Class Accounts: cssc0802, cssc0801
 * CS 570 - Operating Systems, Summer 2019
 * Assignment #1, Player
 * Filename: player.cpp
 * Purpose: The driver for creating and running threads concurrently
*/

#include "player.hpp"

// Thread for printing Diamond Cards
// Note: Comments within this method apply to the other three thread methods
void *DIAMOND(void *abs) {

	int thread_id = (int)(size_t)pthread_self();
	
	usleep(125000);	//Initial sleep to negate starting conflicts (125 ms)
	for(int a = 0; a < 14; a++) {	// Prints 13 cards
		sem_wait(&FLAG);	// Increments semaphore
		myfile.open("STACK.txt", ios_base::out | ios_base::app);
		myfile << "Diamond " << cards[a] << "\n";	// Prints card
		cout << "Thread:" << thread_id << " is running\n";
		myfile.close();
		sem_post(&FLAG);	// Decrements semaphore
		usleep(125000);		// Sleep for 125 ms
	}
	pthread_exit(NULL);
}


// Thread for printing Club cards
void *CLUB(void *abs) {

	int thread_id = (int)(size_t)pthread_self();
    	
	usleep(250000);
	for(int c = 0; c < 14; c++) {
		sem_wait(&FLAG);
		myfile.open("STACK.txt", ios_base::out | ios_base::app);
		myfile << "Club " << cards[c] << "\n";
		cout << "Thread:" << thread_id << " is running\n";
		myfile.close();
		sem_post(&FLAG);
		usleep(250000);		// Sleep for 250 ms
	}
	pthread_exit(NULL);
}

// Thread for printing Heart cards
void *HEART(void *abs) {
    
	int thread_id = (int)(size_t)pthread_self();       
   
	usleep(500000);
	for(int x = 0; x < 14; x++) {
		sem_wait(&FLAG);
		myfile.open("STACK.txt", ios_base::out | ios_base::app);
		myfile<< "Heart " << cards[x] << "\n";
		cout << "Thread:" << thread_id << " is running\n";
		myfile.close();
		sem_post(&FLAG);
		usleep(500000);		// Sleep for 500 ms
	}
	pthread_exit(NULL);
}

// Thread for printing Spade cards
void *SPADE(void *abs) {

	int thread_id = (int)(size_t)pthread_self();    
	
	usleep(750000);
	for(int b = 0; b < 14; b++) {
		sem_wait(&FLAG);
		myfile.open("STACK.txt", ios_base::out | ios_base::app);
		myfile << "Spade " << cards[b] << "\n";
		cout << "Thread:" << thread_id << " is running\n";
		myfile.close();
		sem_post(&FLAG);
		usleep(750000);		// Sleep 750 ms
	}
	pthread_exit(NULL);
}


// Creates output file, prints process ID, then closes it
void initialize_file() {	
    myfile.open("STACK.txt", ios_base::out | ios_base::app);
    myfile << "PID: " << getpid() << "\n";
    myfile.close();
}

// Main function for creating threads and running them
int main() {
    initialize_file();
    
    sem_init(&FLAG,0,56);

    int id[4] = {0, 1, 2, 3}; // Process ID array
   
    // Initialize threads
    pthread_t thread_spade;
    pthread_t thread_heart;
    pthread_t thread_club;
    pthread_t thread_diamond;
    
    // Create each thread, check for error in creation
    int statusW = pthread_create(&thread_spade, NULL, SPADE, (void*) &id[0]);
    if(statusW){
        cout << "pthread_create returned error code status(in spade):" << statusW << endl;
        return 0;
    }

    int statusZ = pthread_create(&thread_heart, NULL, HEART, (void*) &id[1]);
    if(statusZ){
         cout << "pthread_create returned error code status(in heart):" << statusZ << endl;
        return 0;
    }

    int statusY = pthread_create(&thread_club, NULL, CLUB, (void*) &id[2]);
    if(statusY){
        cout << "pthread_create returned error code status(in club):" << statusY << endl;
        return 0;
    }

    int statusX = pthread_create(&thread_diamond, NULL, DIAMOND, (void*) &id[3]);
    if(statusX){
       cout << "pthread_create returned error code status(in diamond):" << statusX << endl;
        return 0;
    }
    
    // Join and run each thread concurrently
    pthread_join(thread_spade, NULL);
    pthread_join(thread_heart, NULL);
    pthread_join(thread_club, NULL);
    pthread_join(thread_diamond, NULL);

    // With threads finished, destroy semaphore and print success method
    sem_destroy(&FLAG);
    cout << "All threads are done!" << endl;
    
    return 0;	// Exit program
}
