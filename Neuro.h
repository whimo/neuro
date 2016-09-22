/***********************************************************
 * Neuro.h                                                 *
 * A simple neural network for character recognition       *
 *                                                         *
 * Author: Artemy Belousov (aka whitemoustache, WM, whimo) *
 ***********************************************************/

#ifndef NEURO_H
#define NEURO_H

#include <stdio.h>
#include <vector>

class Neuron
{
    private:
        std::vector < std::vector <bool> > input;   //Store input
        std::vector < std::vector <int> >  weights; //Store synaptic weights
        std::vector < std::vector <int> >  mul;     //Store input zoomed by weights

        size_t x; //Number of columns
        size_t y; //Number of rows

        int limit = 9; //Sum limit (chosen experimentally for 3x5 bitmap)
        int sum   = 0; //Sum of signals


        //{================ Processing methods ================
        void zoom   (); //Zoom input values by weights
        void sum_up (); //Sum up zoomed values
        bool rez    (); //Compare sum and limit
        //}====================================================

        //{================= Learning methods =================
        void w_inc (); //Increase weights
        void w_dec (); //Reduce weights
        //}====================================================

    public:
        char ch; //Character the neuron is responsible for

        Neuron (char new_ch, size_t new_x, size_t new_y); //The constructor

        void set_input (std::vector < std::vector <bool> > in); //Set input values

        //The main processing method. Returns the neuron output.
        //Teaches the neuron: the argument ("char real") is the real character on the image.
        //If you want to teach the network, you should pass this character to the process() method.
        bool process (char real = '\0');


        void set_weights (std::vector < std::vector <int> >   in); //Set saved weights
        void get_weights (std::vector < std::vector <int> >* out); //Get synaptic weights
};

#endif //NEURO_H
