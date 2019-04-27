#include "Definition.h"
#include <string>
#ifndef __DELETECHANGE_H__
#define __DELETECHANGE_H__
void Delete(date *&Date, int &size, int &count, int DD, int MM, int YYYY, int Del_Type, int Number, std::string Info);
void Change(date *&Date, int size, int DD, int MM, int YYYY, int Change_Type, int Number, std::string Info);
#endif
