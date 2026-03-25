/*
	Header file
	Contains preprocessors like #include, #define and function declarations/prototypes

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*************************************************************
*Function: print_game_rules()
*Date Created : 3/11/2026
*Date Last Modified : 3/23/2026
*Description : This function prints the game rules
*Input parameters : No parameters
*Returns : Does not return anything (void)
*Preconditions : None
*Postconditions : Game rules are printed
*************************************************************/
void print_game_rules(void); 

/*************************************************************
*Function: roll_die()
*Date Created : 3/11/2026
*Date Last Modified : 3/23/2026
*Description : This function returns random number between 1-6
*Input parameters : No parameters
*Returns : Returns integer value
*Preconditions : rand() and srand((unsigned int)time(NULL)) must be properly integrated into program 
*Postconditions : Returns the die number
*************************************************************/
int roll_die(void);

/*************************************************************
*Function: handling_of_rolls()
*Date Created : 3/11/2026
*Date Last Modified : 3/25/2026
*Description : This function determines whether players can and want to roll dice again and rolls dice based on the choice
*Input parameters : die_arr[] - array
                    *roll     - pointer
*Returns : Returns 0
*Preconditions : die_arr must reference a valid array
				 roll must reference a valid integer

*Postconditions : die_arr[] is updated with new dice values
*                 *roll is incremented to reflect the roll

*************************************************************/
int handling_of_rolls(int die_arr[], int *roll); 

/*************************************************************
*Function: print_scoring_combinations()
*Date Created : 3/11/2026
*Date Last Modified : 3/25/2026
*Description : This prints the scoring combination
*Input parameters : No parameters
*Returns : Does not return anything (void)
*Preconditions : None
*Postconditions : Scoring combinations are printed
*************************************************************/
void print_scoring_combinations(void);

/*************************************************************
*Function: choosen_scoring_combination()
*Date Created : 3/11//2026
*Date Last Modified : 3/25/2026
*Description : This function prompts players to pick scoring combination and ensures combination is not choosen again (unless Yahtzee)
*Input parameters : used[] - array
*Returns : Returns the combination
*Preconditions : used[] must reference a valid array,
*Postconditions : If the combination is not 12, the
                  index in used[] is set to 1

*************************************************************/
int choosen_scoring_combination(int used[]); 

/*************************************************************
*Function: scoring_category()
*Date Created : 3/11/2026
*Date Last Modified : 3/25/2026
*Description : This calculates score based on dice and combination choosen and stores the score for that round  
*Input parameters : dice[] - array, combination (int)
*Returns : Returns points
*Preconditions : dice[] must reference a valid array
                 combination must be between 1-13
*Postconditions: returns computed score
*************************************************************/
int scoring_category(int dice[], int combination); 

/*************************************************************
*Function: totalscore_uppersection()
*Date Created : 3/11/2026
*Date Last Modified : 3/25/2026
*Description : This function computes total score for uppersection and adds 35 if greater than 63
*Input parameters : score[] - array
*Returns : Returns total
*Preconditions : score[] must reference a valid array
*Postconditions : Returns total updated score for uppersection
*************************************************************/
int totalscore_uppersection(int score[]); 

/*************************************************************
*Function: total_score()
*Date Created : 3/11/2026
*Date Last Modified : 3/25/2026
*Description : This function computes total score for each player
*Input parameters : score[] - array
*Returns : Returns total
*Preconditions : score[] must reference a valid array
*Postconditions : Rerurns total score for game
*************************************************************/
int total_score(int score[]); 

