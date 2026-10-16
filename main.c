#include "header.h"
#include "TestHeader.h"

/*
	Name: Megha Keezhanjil
	Course: CptS 122, Fall 2026 Lab Section 3
	Lab Assignment: Programming Assignment 3
	Date: 8/30/2026
	Description: Digital Music Manager

*/


int main(void)
{



	printf("--------------------------Testing Environment---------------------------------\n");


	TestInsertData();
	TestDeleteData();
	TestShuffleData();

	printf("-----------------------End of Testing------------------------------------------\n");

	srand(time(NULL)); //generates a random order everytime program in compiled
	Node* pHead = NULL;

	int choice = 0;

	do
	{
		printf("Welcome to the Digital Music Manager!\n");
		printf("1. Load\n");
		printf("2. Store\n");
		printf("3. Display\n");
		printf("4. Insert\n");
		printf("5. Delete\n");
		printf("6. Edit\n");
		printf("7. Sort\n");
		printf("8. Rate\n");
		printf("9. Play\n");
		printf("10. Shuffle\n");
		printf("11. Exit\n");
		printf("Choose which option you want: \n");
		scanf("%d", &choice);
		getchar(); //removes newline

		switch (choice)
		{
		case 1:
			load_data(&pHead);
			break;

		case 2:
			store_data(&pHead);
			break;

		case 3:
			display_data(pHead);
			break;

		case 4:
			insert_data(&pHead);
			break;

		case 5:
			delete_data(&pHead);
			break;

		case 6:
			edit_data(pHead);
			break;

		case 7:
			sort_data(&pHead);
			break;

		case 8:
			rate_data(pHead);
			break;

		case 9:
			play_data(pHead);
			break;

		case 10:
			shuffle_data(pHead);
			break;

		case 11:
			exit_program(&pHead);
			break;

		default:
			printf("Invalid choice\n");
		}


	} while (choice != 11);

	return 0;
}