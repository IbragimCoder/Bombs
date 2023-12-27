#include <unordered_set>


struct Bomb
{
    int x, y;
    std::unordered_set<int> detonatedBombs;
};