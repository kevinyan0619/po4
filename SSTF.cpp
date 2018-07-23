//
// Created by Shucheng Yan on 7/21/18.
//

#include "SSTF.h"
#include <algorithm>
#include <climits>

SSTF::SSTF() {}


void SSTF::add_io(IOop *op) {
    io_queue.push_back(op);
}

//IOop *SSTF::get_io(int trk) {
//    if (io_queue.empty())
//        return nullptr;
//
//
//    vector<IOop *>::iterator itr, itr_ss;
//    int dis = INT_MAX;
//
//    for (itr = io_queue.begin(); itr != io_queue.end(); itr++) {
//        int cur_dis = abs((*itr)->track - trk);
//
//        if (cur_dis < dis) {
//            dis = cur_dis;
//            itr_ss = itr;
//        }
//    }
//
//    IOop *op = *itr_ss;
//    io_queue.erase(itr_ss);
//    return op;
//}


IOop *SSTF::get_io(int trk) {
    if (io_queue.empty())
        return nullptr;


    //vector<IOop *>::iterator itr, itr_ss;
    int dis = INT_MAX;
    int cur_dis;
    int min_index = -1;

    for (int i = 0; i < io_queue.size(); i++) {
        cur_dis = abs(io_queue[i]->track - trk);
        if (cur_dis < dis) {
            dis = cur_dis;
            min_index = i;
        }
    }

    IOop *op = io_queue[min_index];
    io_queue.erase(io_queue.begin() + min_index);
    return op;
}
//    for (itr = io_queue.begin(); itr != io_queue.end(); itr++) {
//        int cur_dis = abs((*itr)->track - trk);
//
//        if (cur_dis < dis) {
//            dis = cur_dis;
//            itr_ss = itr;
//        }
//    }
//
//    IOop *op = *itr_ss;
//    io_queue.erase(itr_ss);
//    return op;
////}


//IOop *SSTF::get_io(int trk) {
//    if (io_queue.empty())
//        return nullptr;
//
//    auto it = min_element(
//            io_queue.begin(),
//            io_queue.end(),
//            [trk](const IOop* a, const IOop* b)
//            { return abs(a->track - trk) < abs(b->track - trk); }
//    );
//    IOop* tmp = *it;
//    io_queue.erase(it);
//
//    return tmp;
//}

