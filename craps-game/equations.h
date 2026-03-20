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
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function prints the game rules
*Input parameters : No parameters
*Returns : Does not return anything (void)
*Preconditions : None
*Postconditions : Game rules are printed
*************************************************************/
void print_game_rules(void);


/*************************************************************
*Function: get_bank_balance()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function stores the bank balance inputted by user
*Input parameters : No parameters
*Returns : Returns double value 
*Preconditions : Standard input must contain valid double value
*Postconditions : Returns the bank balance
*************************************************************/
double get_bank_balance (void); 


/*************************************************************
*Function: get_wager_amount()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function stores the wager amount inputted by user
*Input parameters : No parameters
*Returns : Returns double value
*Preconditions : Standard input must contain valid double value
*Postconditions : Returns the wager amount
*************************************************************/
double get_wager_amount(void); 


/*************************************************************
*Function: check_wager_amount()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function checks whether the wager amount is a valid number
*Input parameters : wager (double), balance (double)
*Returns : Returns integer value
*Preconditions : Wager must be less than bank balance and not equal to 0 or negative number
*Postconditions : Returns the valid wager amount
*************************************************************/
int check_wager_amount(double wager, double balance);

/*************************************************************
*Function: roll_die()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function returns random number between 1-6
*Input parameters : No parameters 
*Returns : Returns integer value
*Preconditions : rand() and srand((unsigned int)time(NULL)) must be properly integrated into program 
*Postconditions : Returns the die number
*************************************************************/
int roll_die(void);

/*************************************************************
*Function: calculate_sum_dice()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function returns the sum of both die values
*Input parameters : die1_value (int), die2_value (int)
*Returns : Returns integer value
*Preconditions : die1 and die2 must be valid values
*Postconditions : Returns the sum of dice
*************************************************************/
int calculate_sum_dice(int die1_value, int die2_value);

/*************************************************************
*Function: is_win_loss_or_point()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function determines the result of first dice roll and sets different cases
*Input parameters : sum_dice (int)
*Returns : Returns integer value
*Preconditions : sum_dice must be valid value
*Postconditions : Returns the integer value (1, 0, -1) based on case
*************************************************************/
int is_win_loss_or_point(int sum_dice); 

/*************************************************************
*Function: is_point_loss_or_neither()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This determines the result of successive dice rolls based on sum of dice and point value
*Input parameters : sum_dice (int), point_value (int)
*Returns : Returns integer value
*Preconditions : sum_dice and point_value must be valid values
*Postconditions : Returns the integer value (1, 0, -1) 
*************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value);

/*************************************************************
*Function: adjust_bank_balance()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function adjusts the bank balance based on whether user wins or loses
*Input parameters : bank_balance (double), wager_amount (double), add_or_subtract(int)
*Returns : Returns double value
*Preconditions : bank_balance, wager_amount and add_or_subtract must be valid values
*Postconditions : Returns the adjusted bank balance
*************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

/*************************************************************
*Function: chatter_messages()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function prints chatter messages based on number of rolls, amount of bank balance and whether user wins or loses
*Input parameters : number_rolls (int), win_loss_neither(int), initial_bank_balance(double), current_bank_balance(double)
*Returns : Does not return anything (void)
*Preconditions : number_rolls, win_loss_neither, initial_banl_balance, and current_bank_balance must be valid values
*Postconditions : chatter messages are printed
*************************************************************/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

/*************************************************************
*Function: update_streak()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function updates the streak count based on the outcome of game
*Input parameters : streak (int), outcome (int)
*Returns : Returns integer value
*Preconditions : outcome must be valid value
*Postconditions : Updates the streak count
*************************************************************/
int update_streak(int streak,int outcome);

/*************************************************************
*Function: print_streak_messages()
*Date Created : 2/25/2026
*Date Last Modified : 3/4/2026
*Description : This function prints messages based on streak count
*Input parameters : streak(int)
*Returns : Does not return anything (void)
*Preconditions : streak must be valid value
*Postconditions : Prints the streak message
*************************************************************/
void print_streak_messages (int streak);













