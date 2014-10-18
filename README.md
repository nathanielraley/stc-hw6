# README #

Hello!

Quick Readme for HW6 (STC, Fall 2014).

Included in the repository are two source files (inverse.c and linear_equation.c) and a makefile. Typing make will build both programs as executables with the names "linear_inverse" and "linear_equation" respectively. Typing make clean removes the executables and all associated object files. 

The first program solves a system of linear equations using LU factorization and the LAPACK routine dgesv. The second program finds the inverse of a 5x5 matrix of fractions also using dgesv and then confirms that the inverse is correct by conducting two matrix-matrix multiplications (inverse on both RHS and LHS); both result in unity (identity matrix).

Any questions? Contact Nathaniel Raley (nathaniel.raley@utexas.edu)