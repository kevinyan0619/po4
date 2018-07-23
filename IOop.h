//
// Created by Shucheng Yan on 7/21/18.
//

#ifndef LAB4_IOOP_H
#define LAB4_IOOP_H

typedef struct IOop {
    int op_num;
    int track;
    int arrival_time;
    int start_time;
    int end_time;

    IOop(int o, int a, int t) : op_num(o), track(t), arrival_time(a), start_time(0), end_time(0) {}

} IOop;


#endif //LAB4_IOOP_H
