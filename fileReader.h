//
// Created by Shucheng Yan on 7/21/18.
//

#ifndef LAB4_FILEREADER_H
#define LAB4_FILEREADER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

string get_token(const vector<string>& list);
void init_token_list(vector<string>& token_list, string file_name);

#endif //LAB4_FILEREADER_H
