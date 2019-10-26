#ifndef CLASSMATRIX_HPP
#define CLASSMATRIX_HPP

typedef int mType;
typedef float eType;

class Matrix
{
	public:
		Matrix() 
		{
			matrix = 0;	
		}

		~Matrix() {
			if (matrix != 0) {
				for (mType i = 0; i < row; ++i) {
					delete[] matrix[i];
				}
			delete[] matrix;
			}
		}

		void init(mType r, mType c) {

			if (matrix != 0) {
				for (mType i = 0; i < row; ++i) {
					delete[] matrix[i];
				}
			delete[] matrix;
			}

			row = r;
			col = c;
			matrix = new eType*[r];
			for (mType i = 0; i < r; ++i) {
				matrix[i] = new eType[c]; 
			}
		}
		
		mType get_row_count() { return row; }
		mType get_col_count() {return col; }
		void set_row_count(mType r) { row = r; };
		void set_col_count(mType c) { col = c; };

		eType& operator() (mType i, mType j) {
			return matrix[i][j];
		}

		const eType& operator() (mType i, mType j) const {
			return matrix[i][j];
		}
				
	private:
			mType row, col;
			eType** matrix;
};


#endif
