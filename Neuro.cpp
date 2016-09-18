/***********************************************************
 * Neuro.cpp                                               *
 * A simple neuron web for character recognition           *
 * IMPLEMENTATION                                          *
 *                                                         *
 * Author: Artemy Belousov (aka whitemoustache, WM, whimo) *
 ***********************************************************/

#include "Neuro.h"

Neuron::Neuron (char new_ch, size_t new_x, size_t new_y): x (new_x), y (new_y), ch (new_ch) //The constructor
{
    weights.resize (x);
    for (size_t i = 0; i < x; i++)
        weights [i].resize (y, 0); //Initialize the weights vector
}


bool Neuron::process (char real /*='\0'*/ )
{
    zoom   (); //Zoom input by synaptic weights...
    sum_up (); //...and sum them up

    bool result = rez ();

    if (real != '\0')
    {
        //{===================== Learning =====================
        //If the answer is right, do nothing
        //If the wrong answer is "true":
        if (ch != real && result == true)
        {
            w_dec (); //Substract input values from weights
            return process (real); //Learn recursively
        }

        //If the wrong answer is "false":
        if (ch == real && result == false)
        {
            w_inc (); //Add input values to weights
            return process (real); //Learn recursively
        }
        //}====================================================
    }

    return result;
}


//{================== "Set"-methods ===================

void Neuron::set_input (std::vector < std::vector <bool> > in) //Set input values
{
    input = in; //Copy input
}

void Neuron::set_weights (std::vector < std::vector <int> > in) //Set saved weights
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            weights [i][j] = in [i][j];
}

//}====================================================

void Neuron::get_weights (std::vector < std::vector <int> >* out) //Get synaptic weights
{
    (*out).clear ();

    for (size_t i = 0; i < y; i++)
    {
        std::vector <int> temp;
        for (size_t j = 0; j < x; j++)
            temp.push_back (weights [i][j]);

        (*out).push_back (temp);
    }
}

//{================ Processing methods ================

void Neuron::zoom () //Zoom input values by weights
{
    mul.resize (x);
    for (size_t i = 0; i < x; i++)
    {
        mul [i].resize (y);
        for (size_t j = 0; j < y; j++)
            mul [i][j] = (bool) input [i][j] * weights [i][j];

    }
}

void Neuron::sum_up () //Sum up zoomed values
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
            weights [i][j] += input [i][j];
}

void Neuron::w_dec () //Reduce weights
{
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            weights [i][j] -= input [i][j];
}

//}====================================================
