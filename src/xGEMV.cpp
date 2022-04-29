/*******************************************************************

This program is an implementation of a BLAS routine from the second level.
It is the generelized matrix-vector multiplication "xGEMV".
It is of the form  alpha*A*x + beta*y using Halide.


*********************************************************************/

/* Including the Halide header file. */
#include "Halide.h"

/* Including other necessary libraries :) */
/* Hahaha the famous printf is coming */
#include <stdio.h>
/* The turn is for manipulating the files (To not say playing xD) */
#include <iostream>
#include <fstream>

/* BOOOM, avoiding collisions ! */
using namespace std;
using namespace Halide;

/* The piece of cake, are you ready? */
int main(int argc, char **argv)
{
    /* 
    * Initializing the vetors x and y of dimensions (n,1) and (m,1) respectivly
    * Initializing  the matrix A od dimentions (m,n)
    * It's a matrix-vector multiplication
    *  Alpha & beta are scalairs.
    */
    int vectX[6][1] = {
        {2},
        {5},
        {5},
        {0},
        {7},
        {5}};

    int vectY[2][1] = {
        {1},
        {5}};

    int A[2][6] = {
        {0, 1, 2, 3, 1, 1},
        {4, 5, 6, 7, 1, 1}};

    int alpha = 7, beta = 8;

    /* Declaring the Halide function */
    Func multiply;

    /* Declaring two Halide indice's variables */
    Var x, z;

    /* Declaring three buffers to store the two vectors and the matrice */
    Buffer<int> inputX(vectX);
    Buffer<int> inputY(vectY);
    Buffer<int> inputA(A);

    /* STOP, Check point of the dimensions! */
    if (!((inputA.width() == inputX.height()) && (inputA.height() == inputY.height()) && (inputX.width() == inputY.width())))
    {
        printf("Oups, an dimension's error. The inputs must be of the form A(m,n), X(n,1) Y(m,1)\n");
        printf("But happily for you, it will never appear, except if you're reading the code hihihi !!\n");
        exit(1);
    }

    
    /* Declaring  a  reduction domain for the sum reduction. */
    RDom r(0, inputA.width());

    /* Defining the function (the slave, since we're the masters :3) to do the job. */
    multiply(z, x) = alpha * sum(inputA(r, x) * inputX(z, r)) + beta * inputY(z, x);

    /* Doing the multiplication's job */
    Buffer<int> result(inputX.width(), inputA.height());
    multiply.realize(result);
    printf("Youpiiii, multiplication terminado in Halide! \n");

    /* Storing results into a file */
    ofstream results("../results/result_h.txt");
    for (int i = 0; i < result.height(); i++)
    {
        for (int j = 0; j < result.width(); j++)
        {
            results << result(j, i) << "\n";

        }
    }
    results.close();

    return 0;
}
