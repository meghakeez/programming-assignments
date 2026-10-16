/*
	Header file
	Contains preprocessors like #include, #define and function declarations/prototypes

*/

#ifndef header_h
#define header_h

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct duration
{
	int minutes,
		seconds;
} Duration;

typedef struct playlist
{
	char artist[200];
	char album_title[200];
	char song_title[200];
	char genre[200];
	Duration song_length;
	int times_played;
	int rating;

}Playlist;

typedef struct node
{
	Playlist data;
	struct node* pNext;
	struct node* pPrev;

}Node;

/*************************************************************
*Function: createNode()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function allocates space for a node
*Input parameters : Playlist newData (struct)
*Returns : Returns the newly created node
*Preconditions : Valid struct needs to be defined
*Postconditions : Returns the new node that has its data field set to the newData and its link pointers pointing to NULL
*************************************************************/
Node* createNode(Playlist newData);

/*************************************************************
*Function: insert_at_front()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function inserts the node at the front of the list
*Input parameters : Node **pList(pointer to node pointer), Playlist newData(struct)
*Returns : Returns 1 if node was inserted and 0 if it wasn't
*Preconditions : Valid head pointer and struct needs to be defined
*Postconditions : Returns an integer based on whether node was correctly inserted and head pointer was updated
*************************************************************/
int insert_at_front(Node** pList, Playlist newData);

/*************************************************************
*Function: load_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function loades the data in the file into the struct
*Input parameters : Node **pList(pointer to node pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to be defined
*Postconditions : Loads the information from file into the struct and then closes it for reading
*************************************************************/
void load_data(Node** pList);

/*************************************************************
*Function: store_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function overwrites the file with all the recent records from the struct 
*Input parameters : Node **pList(pointer to node pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to be defined
*Postconditions : Stores the data into the file and then closes it for writing
*************************************************************/
void store_data(Node** pList);

/*************************************************************
*Function: print_list()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : Helper function to display_data: prints entire list
*Input parameters : Node* pList(pointer to head pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to defined
*Postconditions : Prints the list
*************************************************************/
void print_list(Node* pList);

/*************************************************************
*Function: createNode()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : Helper function to display_data: prints one record
*Input parameters : Node* pList(pointer to head pointer)
*Returns : Does not return anything
*Preconditions :  Valid head pointer needs to defined
*Postconditions : Prints a single record
*************************************************************/
void print_single_artist(Node* pList);

/*************************************************************
*Function: display_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function displays the data based on the user's choice
*Input parameters : Node* pList(pointer to head pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to defined
*Postconditions : Prints full list or single record based on user's choice
*************************************************************/
void display_data(Node* pList);

/*************************************************************
*Function: insert_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function asks the user for the details of the new record and then inserts it at the front of the list
*Input parameters : Node** pList(pointer to node pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to be defined
*Postconditions : New record is inserted at front of playlist
*************************************************************/
void insert_data(Node** pList);

/*************************************************************
*Function: delete_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function asks the user for the song title they want to remove and then removes it from the list
*Input parameters : Node** pList(pointer to node pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to be defined
*Postconditions : Ensures the record is deleted from playlist
*************************************************************/
void delete_data(Node** pList);

/*************************************************************
*Function: edit_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function allows the user to edit the data from the record based on the artist name choosen
*Input parameters : Node* pList(pointer to head pointer)
*Returns : Does not return anything 
*Preconditions : Valid head pointer needs to defined
*Postconditions : Ensures the record has been edited and updated to the playlist
*************************************************************/
void edit_data(Node* pList);

/*************************************************************
*Function: sort_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function sorts the list based on the option choosen by user
*Input parameters :  Node** pList(pointer to node pointer)
*Returns : Does not return anything 
*Preconditions : Valid head pointer needs to be defined
*Postconditions : Ensures the list is sorted correctly
*************************************************************/
void sort_data(Node** pList);

/*************************************************************
*Function: rate_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function allows the user to rate a record based on the song title choosen
*Input parameters : Node* pList(pointer to head pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to be defined
*Postconditions : Ensures new rating entered is valid and list is updated
*************************************************************/
void rate_data(Node* pList);

/*************************************************************
*Function: play_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function plays the record starting from the song title choosen
*Input parameters : Node* pList(pointer to head pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to be defined
*Postconditions : Plays all the records in the playlist
*************************************************************/
void play_data(Node* pList);

/*************************************************************
*Function: generate_shuffle_order()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function generates a random shuffle order
*Input parameters : count(int)
*Returns : Returns a pointer to the list order created
*Preconditions : Valid integer value passed in
*Postconditions : Returns a pointer to an integer
*************************************************************/
int* generate_shuffle_order(int count);

/*************************************************************
*Function: play_shuffle()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function plays the shuffle order that is passed in
*Input parameters : Node* pList(pointer to head pointer), int* order(pointer to int), count(int)
*Returns : Does not return anything
*Preconditions : Valid head pointer, pointer to int and integer is passed in
*Postconditions : Plays the shuffle order
*************************************************************/
void play_shuffle(Node* pList, int* order, int count);

/*************************************************************
*Function: shuffle_data()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function implements both the previous helper shuffle functions
*Input parameters : Node* pList(pointer to head pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer passed in
*Postconditions : Shuffles the records in the playlist
*************************************************************/
void shuffle_data(Node* pList);


/*************************************************************
*Function: exit_program()
*Date Created : 9/21/2026
*Date Last Modified : 9/28/2026
*Description : This function stores the most recent list to the file, frees all the nodes and exits the program
*Input parameters : Node** pList(pointer to node pointer)
*Returns : Does not return anything
*Preconditions : Valid head pointer needs to be defined
*Postconditions : Exits the program
*************************************************************/
void exit_program(Node** pList);


#endif 
