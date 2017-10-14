#include <iostream>
#include <string>
#include <algorithm>


int main() {
    std::string essay;
    std::getline(std::cin, essay);
    std::string upper = essay, lower = essay;
    int cntU = 0, cntL=0;
    std::transform(upper.begin(), upper.end(), upper.begin(), toupper);
    transform(lower.begin(), lower.end(), lower.begin(), tolower);
    for(int i = 0; i < essay.length(); i++)
    {
        if(essay[i]==' ')
            continue;
        if(isupper(essay[i]))
            cntU++;
        else
            cntL++;
    }
    if(cntL == cntU)
        printf("%s\n", essay.c_str());
    else if(cntL>cntU)
        printf("%s\n", lower.c_str());
    else
        printf("%s\n", upper.c_str());
    return 0;
}