#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error : ./sed <filename> <string1> <string2>" << std::endl;
        return (0);
    }

    std::ifstream infile(av[1]);
    std::string string1 = av[2];
    std::string string2 = av[3];
    int i = 0;
    char c;

    if (!infile.is_open() || !string1.size() || !string2.size())
    {
        std::cerr << "failed parameter" << std::endl;
        return (0);
    }
    if (string1.compare(string2) == 0)
    {
        std::cerr << "Nothing to replace : string1 = string2";
        return (0);
    }
    std::string fileContent;
    std::ofstream outfile;
    std::string namefile = av[1];
    namefile += ".replace";
    outfile.open(namefile.c_str());
    while (infile.get(c))
        fileContent.push_back(c);
    i = fileContent.find(string1);
    while (i != -1)
    {
        fileContent.erase(i, string1.length());
        fileContent.insert(i, string2);
        i = fileContent.find(string1);
    }
    outfile << fileContent;    
    outfile.close();
    infile.close();
    return(0);
}