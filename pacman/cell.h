#ifndef CELL_H
#define CELL_H


class Cell
{
    public:
        Cell(int x, int y);
        enum CellState{Pacman, Ghost, Wall, Empty, Ball};
        void make_empty();
        void put_pacman();
        void put_ghost();
        void put_wall();
        void put_ball();

        Cell* left;
        Cell* right;
        Cell* up;
        Cell* down;

        int x, y;

    private:
        CellState state;
};

#endif // CELL_H
