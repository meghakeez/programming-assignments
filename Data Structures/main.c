/*
	Name: Megha Keezhanjil
	Course: CptS 122, Fall 2026 Lab Section 3
	Lab Assignment: Programming Assignment 1
	Date: 8/30/2026
	Description: Data Structures

*/

#include "header.h"

int main(void)
{
	char targetid[20];
	int count = 0,
		index = 0;
	char minutes_seen[1440][10];

	double total_calories = 0,
		   total_distance = 0;
	int total_floors = 0,
		total_steps = 0,
		max_steps = 0;

	double average_hearate = 0;

	FILE* infile = fopen("FitbitData.csv", "r");
	FILE* outfile = fopen("Results.csv", "w");

	/*if (infile != NULL)
	{
		printf("File read succesfully\n");
	}

	else
	{
		printf("Failure in opening input file\n");
	}*/

	char row[200];

	//reads first row
	fgets(row, 200, infile);

	if (!read_targetid(row, targetid))
	{
		printf("Error in printing target ID\n");
		return 1;
	}
	
	printf("%s\n", targetid); //prints target ID to terminal

	//reads second row
	fgets(row, 200, infile);

	//reads the third row (actual data)
	while (fgets(row, 200, infile) != NULL)
	{
		//If it returns 0 -> skips the row 
		//If it returns 1 -> processes the row 
		if(!read_targetdata(row, targetid))
		continue; //skips the row

		if(remove_duplicates(row, minutes_seen, &count))
		continue; //If it returns 1 -> skips the row

		//Cleans the data (inserting -1 wherever there is an empty field)
		data_cleansing(row);

		//Places records into struct
		place_records_in_struct(row, &record[index]);
		index++;

	}

	total_calories = calculate_total_calories(record, index);
	total_distance = calculate_total_distance(record, index);
	total_floors = calculate_total_floors(record, index);
	total_steps = calculate_total_steps(record, index);
	average_hearate = calculate_average_heartrate(record, index);

	char recent_minute[10];
	max_steps = calculate_max_steps(record, index, recent_minute);

	char start_minute[10],
		 end_minute[10];
	calculate_poorsleep_range(record, index, start_minute, end_minute);

	fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Hearate, Max Steps, Sleep\n");
	fprintf(outfile, "%.2lf, %.2lf, %d, %d, %.2lf, %d, %s - %s\n", total_calories, total_distance, total_floors, total_steps, average_hearate, max_steps, start_minute, end_minute);


	for (int i = 0; i < index; i++)
	{
		fprintf(outfile, "%s, %s, %lf, %lf, %d, %d, %d, %d\n", record[i].patient, record[i].minute, record[i].calories, record[i].distance, record[i].floors, record[i].heartRate, record[i].steps, record[i].sleepLevel);
	}

	fclose(infile);
	fclose(outfile);

	return 0;

}

