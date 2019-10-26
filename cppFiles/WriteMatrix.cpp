bool WriteMatrix(Matrix& M, MatrixFileWriter& fw)
{
	bool res;
	mType r, c, n;
	r = M.get_row_count();
	c = M.get_col_count();

	if (fw.write_char('#') && fw.write_size(r) &&
		fw.write_char('x') && fw.write_size(c) && fw.write_char('\n')) {
			for(mType i = 0; i < r; ++i) {
				for (mType j = 0; j < c; ++j) {
					if (fw.write_elm(M(i,j)) && fw.write_char(' ')) {
						res = true;
					} else {
						std::cerr << "Unable to write element!";
						res = false;
					}
				}
				fw.write_char('\n');
			}
	} else {
		std::cerr << "Unable to write in file!";
		res = false;
	}
	return res;
};
