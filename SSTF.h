//
// Created by Shucheng Yan on 7/21/18.
//

#ifndef LAB4_SSTF_H
#define LAB4_SSTF_H

#include "iosched.h"
#include <vector>

using namespace std;

class SSTF : public IOsched {
public:
    SSTF();

    void add_io(IOop *);

    IOop *get_io(int);

private:

    vector<IOop *> io_queue;


};

#endif //LAB4_SSTF_H
