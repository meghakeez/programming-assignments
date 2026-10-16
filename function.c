#include "header.h"

/*

	Contains function headers

*/


Node* createNode(Playlist newData)
{
	Node* pMem = malloc(sizeof(Node));

	if (pMem == NULL)
	{
		return NULL;
	}

	pMem->data = newData;
	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;

}

int insert_at_front(Node** pList, Playlist newData)
{
	Node* pMem = createNode(newData);

	if (pMem == NULL)
	{
		return 0;
	}

	pMem->pNext = *pList;
	pMem->pPrev = NULL;

	if ((*pList != NULL))
	{
		(*pList)->pPrev = pMem; //sets old header's pPrev pointer to point to new header
	}

	//updates head pointer
	*pList = pMem;
	return 1;

}




//stores data from file into struct
void load_data(Node** pList)
{
	FILE* infile = fopen("musicPlayList.csv", "r");

	if (infile == NULL)
	{
		printf("Error in opening file\n");
	}

	Playlist temp;
	char row[200] = "";

	while (fgets(row, sizeof(row), infile) != NULL) 
	{
	
		//if beginning of row starts with double quotes
		if (row[0] == '\"')
		{
			char* token = strtok(row, "\""); //gets artist's name
			strcpy(temp.artist, token);
			char name[50] = "";
			strcpy(name, &temp.artist[0]); //removes double quotes from token
			strcpy(temp.artist, name);

			printf("Checkpoint: Should print 5 times for 5 instances of double quotes\n");

		}

		else
		{
			char* token = strtok(row, ",");
			strcpy(temp.artist, token);

		}

		//char* token = strtok(row, ",");
		strcpy(temp.album_title, strtok(NULL, ","));

		//token = strtok(NULL, ",");
		strcpy(temp.song_title, strtok(NULL, ","));

		//token = strtok(NULL, ",");
		strcpy(temp.genre, strtok(NULL, ","));

		//token = strtok(NULL, ":");
		temp.song_length.minutes = atoi(strtok(NULL, ":"));

		//token = strtok(NULL, ",");
		temp.song_length.seconds = atoi(strtok(NULL, ","));

		//token = strtok(NULL, ",");
		temp.times_played = atoi(strtok(NULL, ","));

		//token = strtok(NULL, ",");
		temp.rating = atoi(strtok(NULL, ","));

		insert_at_front(pList, temp);

	}

	printf("Records successfully loaded\n");
	fclose(infile);

	return;

}



//writes all the current records from the struct to the file
void store_data(Node** pList)
{
	FILE* outfile = fopen("musicPlayList.csv", "w");

	if (outfile == NULL)
	{
		printf("Error in opening file\n");
	}

	Node* curr = *pList;

	while (curr != NULL)
	{
		fprintf(outfile, "%s,", curr->data.artist);
		fprintf(outfile, "%s,", curr->data.album_title);
		fprintf(outfile, "%s,", curr->data.song_title);
		fprintf(outfile, "%s,", curr->data.genre);
		fprintf(outfile, "%d:%d,", curr->data.song_length.minutes, curr->data.song_length.seconds);
		fprintf(outfile, "%d,", curr->data.times_played);
		fprintf(outfile, "%d,", curr->data.rating);
		fprintf(outfile, "\n");

		curr = curr->pNext;

	}

	printf("Records have been successfully written to file\n");

	fclose(outfile);
}

//prints entire list
void print_list(Node* pList)
{

	Node* curr = pList;

	while (curr != NULL)
	{
		printf("%s, ", curr->data.artist);
		printf("%s, ", curr->data.album_title);
		printf("%s, ", curr->data.song_title);
		printf("%s, ", curr->data.genre);
		printf("%d:%d, ", curr->data.song_length.minutes, curr->data.song_length.seconds);
		printf("%d, ", curr->data.times_played);
		printf("%d,", curr->data.rating);
		printf("\n");

		curr = curr->pNext;

	}

}

//prints single artist
void print_single_artist(Node* pList)
{

	printf("%s, ", pList->data.artist);
	printf("%s, ", pList->data.album_title);
	printf("%s, ", pList->data.song_title);
	printf("%s, ", pList->data.genre);
	printf("%d:%d, ", pList->data.song_length.minutes, pList->data.song_length.seconds);
	printf("%d, ", pList->data.times_played);
	printf("%d, ", pList->data.rating);
	printf("\n");

}

//displays the data and prints either entire list or one artist
void display_data(Node* pList)
{
	int choice = 0;
	char artist[200];

	if (pList == NULL)
	{
		printf("List is empty\n");
		return;
	}

	//else

	printf("Options:\n");
	printf("1. Print all records\n");
	printf("2. Print all records that match an artist\n");
	printf("Enter your choice(number): ");
	scanf("%d", &choice);
	getchar(); //removes newline

	if (choice == 1)
	{
		print_list(pList);
	}

	else if (choice == 2)
	{
		printf("Enter artist's name: ");
		fgets(artist, sizeof(artist), stdin);

		if (artist[strlen(artist) - 1] == '\n')
		{
			artist[strlen(artist) - 1] = '\0'; //removes newline
		}

		Node* curr = pList;
		int found = 0;

		while (curr != NULL)
		{
			if (strcmp(curr->data.artist, artist) == 0)
			{
				print_single_artist(curr);
				found = 1;
			}

			curr = curr->pNext; //searches list for artist's name
		}

		if (!found)
		{
			printf("No records were found for %s\n", artist);
		}

	}

	else
	{
		printf("Invalid choice\n");
	}

	Sleep(7000); //waites for 7 seconds
	system("cls"); //clears screen

}

//inserts new node into list
void insert_data(Node** pList)
{
	Playlist temp;
	int success_times_played = 0;
	int success_rating= 0;
	int success_seconds = 0;
	
	printf("Please enter the details of the new record\n");

	printf("Enter artist name: \n");
	fgets(temp.artist, sizeof(temp.artist), stdin);
	temp.artist[strcspn(temp.artist, "\n")] = '\0'; //replaces newline with null character

	printf("Enter album title: \n");
	fgets(temp.album_title, sizeof(temp.album_title), stdin);
	temp.album_title[strcspn(temp.album_title, "\n")] = '\0';

	printf("Enter song title: \n");
	fgets(temp.song_title, sizeof(temp.song_title), stdin);
	temp.song_title[strcspn(temp.song_title, "\n")] = '\0';

	printf("Enter genre: \n");
	fgets(temp.genre, sizeof(temp.genre), stdin);
	temp.genre[strcspn(temp.genre, "\n")] = '\0';

	printf("Enter song length (minutes): \n");
	scanf("%d", &temp.song_length.minutes);
	getchar();

	printf("Enter song length (seconds): \n");
	scanf("%d", &temp.song_length.seconds);
	getchar();
	if (temp.song_length.seconds < 0 || temp.song_length.seconds > 59)
	{
		printf("Invalid entry\n");
	}
	else
	{
		success_seconds = 1;
	}

	printf("Enter times played (has to be >= 0): \n");
	scanf("%d", &temp.times_played);
	getchar();
	if (temp.times_played >= 0)
	{
		success_times_played = 1;
	}
	else
	{
		printf("Invalid entry\n");
	}
		
	printf("Enter rating (1-5): \n");
	scanf("%d", &temp.rating);
	getchar();
	if (temp.rating < 1 || temp.rating > 5)
	{
		printf("Invalid entry\n");
	}
	else
	{
		success_rating = 1;
	}


	if (!success_times_played || !success_rating || !success_seconds)
	{
		printf("Record could not be inserted due to invalid data\n");
		return;
	}


	insert_at_front(pList, temp);
	printf("Records successully inserted at front of list\n");


}

//deletes data based on user's choice
void delete_data(Node** pList)
{

	if (*pList == NULL)
	{
		printf("List is empty\n");
		return;
	}

	Playlist temp;
	Node* curr = *pList;

	printf("Enter song title to remove: \n");
	fgets(temp.song_title, sizeof(temp.song_title), stdin);
	temp.song_title[strcspn(temp.song_title, "\n")] = '\0';

	while (curr != NULL)
	{

		if (strcmp(curr->data.song_title, temp.song_title) == 0)
		{
			Node* prev = curr->pPrev;
			Node* next = curr->pNext;

			//if record is first in the list
			if (prev == NULL)
			{
				*pList = next;

				if (next != NULL)
				{
					next->pPrev = NULL;
				}

			}

			//if record is in the middle or end of list
			else
			{
				prev->pNext = next;

				if (next != NULL)
				{
					next->pPrev = prev;
				}
		

			}

			free(curr);
			printf("Song successfully deleted\n");
			return;

		}

		else
		{

			curr = curr->pNext;

		}


	}

	printf("Song was not found in the list\n");
}

//allows the user to edit attributes of one record
void edit_data(Node* pList)
{

	char artist[200];

	if (pList == NULL)
	{
		printf("List is empty\n");
		return;
	}

	//else
	printf("Enter the name of the artist to edit: ");
	fgets(artist, sizeof(artist), stdin);

	if (artist[strlen(artist) - 1] == '\n')
	{
		artist[strlen(artist) - 1] = '\0'; //removes newline
	}

	Node* matches[50]; //stores records that match artist's name
	int count = 0; //number of matches found

	Node* curr = pList;

	while (curr != NULL)
	{
		if (strcmp(curr->data.artist, artist) == 0)
		{
			matches[count] = curr;
			count++;
		}

		curr = curr->pNext; //increments the list


	}

	if (count == 0)
	{
		printf("No records were found for %s\n", artist);
		return;
	}

	int choice = 0; //stores the record that is choosen to be edited

	//One match was found
	if (count == 1)
	{
		choice = 1;
	}

	else
	{
		printf("Multiple records were found\n");

		for (int i = 0; i < count; i++)
		{
			printf(" %d. %s, %s\n", i + 1, matches[i]->data.artist, matches[i]->data.song_title);
			printf("\n");
		}


		printf("Enter the record you want to edit(number): ");
		scanf("%d", &choice);
		getchar();

		if (choice < 1 || choice > count)
		{
			printf("Invalid selection\n");
			return;
		}
	}

	Node* target = matches[choice - 1]; //accounts for index number

	printf("Enter new artist: ");
	fgets(target->data.artist, 200, stdin);
	if (target->data.artist[strlen(target->data.artist) - 1] == '\n')
	{
		target->data.artist[strlen(target->data.artist) - 1] = '\0'; //removes newline
	}

	printf("Enter new album title: ");
	fgets(target->data.album_title, 200, stdin);
	if (target->data.album_title[strlen(target->data.album_title) - 1] == '\n')
	{
		target->data.album_title[strlen(target->data.album_title) - 1] = '\0'; //removes newline
	}

	printf("Enter new song title: ");
	fgets(target->data.song_title, 200, stdin);
	if (target->data.song_title[strlen(target->data.song_title) - 1] == '\n')
	{
		target->data.song_title[strlen(target->data.song_title) - 1] = '\0'; //removes newline
	}

	printf("Enter new genre: ");
	fgets(target->data.genre, 200, stdin);
	if (target->data.genre[strlen(target->data.genre) - 1] == '\n')
	{
		target->data.genre[strlen(target->data.genre) - 1] = '\0'; //removes newline
	}

	printf("Enter new song length (minutes seconds): ");
	scanf("%d %d", &target->data.song_length.minutes, &target->data.song_length.seconds);

	printf("Enter new times played: ");
	scanf("%d", &target->data.times_played);

	printf("Enter new rating: ");
	scanf("%d", &target->data.rating);

	getchar();

	printf("Record updated successfully\n");

}


//allows  the user to enter a rating for a song
void rate_data(Node* pList)
{
	if (pList == NULL)
	{
		return;
	}

	char title[200];

	printf("Enter the song title you want to rate: ");
	fgets(title, sizeof(title), stdin);

	if (title[strlen(title) - 1] == '\n')
	{
		title[strlen(title) - 1] = '\0';
	}

	Node* curr = pList;
	Node* target = NULL;

	while (curr != NULL)
	{
		if (strcmp(curr->data.song_title, title) == 0)
		{
			target = curr;
			break;
		}

		curr = curr->pNext;

	}

	if (target == NULL)
	{
		printf("Song not found\n");
		return;
	}

	int new_rating = 0;
	printf("Assign a rating between 1-5 (1 is the lowest and 5 is the highest): ");
	scanf("%d", &new_rating);
	getchar();

	if (new_rating < 1 || new_rating > 5)
	{
		printf("Invalid rating\n");
		return;
	}

	target->data.rating = new_rating;

	printf("Rating updated successfully\n");


}

//sort's data based on user's choice
void sort_data(Node** pList)
{

	if (*pList == NULL || (*pList)->pNext == NULL)
	{
		printf("List is too small to sort\n");
		return;
	}

	int choice;

	printf("Please Choose a Sorting Method (enter number):\n");
	printf("1. Based on Artist (A-Z)\n");
	printf("2. Based on Album Title (A-Z)\n");
	printf("3. Based on Rating (1-5)\n");
	printf("4. Based on Times Played (largest-smallest)\n");
	scanf("%d", &choice);
	getchar();

	int swapped;

	do
	{

		Node* curr = *pList;
		swapped = 0;

		while (curr->pNext != NULL)
		{

			Node* next = curr->pNext;

			int compare = 0;

			switch (choice)
			{
				case 1: //Based on Artist
					compare = strcmp(curr->data.artist, next->data.artist) > 0;
					break;

				case 2: //Based on Album title
					compare = strcmp(curr->data.album_title, next->data.album_title) > 0;
					break;

				case 3: //Based on rating
					compare = curr->data.rating > next->data.rating;
					break;

				case 4: //Based on times played
					compare = curr->data.times_played < next->data.times_played;
					break;

				default:
					printf("Invalid choice\n");
					return;

			}

			//swaps the data between the 2 nodes
			if (compare)
			{
				Playlist temp = curr->data;
				curr->data = next->data;
				next->data = temp;
				swapped = 1;



			}

			curr = curr->pNext;


		}


	} while(swapped);

	
	printf("List successfully sorted\n");

}

//allows the user to start playing the songs in order starting from the current song
void play_data(Node* pList)
{
	

	if (pList == NULL)
	{
		printf("List is empty\n");
		return;
	}

	char title[200];

	printf("Enter the song title you want to start playing from: ");
	fgets(title, sizeof(title), stdin);

	if (title[strlen(title) - 1] == '\n')
	{
		title[strlen(title) - 1] = '\0';
	}


	Node* curr = pList;

	while (curr != NULL)
	{

		if (strcmp(curr->data.song_title, title) == 0)
		{
			break;
		}
		curr = curr->pNext;
	}

	if (curr == NULL)
	{
		printf("Song not found\n");
		return;
	}

	Node* start = curr;

	//Plays the playlist starting from the choosen song to the end
	while (curr != NULL)
	{
		printf("Now playing:\n");
		printf("Artist: %s\n", curr->data.artist);
		printf("Album: %s\n", curr->data.album_title);
		printf("Song: %s\n", curr->data.song_title);
		printf("Genre: %s\n", curr->data.genre);
		printf("Length: %d:%d\n", curr->data.song_length.minutes, curr->data.song_length.seconds);
		printf("Times played: %d\n", curr->data.times_played);
		printf("Rating: %d\n", curr->data.rating);


		Sleep(5000); //waites for 5 seconds
		system("cls"); //clears screen

		curr = curr->pNext;

	}

	curr = pList; //resetting curr to point to the head pointer

	//Plays the playlist as long as curr is not equal to choosen song
	while (curr != start)
	{
		printf("Now playing:\n");
		printf("Artist: %s\n", curr->data.artist);
		printf("Album: %s\n", curr->data.album_title);
		printf("Song: %s\n", curr->data.song_title);
		printf("Genre: %s\n", curr->data.genre);
		printf("Length: %d:%d\n", curr->data.song_length.minutes, curr->data.song_length.seconds);
		printf("Times played: %d\n", curr->data.times_played);
		printf("Rating: %d\n", curr->data.rating);

		Sleep(5000); //waites for 5 seconds
		system("cls"); //clears screen

		curr = curr->pNext;

	}

	printf("Finished playing all songs\n");

}

//generates order for random shuffle
int* generate_shuffle_order(int count)
{
	
	int* list_order = malloc(count * sizeof(int)); //pointer points to list that holds all the positions

		for (int i = 0; i < count; i++)
		{
			list_order[i] = i +1;  //initializes the array with sequential numbers
		}
	
	
		for (int i = count - 1; i > 0; i--)
		{
			int j = rand() % (i + 1); //generates random index number
	
			int temp = list_order[i];
			list_order[i] = list_order[j];
			list_order[j] = temp;
		}

		return list_order;

}



//plays the random shuffle order
void play_shuffle(Node* pList, int* list_order, int count)
{

	Node* curr = pList;
	int curr_position = 1;
	
	for (int i = 0; i < count; i++)
	{
	
		int next_position = list_order[i]; //points to shuffled array

		//Moves forward
		while (next_position > curr_position)
		{
			curr = curr->pNext;
			curr_position++;
		}
	
		//Moves backwards
		while (next_position < curr_position)
		{
			curr = curr->pPrev;
			curr_position--;

		}
	
	
		//plays the songs (index is shuffled order and position is the location of the song in original list)
		printf("Now playing song at index %d and position %d:\n", i + 1, next_position);
		printf("Artist: %s\n", curr->data.artist);
		printf("Album: %s\n", curr->data.album_title);
		printf("Song: %s\n", curr->data.song_title);
		printf("Genre: %s\n", curr->data.genre);
		printf("Length: %d:%d\n", curr->data.song_length.minutes, curr->data.song_length.seconds);
		printf("Times played: %d\n", curr->data.times_played);
		printf("Rating: %d\n", curr->data.rating);
		printf("---------------------------------------------------------\n");
		
	}

}


//implements both the previous helper shuffle functions
void shuffle_data(Node* pList)
{

	if (pList == NULL)
	{
		printf("List is empty\n");
		return;
	}

	int count = 0;
	Node* curr = pList;
	
	//counts the records in the list
	while (curr != NULL)
	{
		curr = curr->pNext;
		count++;
	}

	//Generates random order for the shuffle
	int* order = generate_shuffle_order(count);

	//Plays the random shuffle order
	play_shuffle(pList, order, count);

	free(order);


}



//Saves the most recent list to the file and exits
void exit_program(Node** pList)
{

	if (*pList == NULL)
	{
		printf("List is empty\n");
		return;
	}

	else
	{
		store_data(pList); //stores the recent list to the CSV file
		printf("Playlist saved successfully\n");

	}

	//Freeing all the nodes
	Node* curr = *pList;
	Node* temp = NULL;

	while (curr != NULL)
	{
		temp = curr;
		curr = curr->pNext; //increments position in the list until all nodes are freed
		free(temp);
	}

	*pList = NULL;

	printf("Exiting program\n");

}




