//
// Created by Shucheng Yan on 7/21/18.
//

#ifndef LAB4_IOSCHED_H
#define LAB4_IOSCHED_H

#include "IOop.h"

class IOsched {
public:
    IOsched() = default ;

    virtual void add_io(IOop *) = 0;

    virtual IOop *get_io(int) = 0;
};

#endif //LAB4_IOSCHED_H
