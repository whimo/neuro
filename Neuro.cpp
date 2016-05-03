/**********************************************************
 * Neuro.cpp                                              *
 * A simple neuron web for character recognition          *
 * IMPLEMENTATION                                         *
 *                                                        *
 * Author: Artemy Belousov (aka whitemoustache, WM, whimo)*
 **********************************************************/

#include "Neuro.h"

int**  matrix_init (int**  matrix, size_t x, size_t y); // |Provide memory|
bool** matrix_init (bool** matrix, size_t x, size_t y); // | for a matrix |

Neuron::Neuron (size_t sx, size_t sy, bool** in): x (sx), y (sy) //The constructor
{
    matrix_init (weight, x, y);
    matrix_init (mul   , x, y);
    matrix_init (input , x, y);

    set_input (in);
}

void Neuron::set_input (bool **in) //Set the input values
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            input [i][j] = in [i][j]; //Copy the input
}

//{================ Processing methods ================

void Neuron::zoom () //Zoom input values by weights
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            mul [i][j] = input [i][j] * weight [i][j];
}

void Neuron::sum_up () //Sum up the zoomed values
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            sum += mul [i][j];
}

bool Neuron::rez () {return sum >= limit;} //Compare sum and limit

//}====================================================


//{================= Learning methods =================

void Neuron::w_inc () //Increase weights
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            weight [i][j] += input [i][j];
}

void Neuron::w_dec () //Reduce weights
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            weight [i][j] -= input [i][j];
}

//}====================================================


//{================ Auxiliary methods =================

int** matrix_init (int** matrix, size_t x, size_t y)
{
    matrix = new int* [x];
    for (size_t i = 0; i < x; i++)
        matrix [i] = new int [y];

    return matrix;
}

bool** matrix_init (bool** matrix, size_t x, size_t y)
{
    matrix = new bool* [x];
    for (size_t i = 0; i < x; i++)
        matrix [i] = new bool [y];

    return matrix;
}

//}====================================================
