#ifndef _CONSTANTS_HPP
#define _CONSTANTS_HPP

/**
 * @brief number of the commands available to the user
 * 
 */
const int COMMANDS = 11;
/// max length for the commands
const char MAX_STRING_LENGTH = 100;
/**
 * @brief array with all the available commands
 * 
 */
const char commandsArray[COMMANDS][MAX_STRING_LENGTH] = { "Add new show:", "Free seats:" , "Reserve a ticket:", "Cancel reservation:", "Buy a ticket: ",
								 "Show list with reservations: ", "Bought ticket refference: ","Show the list with the most watched shows:",
								 "Show list with all the shows that are presented: "
	,"Show list with the shows that have les that 10 percent viership in a certain period: ","END the program: " };
#endif // !_CONSTANTS_HPP
