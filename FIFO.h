//
// Created by Shucheng Yan on 7/21/18.
//

#ifndef LAB4_FIFO_H
#define LAB4_FIFO_H

#include "iosched.h"
#include <queue>

using namespace std;


class FIFO : public IOsched {
public:
    FIFO();

    void add_io(IOop *);

    IOop *get_io(int);

    queue<IOop *> io_queue;


};

#endif //LAB4_FIFO_H
