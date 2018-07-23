//
// Created by Shucheng Yan on 7/21/18.
//

#ifndef LAB4_FLOOK_H
#define LAB4_FLOOK_H

#include "iosched.h"
#include <list>


using namespace std;

class FLOOK : public IOsched {
public:
    FLOOK();

    void add_io(IOop *);

    IOop *get_io(int);

private:

    list<IOop*> io_queue;
    list<IOop*> wait_queue;


};


#endif //LAB4_FLOOK_H
