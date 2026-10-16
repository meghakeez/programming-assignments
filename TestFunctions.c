#include "TestHeader.h"

void TestInsertData(void)
{

	Node* pList = NULL;

	printf("-------------------------------------------Testing Inserting Data-----------------------------------------------------\n");

	FILE* fake = fopen("fake_data.text", "w");
	fprintf(fake,
			"Perry, Katy\n"
			"Witness\n"
			"Chained to the Rhythm\n"
			"pop\n"
			"4\n"
			"36\n"
			"-1\n" //invalid data
			"6\n"
			"3\n"
			"5\n"); //invalid data
	fclose(fake);

	freopen("fake_data.text", "r", stdin);

	insert_data(&pList);

	if (pList == NULL)
	{
		printf("Invalid record was not inserted so test PASSED!\n");
	}
	else
	{

		printf("Invalid record was inserted so test FAILED!\n");
	}


	freopen("CON", "r", stdin); //restores stdin so that it reads from the keyboard instead of file
}



void TestDeleteData(void)
{
	Node* pList = NULL;

	printf("-----------------------------------------------Testing Deleting Data--------------------------------------------------------\n");

	Playlist temp;
	strcpy(temp.artist, "Perry, Katy");
	strcpy(temp.album_title, "Witness");
	strcpy(temp.song_title, "Chained to the Rhythm");
	strcpy(temp.genre, "pop");
	temp.song_length.minutes = 4;
	temp.song_length.seconds = 36;
	temp.times_played = 3;
	temp.rating = 5;

	insert_at_front(&pList, temp); //inserting record into list

	FILE* fake = fopen("fake_delete.txt", "w");
	fprintf(fake, "Chained to the Rhythm\n");
	fclose(fake);

	freopen("fake_delete.txt", "r", stdin);

	delete_data(&pList);

	if (pList == NULL)
	{
		printf("Record was deleted, head pointer was updated and memory was released: PASSED!\n");
	}
	else
	{
		printf("Record still exists, head pointer was not updated and memory was not released: FAILED!\n");
	}

	freopen("CON", "r", stdin); //restores stdin so that it reads from the keyboard instead of file
}




void TestShuffleData(void)
{
	Node* pList = NULL;
	
	printf("--------------------------------------------------Testing Shuffling Data--------------------------------------------------------------\n");

	srand(0);
	Playlist s1, s2, s3;

	strcpy(s1. artist, "Artist A");
	strcpy(s1.album_title, "Album A");
	strcpy(s1.song_title, "Song A");
	strcpy(s1.genre, "country");
	s1.song_length.minutes = 4;
	s1.song_length.seconds = 12;
	s1.times_played = 2;
	s1.rating = 1;

	strcpy(s2.artist, "Artist B");
	strcpy(s2.album_title, "Album B");
	strcpy(s2.song_title, "Song B");
	strcpy(s2.genre, "pop");
	s2.song_length.minutes = 5;
	s2.song_length.seconds = 10;
	s2.times_played = 4;
	s2.rating = 3;

	strcpy(s3.artist, "Artist C");
	strcpy(s3.album_title, "Album C");
	strcpy(s3.song_title, "Song C");
	strcpy(s3.genre, "indie");
	s3.song_length.minutes = 6;
	s3.song_length.seconds = 18;
	s3.times_played = 9;
	s3.rating = 5;

	insert_at_front(&pList, s1);
	insert_at_front(&pList, s2);
	insert_at_front(&pList, s3);

	int test_order[3] = {3, 1, 2};

	play_shuffle(pList, test_order, 3);


}