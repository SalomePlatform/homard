#ifndef HOMARDMEDCOMMUN_H
#define HOMARDMEDCOMMUN_H

#include <vector>
#include <set>
#include <string>

std::vector<double>    GetBoundingBoxInMedFile( const char * aFile);
std::set<std::string>  GetListeGroupesInMedFile(const char * aFile);

#endif // HOMARD%MEDCOMMUN_H
