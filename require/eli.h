#ifndef ELI_dsfx3d
#define ELI_dsfx3d

#include "eli_def.h"

#define CHK_FILE_ACCESS(m)if(!file.is_open()){FILE_ACCESS_ERR;return m;}

/*
note: open file to read entire content
 
ReadMode : true - reading doped file
		   false- reading plain file */
std::string ELI::readFile(FilePath path, StartOffset offset) {
	int beg=0;
	Data data;
	
	ifstream file(&(path[0]));

	CHK_FILE_ACCESS(data);
	
	file.seekg(0, ios::end);   
	data.reserve(file.tellg());
	file.seekg(beg+offset, ios::beg);

	data.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	
	return data;
}
/**/
std::string ELI::readFile(FilePath path, StartOffset offset, EndOffset eoffset) {
	int beg=0;
	Data data;
	
	ifstream file(&(path[0]));

	CHK_FILE_ACCESS(data);
	
	file.seekg(0, ios::end);   
	data.reserve(file.tellg());
	file.seekg(offset, ios::beg);

	data.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	
	return data;
}
/**/
void ELI::writeFile(FilePath path, Data data) {
	ofstream file(&(path[0]));
	file<<data;
	file.close();
}
/**/
int ELI::_searchc(FilePath path, char c, MinimumCharOccurance mino) {
	
}
/**/
#endif
