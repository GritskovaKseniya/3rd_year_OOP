#pragma once

#include <string>

/**
 * Finds all occurencies of toString in data and replaces them with replaceStr
 * 
 * @param data String with data
 * @param toSeatch String that needs to be replaced
 * @param replaceStr String that replaces
*/
void findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr);


/**
 * Returns current date and time
 * 
 * @return Date and time in format %d-%m-%Y_%H:%M:%S
*/
std::string getCurrentDateAndTime();
