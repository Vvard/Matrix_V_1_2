void SumMatrix(Matrix& M1, Matrix& M2, Matrix& S)
{
	mType r1, r2, c1, c2;
	r1 = M1.get_row_count();
	r2 = M2.get_row_count();
	c1 = M1.get_col_count();
	c2 = M2.get_col_count();

	if ((r1 == r2) && (c1 == c2)) {
	S.init(r1, c1);
		for (mType i = 0; i < r1; ++i) {
			for (mType j = 0; j < c1 ;  ++j) {
				S(i, j) = M1(i, j) + M2(i, j);
			}
		}
	} else {
		std::cerr << "The Matrices sizes mismatch!";
	}
};

void MulMatrix(Matrix& M1, Matrix& M2, Matrix& R)
{
	mType r1, r2, c1, c2;
	eType Sum;
	r1 = M1.get_row_count();
	r2 = M2.get_row_count();
	c1 = M1.get_col_count();
	c2 = M2.get_col_count();
	
	if (c1 == r2) {
	R.init(r1, c2);
		for (mType i = 0; i < r1; ++i) {
			for (mType j = 0; j < c2; ++j) {
			Sum = 0;
				for(mType k = 0; k < c1; ++k) {
				Sum += M1(i, k) * M2(k, j);
				}
			R(i, j) = Sum;
			}
		}
	}
};

void MulTransposeMatrix(Matrix& M1, Matrix& M2, Matrix& R)
{
	mType r1, r2, c1, c2;
	eType Sum;
	r1 = M1.get_row_count();
	r2 = M2.get_row_count();
	c1 = M1.get_col_count();
	c2 = M2.get_col_count();

	if ( c1 == c2) {
	R.init(r1, r2);
		for (mType i = 0; i < r1; ++i) {
			for (mType j = 0; j < r2; ++j) {
				Sum = 0;
				for (mType k = 0; k < c2; ++k) {
				Sum += M1(i, k) * M2(j, k);
				}
			R(i, j) = Sum;
			}
		}
	}
};
