//
// Created by Shucheng Yan on 7/21/18.
//

#include "FIFO.h"

FIFO::FIFO() {}

void FIFO::add_io(IOop *op) {
    io_queue.push(op);
}

IOop *FIFO::get_io(int trk) {
    if (!io_queue.empty()) {
        IOop *op = io_queue.front();
        io_queue.pop();
        return op;
    }

    return nullptr;
}
