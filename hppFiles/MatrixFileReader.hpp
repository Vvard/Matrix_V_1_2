#ifndef MATRIXFILEREADER_HPP
#define MATRIXFILEREADER_HPP

typedef int mType;
typedef float eType;

#include <iostream>
#include <fstream>

class MatrixFileReader
{	
	public:
		MatrixFileReader(const char* f_Name) : fName(f_Name) {
			fr.open(fName, std::ios::in);
			if (!fr) {
				std::cerr << "Unable to open the file!";
				exit(1);
			} 
		}

		~MatrixFileReader() {
			if (fr.is_open()) {
				fr.close();
			}
		}

		bool read_char(char smb) {
			if (fr >> smb) {
				return true;
			} else {
				return false;
			}
		}

		bool read_num(mType& n) {
			if (fr >> n) {
				return true;
			} else {
				return false;
			}
		}

		bool read_size(mType& s) {
			if (fr >> s) {
				return true;
			} else {
				return false;
			}
		}

		bool read_elm(eType& e) {
			if (fr >> e) {
				return true;
			} else {
				return false;
			}
		}

	private:
		const char* fName;
		std::ifstream fr;
};

#endif
