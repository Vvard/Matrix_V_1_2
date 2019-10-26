#include "./hppFiles/classMatrix.hpp"
#include "./hppFiles/MatrixFileWriter.hpp"
#include "./hppFiles/MatrixFileReader.hpp"
#include "./hppFiles/ReadMatrix.hpp"
#include "./hppFiles/WriteMatrix.hpp"
#include "./hppFiles/ArithmeticFuncs.hpp"
#include "./hppFiles/TransposeMatrix.hpp"

#include<iostream>
int main()
{
	Matrix A, B, C, D, S1, S2, M, MT, rT;    
	
	MatrixFileReader fr_A("A.txt"),
					 fr_B("B.txt"),
					 fr_C("C.txt"),
					 fr_D("D.txt");

	MatrixFileWriter fw("Result.txt"),
		        	 fwT("TransposeResult.txt");

	while (ReadMarix(A, fr_A) && ReadMarix(B, fr_B) &&
	       ReadMarix(C, fr_C) && ReadMarix(D, fr_D)) {
				SumMatrix(A, B, S1);
				SumMatrix(C, D, S2);
				MulMatrix(S1, S2, M);
				WriteMatrix(M, fw);

				TransposeMatrix(S2, MT);
				MulTransposeMatrix(S1, MT, rT);
				WriteMatrix(rT, fwT);
	}

	return 0;
}
