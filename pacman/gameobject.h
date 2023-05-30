#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class GameObject
{
    public:
        GameObject();
        enum ObjectType {Ball, Wall, Gate, Pacman, Ghost, Blank, PowerBall};
        enum Direction {Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4};

    protected:
        int x, y;
        Direction direction, next_dir;
        ObjectType type;
        int score;
};

#endif // GAMEOBJECT_H
