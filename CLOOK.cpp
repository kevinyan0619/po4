//
// Created by Shucheng Yan on 7/21/18.
//

#include "CLOOK.h"
#include <algorithm>
#include <climits>

CLOOK::CLOOK() {}

void CLOOK::add_io(IOop *op) {

    io_queue.push_back(op);

}

IOop *CLOOK::get_io(int trk) {

    if (io_queue.empty())
        return nullptr;

    list<IOop *>::iterator itr, itr1, itr_ss;

    int dis = INT_MAX;
    int cur_dis;
    bool has_up = false;


    // first go all the way up and then wrap around
    for (itr = io_queue.begin(); itr != io_queue.end(); itr++) {
        cur_dis = ((*itr)->track) - trk;

        if (cur_dis >= 0) { // go up

            if (cur_dis < dis) {
                dis = cur_dis;
                itr_ss = itr;
                has_up = true;
            }

        }

    }

    if (!has_up) {
        int min_track = INT_MAX;
        int cur_track;
        for (itr1 = io_queue.begin(); itr1 != io_queue.end(); itr1++) {
            cur_track = (*itr1)->track;
            if (cur_track < min_track) {
                min_track = cur_track;
                itr_ss = itr1;
            }
        }

    }

    IOop *op = *itr_ss;
    io_queue.erase(itr_ss);
    return op;

}
