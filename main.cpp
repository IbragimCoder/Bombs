#include <iostream>
#include <fstream>
#include <vector>


int main()
{
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> bombs;
    int x, y, r;

    while (inputFile >> x >> y >> r)
    {
        bombs.push_back({ x, y, r });
    }

    inputFile.close();

    std::ofstream out("output.txt");

    int result = maxDetonatedBombs(bombs);

    if (out.is_open())
    {
        out << "Max count of explotion bombs : " << result << "\n";
    }

    out.close();

    return 0;
}