bool ReadMarix(Matrix& M, MatrixFileReader& fr)
{
	mType r, c, n;
	eType e;

		if(fr.read_char('#') && fr.read_num(n) &&
		   fr.read_size(r) && fr.read_char('x') &&
		   fr.read_size(c)) {

				M.init(r, c);
				for (mType i = 0; i < r; ++i) {
					for (mType j = 0; j < c; ++j) {
						fr.read_elm(e);
						M(i, j) = e;
					}
			}
		 	return true;
		} else {
			std::cerr << "Unable to read a element!";
			return false;
		}
};
