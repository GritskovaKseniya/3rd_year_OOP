#include "../header/utils.h"

#include <string>

bool startsWith(std::string predicate, std::string string) {
    return string.rfind(predicate, 0) == 0;
}
