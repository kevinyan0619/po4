//
// Created by Shucheng Yan on 7/21/18.
//

#ifndef LAB4_SUM_INFO_H
#define LAB4_SUM_INFO_H

typedef struct Sum {
    int io_count;
    int total_time;
    int total_movement;
    unsigned long long total_turn;
    unsigned long long total_wait;
    double avg_turnaround;
    double avg_waittime;
    int max_waittime;

} Sum;


#endif //LAB4_SUM_INFO_H
