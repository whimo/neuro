#include <stdio.h>

int** matrix_init (int** matrix, size_t x, size_t y); //Provide memory for a matrix

class Neuron
{
    private:
        int** input;  //Stores synaps input
        int** weight; //Stores synaps weights
        int** mul;    //Stores input zoomed by the synaps weights

        size_t x; //Number of columns
        size_t y; //Number of rows

        int limit = 9; //Sum limit (chosen experimentally)
        int sum;       //Sum of the signals

    public:
        Neuron (size_t new_x, size_t new_y, int** in);

        void zoom ();
        void ssum ();
        bool rez  ();

        void w_inc ();
        void w_dec ();
};

int** matrix_init (int** matrix, size_t x, size_t y)
{
    matrix = new int* [x];
    for (size_t i = 0; i < x; i++)
        matrix [i] = new int [y];

    return matrix;
}