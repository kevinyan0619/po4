//
// Created by Shucheng Yan on 7/21/18.
//

#include "FLOOK.h"
#include <algorithm>
#include <climits>

FLOOK::FLOOK() {}


void FLOOK::add_io(IOop *op) {
    wait_queue.push_back(op);

}

IOop *FLOOK::get_io(int trk) {

    if (io_queue.empty())
        io_queue.swap(wait_queue);

    if (io_queue.empty())
        return nullptr;


    static bool has_up = true;
    bool sym = false;

    list<IOop *>::iterator itr, itr1, itr_ss;
    int dis = INT_MAX;
    int cur_dis;

    if (has_up) {


        for (itr = io_queue.begin(); itr != io_queue.end(); itr++) {
            cur_dis = (*itr)->track - trk;

            if (cur_dis >= 0) {

                if (cur_dis < dis) {
                    dis = cur_dis;
                    itr_ss = itr;
                    sym = true;
                }
            }
        }

        if (!sym) {
            has_up = false;
            return get_io(trk);
        }
    } else {
        dis = INT_MAX;


        for (itr1 = io_queue.begin(); itr1 != io_queue.end(); itr1++) {
            cur_dis = trk - (*itr1)->track;

            if (cur_dis >= 0) {

                if (cur_dis < dis) {
                    dis = cur_dis;
                    itr_ss = itr1;
                    sym = true;
                }
            }

        }

        if (!sym) {
            has_up = true;
            return get_io(trk);
        }
    }

    IOop *op = *itr_ss;
    io_queue.erase(itr_ss);
    return op;


}