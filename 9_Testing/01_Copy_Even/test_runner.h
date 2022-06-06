#ifndef INC_01_COPY_EVEN_TEST_RUNNER_H
#define INC_01_COPY_EVEN_TEST_RUNNER_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <set>
#include <map>

template<typename T>
std::ostream &operator<<(std::ostream &out, std::set<T> container);


void Assert(bool b,
            const std::string &hint = {});

template<typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> container) {
    out << "[";
    bool is_first = true;
    for (auto &el: container) {
        if (!is_first) {
            out << ", ";
        } else {
            is_first = false;
        }
        out << el;
    }
    out << "]";
    return out;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, std::set<T> container) {
    out << "{";
    bool is_first = true;
    for (auto &el: container) {
        if (!is_first) {
            out << ", ";
        } else {
            is_first = false;
        }
        out << el;
    }
    out << "}";
    return out;
}


template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, std::map<K, V> container) {
    out << "{";
    bool is_first = true;
    for (auto &[k, v]: container) {
        if (!is_first) {
            out << ", ";
        } else {
            is_first = false;
        }
        out << k << " : " << v;
    }
    out << "}";
    return out;
}

template<typename V, typename U>
void AssertEqual(const V &first,
                 const U &second,
                 const std::string &hint = {}) {
    if (first != second) {
        std::ostringstream out;
        out << "Assertion error " << first << " != "
            << second << "\n";
        if (!hint.empty()) {
            out << "hint: " << hint << std::endl;
        }
        throw std::runtime_error(out.str());
    }
}

class TestRunner {
    int fail_count = 0;
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const std::string &testname) {
        try {
            func();
            std::cerr << testname << " OK\n";
        } catch (std::exception& e) {
            ++fail_count;
            std::cerr << testname
                << " failed: " << e.what() << std::endl;
        } catch (...) {
            ++fail_count;
            std::cerr << "Unknown exception" << std:: endl;
        }

    }
            ~TestRunner(){
                if (fail_count > 0){
                    std::cerr << fail_count << " tests failed. "
                                               "Terminate program";
                    exit(1);
                }

            }

};

#define ASSERT_EQUAL(x,y) { \
    ostringstream os;        \
    os << #x << "!= " << #y << ", " \
        << __FILE__ << ":" <<__LINE__; \
    AssertEqual(x,y, os.str());    \
}

#define ASSERT(x) { \
    ostringstream os;        \
    os << #x << "is false, " \
        << __FILE__ << ":" <<__LINE__; \
    Assert(x, os.str());    \
}

#define RUN_TEST(tr,func) \
   tr.RunTest(func,#func)

#endif //INC_01_COPY_EVEN_TEST_RUNNER_H
