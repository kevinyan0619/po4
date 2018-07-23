//
// Created by Shucheng Yan on 7/21/18.
//

#ifndef LAB4_CLOOK_H
#define LAB4_CLOOK_H

#include "iosched.h"
#include <list>

using namespace std;

class CLOOK : public IOsched {
public:
    CLOOK();

    void add_io(IOop *);

    IOop *get_io(int);

private:
    list<IOop *> io_queue;
};

#endif //LAB4_CLOOK_H
