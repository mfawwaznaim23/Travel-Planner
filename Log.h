#ifndef Log_H
#define Log_H

#include "Destination.h"
#include "MonumenDestination.h"
#include "SnowDestination.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class log
{
    private:
    vector <destination*> list;
    public:
    log();
    log(const log&  RHS);
    log& operator=(const log& RHS);
    ~log();
    void add_destination(destination& dest_ptr);
    void print(ofstream& output_file) const;


};


#endif