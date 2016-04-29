#include "Neuro.h"

Neuron::Neuron (size_t sx, size_t sy, int** in): x (sx), y (sy)
{
    matrix_init (weight, x, y);
    matrix_init (mul   , x, y);
    matrix_init (input , x, y);

    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            input [i][j] = in [i][j]; //Copy the input
}

void Neuron::zoom ()
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            mul [i][j] = input [i][j] * weight [i][j];
}

void Neuron::ssum()
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            sum += mul [i][j];
}

bool Neuron::rez() {return sum >= limit;}

void Neuron::w_inc()
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            weight [i][j] += input [i][j];
}

void Neuron::w_dec()
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            weight [i][j] -= input [i][j];
}

int main ()
{
    return 0;
}
