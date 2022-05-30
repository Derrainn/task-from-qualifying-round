#include "fairy_tail.h"

#include <cstdlib>
#include <ctime>

using namespace std;

int walk()
{
    Fairyland world;
    int upIvan=0, upElena=0, rightIvan=0, rightElena=0, leftIvan=0, leftElena=0, downIvan=0, downElena=0;

    for (int i = 0; i < 1000; ++i)
    {
        Direction direction = Direction::Pass;
        
        if ((world.canGo(Character::Elena, Direction::Up)) && (world.canGo(Character::Ivan, Direction::Up)))
        {
            if ((upElena < 6) && (upIvan < 6))
            {
                world.go(Direction::Up, Direction::Up);
                upElena++;
                upIvan++;
                direction=Direction::Up;
            }
            else 
            {
                if (upElena >= 6)
                {
                    world.go(Direction::Down, Direction::Up);
                    downIvan++;
                    direction = Direction::Down;
                    upElena++;
                }
                if (upIvan >= 6)
                {
                    world.go(Direction::Up, Direction::Down);
                    upIvan++;
                    direction = Direction::Up;
                    downElena++;
                }
            }
            i++;
            if (world.canGo(Character::Ivan, direction) && world.go(direction, Direction::Pass))
                return world.getTurnCount();
        }
        
        if ((world.canGo(Character::Elena, Direction::Down)) && (world.canGo(Character::Ivan, Direction::Down)))
        {
            if ((downElena < 6) && (downIvan < 6))
            {
                world.go(Direction::Down, Direction::Down);
                downElena++;
                downIvan++;
                direction = Direction::Down;
            }
            else
            {
                if (downElena >= 6)
                {
                    world.go(Direction::Up, Direction::Down);
                    upIvan++;
                    direction = Direction::Up;
                    downElena++;
                }
                if (downIvan >= 6)
                {
                    world.go(Direction::Down, Direction::Up);
                    downIvan++;
                    direction = Direction::Down;
                    downElena++;
                }
            }
            i++;
            if (world.canGo(Character::Ivan, direction) && world.go(direction, Direction::Pass))
                return world.getTurnCount();
        }

        if ((world.canGo(Character::Elena, Direction::Left)) && (world.canGo(Character::Ivan, Direction::Left)))
        {
            if ((leftElena < 6) && (leftIvan < 6))
            {
                world.go(Direction::Left, Direction::Left);
                leftElena++;
                leftIvan++;
                direction = Direction::Left;
            }
            else
            {
                if (leftElena >= 6)
                {
                    world.go(Direction::Right, Direction::Left);
                    rightIvan++;
                    direction = Direction::Right;
                    leftElena++;
                }
                if (leftIvan >= 6)
                {
                    world.go(Direction::Left, Direction::Right);
                    leftIvan++;
                    direction = Direction::Left;
                    rightElena++;
                }
            }
            i++;
            if (world.canGo(Character::Ivan, direction) && world.go(direction, Direction::Pass))
                return world.getTurnCount();
        }
    }
    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    if (const int turns = walk())
        std::cout << "Found in " << turns << " turns" << std::endl;
    else
        std::cout << "Not found" << std::endl;

    return 0;
}

