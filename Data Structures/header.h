/*
	Header file
	Contains preprocessors like #include, #define and function declarations/prototypes

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;

}FitbitData;

FitbitData record[1440]; //change it to local

int read_targetid(char *row, char* targetid);
int read_targetdata(char* row, char* targetid);
int remove_duplicates(char *row, char minutes_seen[][10], int* count);
int data_cleansing(char *row);
int place_records_in_struct(char *row, FitbitData *record);

double calculate_total_calories(FitbitData *record, int index);
double calculate_total_distance(FitbitData *record, int index);
int calculate_total_floors(FitbitData* record, int index);
int calculate_total_steps(FitbitData* record, int index);

double calculate_average_heartrate(FitbitData *record, int index);
int calculate_max_steps(FitbitData* record, int index, char* recent_minute);
void calculate_poorsleep_range(FitbitData* record, int index, char* start_minute, char* end_minute);


