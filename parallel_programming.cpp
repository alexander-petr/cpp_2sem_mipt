#include <thread>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <future>
#include <chrono>

using clock_n = std::chrono::steady_clock;

class Timer{
public:
    Timer(): start(clock_n::now()) {}
    ~Timer(){
        auto finish = clock_n::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << std::endl;
        }
private:
    std::chrono::time_point<clock_n> start;
};
/*
template<typename Iterator, typename Function>
void parallel_for_each(Iterator begin, Iterator end, Function f) {
    // iter for middle
    auto dist = std::distance(begin, end);
    auto middle = std::next(begin, dist/2);

    std::thread other(std::for_each<Iterator, Function>, begin, middle, f);
    std::for_each(middle, end, f);

    other.join();

}*/


template<typename Iterator, typename Function>
void parallel_for_each(Iterator begin, Iterator end, Function f) {
        auto num_threads = std::thread::hardware_concurrency();
        auto dist = std::distance(begin, end);
        auto block_size = dist / num_threads;

        std::vector<std::thread> threads;
        for(auto i = 0; i + 1 < num_threads; i++){
            threads.push_back(std::thread(std::for_each<Iterator, Function>, std::next(begin, i * block_size), std::next(begin, (i + 1) * block_size), f));
        }
        auto start = std::next(begin, (num_threads - 1) * block_size);
        std::for_each(start, end, f);
        for(auto& thread: threads) {
            thread.join();
        }
}

template<typename Iterator, typename T>
T parallel_accumulate(Iterator begin, Iterator end, T initial) {
        auto dist = std::distance(begin, end);
        auto middle = std::next(begin, dist/2);
        auto future = std::async(std::launch::async, std::accumulate<Iterator, T>, begin, middle, T(0));

        auto sum = std::accumulate(middle, end, initial);
        return sum + future.get();
}

int main(){

    auto mul2 = [](auto& item){item *= 2;};
    std::vector<int> nums(1);
    //std::iota(nums.begin(), nums.end(), 0);
    for(auto& num: nums){
        num = 1;
    }
    {
        Timer t;
        //parallel_for_each(nums.begin(), nums.end(), mul2);
        std::cout << parallel_accumulate(nums.begin(), nums.end(), 0) << std::endl;
    }
    {
        Timer t;
        //std::for_each(nums.begin(), nums.end(), mul2);
        std::cout << std::accumulate(nums.begin(), nums.end(), 0) << std::endl;

    }

    std::cout << std::thread::hardware_concurrency() << std::endl;
}
