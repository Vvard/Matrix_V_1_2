#ifndef MATRIXFILEWRITER_HPP
#define MATRIXFILEWRITER_HPP

#include <fstream>
#include <iostream>

typedef int mType;
typedef float eType;

class MatrixFileWriter
{
	public:
		MatrixFileWriter(const char* f_Name) : fName(f_Name) {
			fw.open(fName, std::ios::out);
			if (!fw) {
				std::cerr << "Unable to open the file!";
				exit(1);
			}
		}

		~MatrixFileWriter() {
			if (fw.is_open()) {
				fw.close();
			}
		}

		bool write_char(char smb) {
			if (fw << smb) {
				return true;
			} else {
				return false;
			}
		}

		bool write_count(mType n) {
			if (fw << n) {
				return true;
			} else {
				return false;
			}
		}

		bool write_size(mType s ) {
			if (fw << s) {
				return true;
			} else {
				return false;
			}
		}

		bool write_elm(eType e) {
			if (fw << e) {
				return true;
			} else {
				return false;
			}
		}

	private:
		const char* fName;
		std::ofstream fw;
};

#endif
