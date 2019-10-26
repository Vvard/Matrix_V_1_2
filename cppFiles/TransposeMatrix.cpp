void TransposeMatrix(Matrix& M, Matrix& MT)
{
	mType r1, r2, c1, c2;
	r1 = M.get_row_count();
	c1 = M.get_col_count();
	r2 = c1; 
	c2 = r1;

	MT.init(r2, c2);
	
	for (mType i = 0; i < r1; ++i) {
		for (mType j = 0; j < c1; ++j) {
			MT(j, i) = M(i, j); 
		}
	}
};
