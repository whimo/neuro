/**********************************************************
 * Neuro.h                                                *
 * A simple neuron web for character recognition          *
 *                                                        *
 * Author: Artemy Belousov (aka whitemoustache, WM, whimo)*
 **********************************************************/

#ifndef NEURO_H
#define NEURO_H

#include <iostream>

class Neuron
{
    private:
        bool** input;  //Store synaps input
        int**  weight; //Store synaptic weights
        int**  mul;    //Store input zoomed by weights

        size_t x; //Number of columns
        size_t y; //Number of rows

        int limit = 9; //Sum limit (chosen experimentally for 3x5 bitmap)
        int sum   = 0; //Sum of the signals

    public:
        Neuron (size_t new_x, size_t new_y, bool** in); //The constructor

        void set_input (bool** in); //Set the input values

        //{================ Processing methods ================
        void zoom   (); //Zoom input values by weights
        void sum_up (); //Sum up the zoomed values
        bool rez    (); //Compare sum and limit
        //}====================================================

        //{================= Learning methods =================
        void w_inc (); //Increase weights
        void w_dec (); //Reduce weights
        //}====================================================

        //TODO: add memory file
};

#endif //NEURO_H
