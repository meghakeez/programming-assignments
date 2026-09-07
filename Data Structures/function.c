/*

	Contains function headers

*/

#include "header.h"


/*************************************************************
*Function: read_targetid()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function reads the targetid from the data
*Input parameters : *row(string), *targetid(string)
*Returns : Returns an integer
*Preconditions : valid variables declared for *targetid, and row needs to store valid data from the dataset
*Postconditions : Returns an integer based on whether targetid has been stored properly
*************************************************************/
int read_targetid(char* row, char* targetid)
{

	char temp[200];

	//stores data from row in temp
	strcpy(temp, row);

	char* token = strtok(temp, ","); //reads first token which is "Target"
	token = strtok(NULL,","); //reads second token which contains target patient ID

	//error in reading patient id
	if (token == NULL)
	{
		return 0; 
	}

	//stores target patient id
	strcpy(targetid, token);
	return 1;

}

/*************************************************************
*Function: read_targetdata()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function reads in the data if the patient id matches the target patient id
*Input parameters : *row(string), *targetid(string)
*Returns : Returns an integer
*Preconditions : valid variables declared for *targetid, and row needs to store valid data from the dataset
*Postconditions : Returns an integer based on whether the patient ID was a match or not
*************************************************************/
int read_targetdata(char* row, char* targetid)
{

	char temp[200];

	//stores data from row in temp
	strcpy(temp, row);

	//get the first token which is patient ID
	char* token = strtok(temp, ",");

	if (token == NULL)
	{
		return 0;
	}

	//Compares the ID to the target patient ID
	if (strcmp(token, targetid) == 0)
	{
		return 1; //It is a match
	}

	return 0; //It is not a match


}


/*************************************************************
*Function: remove_duplicates()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function removes duplicates based on whether the minute data is the same
*Input parameters : *row(string), minutes_seen(2 dimensional array), *count(pointer)
*Returns : Returns an integer 
*Preconditions : row needs to store valid data from the dataset, valid variables declared for minutes_seen and count
*Postconditions : Returns an integer based on whether the row was a duplicate or not
*************************************************************/
int remove_duplicates(char* row, char minutes_seen[][10], int* count)
{

	char temp[200];
	strcpy(temp, row);

	strtok(temp, ","); //skips patient ID
	char* minute = strtok(NULL, ","); //gets the minute from record

	for (int index = 0; index < *count; index++)
	{
		if (strcmp(minutes_seen[index], minute) == 0)
		{
			return 1; //it is a duplicate
		}

	}

	strcpy(minutes_seen[*count], minute);
	(*count)++; //increments how many minutes have been seen

	return 0;

}


/*************************************************************
*Function: data_cleansing()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function cleanses the data and adds '-1' wherever there is an empty field
*Input parameters : *row(string)
*Returns : Returns an integer
*Preconditions : row needs to store valid data from the dataset
*Postconditions : Returns 1 after the data has been cleansed and invalid data has been entered into empty fields
*************************************************************/
int data_cleansing(char* row)
{
	char temp[400];
	int j = 0;

	//Controls the loop for the whole string until we hit the null terminator
	for (int index = 0; row[index] != '\0'; index++)
	{
	
		if (row[index] == ',')
		{
			temp[j] = ','; //copies the comma 
			j += 1; //increments the position

			int c = index + 1; //gets the next character

			//If next character is a comma
			if (row[c] == ',')
			{
				temp[j++] = '-';
				temp[j++] = '1';

				//copies the original comma which is now shifted
				temp[j++] = ',';

				index = c;//moves index forward to c

			}

		}

		//If character is not a comma
		else
		{
			temp[j++] = row[index];//copies current character into temp
		}

	}

	temp[j] = '\0';
	strcpy(row, temp);
	return 1;

}


/*************************************************************
*Function: place_records_in_struct()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function places the records into the struct
*Input parameters : *row(string), *record(struct)
*Returns : Returns an integer
*Preconditions : row needs to store valid data from the dataset, record has to point towards a valid struct
*Postconditions : Returns 1 after the row has been properly placed into the struct
*************************************************************/
int place_records_in_struct(char* row, FitbitData* record)
{
	
	char temp[400];
	strcpy(temp, row);

	char* token = strtok(temp, ",");
	strcpy(record->patient, token); //patient ID

	token = strtok(NULL, ",");
	strcpy(record->minute, token); //minutes

	token = strtok(NULL, ","); //calories
	record->calories = atof(token);

	token = strtok(NULL, ","); //distance
	record->distance = atof(token);

	token = strtok(NULL, ","); //floors
	record->floors = atoi(token);

	token = strtok(NULL, ","); //heartrate
	record->heartRate = atoi(token);

	token = strtok(NULL, ","); //steps
	record->steps = atoi(token);

	token = strtok(NULL, ","); //sleep level
	record->sleepLevel = atoi(token);

	return 1;

}

/*************************************************************
*Function: calculate_total_calories()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function calculates total calories
*Input parameters : *record(struct), index(int)
*Returns : Returns total_calories(double)
*Preconditions : record has to point towards a valid struct, valid variable for index
*Postconditions : Returns the total_calories computed
*************************************************************/
double calculate_total_calories(FitbitData* record, int index)
{

	double total_calories = 0;

	for (int i = 0; i < index; i++)
	{
		total_calories += record[i].calories;
	}

	return total_calories;

}


/*************************************************************
*Function: calculate_total_distance()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function calculates the total distance
*Input parameters : *record(struct), index(int)
*Returns : Returns total_distance(double)
*Preconditions : record has to point towards a valid struct, valid variable for index
*Postconditions : Returns the total_distance computed
*************************************************************/
double calculate_total_distance(FitbitData* record, int index)
{
	double total_distance = 0;

	for (int i = 0; i < index; i++)
	{
		total_distance += record[i].distance;
	}

	return total_distance;
}


/*************************************************************
*Function: calculate_total_floors)
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function calculates the total floors
*Input parameters : *record(struct), index(int)
*Returns : Returns total_floors(int)
*Preconditions : record has to point towards a valid struct, valid variable for index
*Postconditions : Returns the total_floors computed
*************************************************************/
int calculate_total_floors(FitbitData* record, int index)
{
	int total_floors = 0;

	for (int i = 0; i < index; i++)
	{
		total_floors += record[i].floors;
	}

	return total_floors;


}


/*************************************************************
*Function: calculate_fuel_steps()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function calculates the total steps
*Input parameters : *record(struct), index(int)
*Returns : Returns total_steps(int)
*Preconditions : record has to point towards a valid struct, valid variable for index
*Postconditions : Returns the total_steps computed
*************************************************************/
int calculate_total_steps(FitbitData* record, int index)
{
	int total_steps = 0;

	for (int i = 0; i < index; i++)
	{
		total_steps += record[i].steps;
	}

	return total_steps;
	

}


/*************************************************************
*Function: calculate_average_heartrate()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function calculates the average heartrate
*Input parameters : *record(struct), index(int)
*Returns : Returns average_heartrate(double)
*Preconditions : record has to point towards a valid struct, valid variable for index
*Postconditions : Returns the average_heartrate computed
*************************************************************/
double calculate_average_heartrate(FitbitData* record, int index)
{
	
	int total_heartrate = 0;
	double average_heartrate = 0;

	for (int i = 0; i < index; i++)
	{
		total_heartrate += record[i].heartRate;
	}

	average_heartrate = (double)total_heartrate/index;

	return average_heartrate;


}


/*************************************************************
*Function: calculate_max_steps()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function calculates max steps and also records the minute at which the steps are at the highest
*Input parameters : *record(struct), index(int), recent_minute(array)
*Returns : Returns max_steps(int)
*Preconditions :  record has to point towards a valid struct, valid variable for index and recent_minute
*Postconditions : Returns the max_steps computed
*************************************************************/
int calculate_max_steps(FitbitData* record, int index, char* recent_minute)
{
	int max_steps = 0;

	for (int i = 0; i < index; i++)
	{
		if (record[i].steps > max_steps)
		{
			max_steps = record[i].steps;
			strcpy(recent_minute, record[i].minute); //records the minute at which steps are at the max
		}

		//If steps are the same
		else if (record[i].steps == max_steps) 
		{
			if (strcmp(record[i].minute, recent_minute) > 0) //if the current minute is more recent
			{
				strcpy(recent_minute, record[i].minute); //copies the most recent minute
			}
		}

	}
	
	return max_steps;

}


/*************************************************************
*Function: calculate_poorsleep_range()
*Date Created : 8/30/2026
*Date Last Modified : 9/6/2026
*Description : This function calculates the range of poorsleep based on the sum of sleepLevel
*Input parameters : *record(struct), index(int), start_minute(array), end_minute(array)
*Returns : Does not return anything (void)
*Preconditions : record has to point towards a valid struct, valid variable for index, start_minute, and end_minute
*Postconditions : Does not return anything
*************************************************************/
void calculate_poorsleep_range(FitbitData* record, int index, char* start_minute, char* end_minute)
{
	
	int current_sum = 0,
		highest_sum = 0;

	char current_start[10],
		 current_end[10];

	int in_range = 0; //tracks whether we are inside a poor-sleep segment

	for (int i = 0; i < index; i++)
	{
		if (record[i].sleepLevel > 1) //poor-sleep
		{
			if (!in_range)
			{
				//start of a poor-sleep segment
				in_range = 1;
				strcpy(current_start, record[i].minute);
			}

			current_sum += record[i].sleepLevel;
			strcpy(current_end, record[i].minute);
		}
		else
		{	
			//poor-sleep segment has ended
			if (in_range)
			{
				if (current_sum > highest_sum)
				{
					highest_sum = current_sum;
					strcpy(start_minute, current_start);
					strcpy(end_minute, current_end);
				}
				
				//resetting for next segment
				in_range = 0;
				current_sum = 0;

			}

		}

	}

	//Edge Case: the loop ends while we are still inside a poor-sleep segment
	if (in_range && current_sum > highest_sum)
	{
		highest_sum = current_sum;
		strcpy(start_minute, current_start);
		strcpy(end_minute, current_end);
	}

}



