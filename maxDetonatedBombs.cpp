#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "bomb.cpp"

int maxDetonatedBombs(std::vector<std::vector<int>>& bombs)
{
    int maxDetonated = 0;
    std::unordered_map<int, Bomb> bombMap;

    for (int i = 0; i < bombs.size(); ++i)
    {
        int xi = bombs[i][0];
        int yi = bombs[i][1];
        int ri = bombs[i][2];

        std::unordered_set<int> visited;

        visited.insert(i);

        std::queue<int> q;

        q.push(i);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            int current_x = bombs[current][0];
            int current_y = bombs[current][1];

            for (int j = 0; j < bombs.size(); ++j)
            {
                if (visited.count(j))
                {
                    continue;
                }

                int temp_x = bombs[j][0];
                int temp_y = bombs[j][1];

                if ((temp_x - current_x) * (temp_x - current_x) + (temp_y - current_y) * (temp_y - current_y) <= ri * ri)
                {
                    q.push(j);
                    visited.insert(j);

                    bombMap[i].detonatedBombs.insert(j);
                }

            }
        }

        bombMap[i].x = xi;
        bombMap[i].y = yi;

        if (visited.size() > maxDetonated)
        {
            maxDetonated = visited.size();
        }

    }

    for (const auto& bomb : bombMap)
    {
        std::cout << "Bomba (" << bomb.second.x << ", " << bomb.second.y << ") bum: ";

        for (int detonated : bomb.second.detonatedBombs)
        {
            std::cout << "(" << bombs[detonated][0] << ", " << bombs[detonated][1] << ") ";
        }

        std::cout << "\n";
    }

    return maxDetonated;
}