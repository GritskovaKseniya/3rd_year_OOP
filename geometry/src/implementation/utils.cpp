#include <string>
#include <ctime>

#include "../header/utils.h"

void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr) {
	// Get the first occurrence
	size_t pos = data.find(toSearch);
 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + replaceStr.size());
	}
}

std::string getCurrentDateAndTime() {
	time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y_%H:%M:%S", timeinfo);
    std::string str(buffer);

    return str;
}
