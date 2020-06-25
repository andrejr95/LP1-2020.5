#include "../include/App.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{

    App aplicativo("diary.md");
    return aplicativo.run(argc, argv);
}
