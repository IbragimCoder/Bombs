#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "maxDetonatedBombs.cpp"
#include <gtest/gtest.h>


TEST(bombs, bombTest1)
{
    std::vector<std::vector<int>> bombs = { {2,1,3},{6,1,4} };
    int res = maxDetonatedBombs(bombs);
    ASSERT_EQ(2, res);
}

TEST(bombs, bombTest2)
{
    std::vector<std::vector<int>> bombs = { {1,1,5},{10,10,5} };
    int res = maxDetonatedBombs(bombs);
    ASSERT_EQ(1, res);
}

TEST(bombs, bombTest3)
{
    std::vector<std::vector<int>> bombs = { {1,2,3},{2,3,1}, {3,4,2},{4,5,3},{5,6,4} };
    int res = maxDetonatedBombs(bombs);
    ASSERT_EQ(5, res);
}

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

    return RUN_ALL_TESTS();
}