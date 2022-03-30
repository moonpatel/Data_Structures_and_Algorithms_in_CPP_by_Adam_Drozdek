#ifndef _AUTHOR_H_
#define _AUTHOR_H_

#include <string>
#include <vector>

class author {
private:
    std::string name;               // name of the author
    std::vector<std::string> books; // books written by author

public:
    author();       // default constructor
};

#endif