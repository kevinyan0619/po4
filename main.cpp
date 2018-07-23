#include <iostream>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

#include "fileReader.h"
#include "FIFO.h"
#include "SSTF.h"
#include "CLOOK.h"
#include "LOOK.h"
#include "FLOOK.h"
#include "sum_info.h"

#include <string>
#include <algorithm>


void print_opstats(const vector<IOop *> &op_list);

void print_sum(const Sum &sum);

int main(int argc, char **argv) {
    vector<string> token_list;
    vector<IOop *> op_list;

    string file_name = argv[argc - 1];
    //init_token_list(token_list, "/Users/shuchengyan/CLionProjects/lab4/input3");
    init_token_list(token_list, file_name);

    Sum sum;
    //token_list.push_back("");
    int num = 0;


    for (int i = 0; i < token_list.size() - 1; i = i + 2) {
        int arv = stoi(token_list[i]);
        int trk = stoi(token_list[i + 1]);

        auto *op = new IOop(num, arv, trk);
        op_list.push_back(op);
        num++;
    }


    IOsched *sched;
    int c = 0;
    string algo;

    while ((c = getopt(argc, argv, "s:")) != -1) {
        switch (c) {
            case 's':
                algo = optarg;
                if (algo == "i") {
                    sched = new FIFO();
                } else if (algo == "j") {
                    sched = new SSTF();
                } else if (algo == "s") {
                    sched = new LOOK();
                } else if (algo == "c") {
                    sched = new CLOOK();
                } else if (algo == "f") {
                    sched = new FLOOK();
                } else {
                    fprintf(stderr, "Unknown argument for option -%c.\n", c);
                    exit(1);
                }
                break;
            case '?':
                if (optopt == 's')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option '-%c'.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
                exit(1);
            default:
                exit(1);
        }
    }

//    for (int i = 0; i < op_list.size(); i++)
//        cout << op_list[i]->op_num << " " << op_list[i]->arrival_time << " " << op_list[i]->track << '\n';


    //sched = new FLOOK();

    int cur_time = 0;
    int cur_track = 0;
    IOop *cur_io;
    cur_io = nullptr;
    int future_io = 0;

    int move;
    int wait;
    int turn;


    while (future_io < op_list.size() || cur_io != nullptr) {

        cur_time++;

//        if (cur_time == 15000)
//            break;


        // check arrival of new io request
        if (future_io < op_list.size() && (op_list[future_io])->arrival_time == cur_time) {
            sched->add_io(op_list[future_io]);

            // cout << cur_time << " " << op_list[future_io]->op_num << " add " << op_list[future_io]->track << '\n';

            future_io++;
        }

        // io finished
        if (cur_io != nullptr && (cur_io->end_time) == cur_time) {
            cur_track = cur_io->track;

            // cout << cur_time << " " << cur_io->op_num << " finish " << cur_io->end_time - cur_io->arrival_time << '\n';
            cur_io = nullptr;
        }

        // get next io request
        if (cur_io == nullptr) {
            cur_io = sched->get_io(cur_track);


            // no more pending io request
            if (cur_io == nullptr) {
                continue;
            }

            //cout << cur_time << " " << cur_io->op_num << " issue " << cur_io->track << " " << cur_track << '\n';

            cur_io->start_time = cur_time;

            move = abs(cur_track - cur_io->track);
            cur_io->end_time = cur_io->start_time + move;


            wait = (cur_io->start_time) - (cur_io->arrival_time);
            if (wait > sum.max_waittime)
                sum.max_waittime = wait;


            turn = (cur_io->end_time) - (cur_io->arrival_time);


            if (move == 0)
                cur_time--;

            sum.total_movement += move;
            sum.total_turn += turn;
            sum.total_wait += wait;
            sum.io_count++;

        }

        //cout << cur_time << ' ' << cur_io->op_num << '\n';
    }
    sum.total_time = cur_time;
    sum.avg_turnaround = sum.total_turn / (double) sum.io_count;
    sum.avg_waittime = sum.total_wait / (double) sum.io_count;


    print_opstats(op_list);
    print_sum(sum);
    //cout << "Hello, World!" << std::endl;

    return 0;
}

void print_opstats(const vector<IOop *> &op_list) {
//    cout << '\n';
    for (int i = 0; i < op_list.size(); i++) {
        IOop *req = op_list[i];

        printf("%5d: %5d %5d %5d\n", i, req->arrival_time, req->start_time, req->end_time);
    }
}

void print_sum(const Sum &sum) {
    printf("SUM: %d %d %.2lf %.2lf %d\n",
           sum.total_time, sum.total_movement, sum.avg_turnaround,
           sum.avg_waittime, sum.max_waittime);

}