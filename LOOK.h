//
// Created by Shucheng Yan on 7/22/18.
//

#ifndef LAB4_LOOK_H
#define LAB4_LOOK_H

#include "iosched.h"
#include <list>

using namespace std;

class LOOK : public IOsched {
public:
    LOOK();

    void add_io(IOop *);

    IOop *get_io(int);

private:
    list<IOop *> io_queue;
};

#endif //LAB4_LOOK_H
