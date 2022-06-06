//
// Created by nkchuykin on 06.06.2022.
//

#ifndef INC_01_COPY_EVEN_PROFILER_H
#define INC_01_COPY_EVEN_PROFILER_H
#include <iostream>
#include <chrono>
#include <utility>


/*
 *     steady_clock::time_point start = steady_clock::now();
        stable_sort(vec_t.begin(), vec_t.end());
        steady_clock::time_point finish = steady_clock::now();
        duration<long, ratio<1, 1000000000>> dur = finish - start; //duration<long,ratio<1,1000000000>>
        cout << duration_cast<milliseconds>(dur).count() << "\n";
 *
 *
 *
 */

class LogDuration {
    std::string message;
    std::chrono::steady_clock::time_point start;
public:
    explicit LogDuration(std::string msg = {}):
        message(std::move(msg)),
        start(std::chrono::steady_clock::now())
    {

    }

    ~LogDuration(){
        auto finish = std::chrono::steady_clock::now();
        auto dur = finish - start; //duration<long,ratio<1,1000000000>>
        std::cerr << message << " " <<
            std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms\n";
    }

};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) LogDuration UNIQ_ID(__LINE__){message};
#endif //INC_01_COPY_EVEN_PROFILER_H
