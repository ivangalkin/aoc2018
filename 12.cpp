#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

#define ASSERT_EQ(a, b) \
   do { __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     if (_a != _b)       \
     {                 \
       std::cout << _a << " != " << _b << std::endl; \
       assert(0);                  \
     }                  \
     }while(0)

#define myprint(arg) do { std::cout << "" #arg << " = " << arg << std::endl; } while(0)

using ll = int64_t;

namespace {

    std::string input_real = "##.####..####...#.####..##.#..##..#####.##.#..#...#.###.###....####.###...##..#...##.#.#...##.##..";
    std::map<std::string, char> rules_real = {
            {"##.##", '#'},
            {"....#", '.'},
            {".#.#.", '#'},
            {"..###", '.'},
            {"##...", '#'},
            {"#####", '.'},
            {"###.#", '#'},
            {".##..", '.'},
            {"..##.", '.'},
            {"...##", '#'},
            {"####.", '.'},
            {"###..", '.'},
            {".####", '#'},
            {"#...#", '#'},
            {".....", '.'},
            {"..#..", '.'},
            {"#..##", '.'},
            {"#.#.#", '#'},
            {".#.##", '#'},
            {".###.", '.'},
            {"##..#", '.'},
            {".#...", '#'},
            {".#..#", '#'},
            {"...#.", '.'},
            {"#.#..", '.'},
            {"#....", '.'},
            {"##.#.", '.'},
            {"#.###", '.'},
            {".##.#", '.'},
            {"#..#.", '#'},
            {"..#.#", '.'},
            {"#.##.", '#'},
    };

    decltype(input_real) input_test = "#..#.#..##......###...###";
    decltype(rules_real) rules_test{
            {"...##", '#'},
            {"..#..", '#'},
            {".#...", '#'},
            {".#.#.", '#'},
            {".#.##", '#'},
            {".##..", '#'},
            {".####", '#'},
            {"#.#.#", '#'},
            {"#.###", '#'},
            {"##.#.", '#'},
            {"##.##", '#'},
            {"###..", '#'},
            {"###.#", '#'},
            {"####.", '#'},
    };


    auto &input = input_real;
    auto &rules = rules_real;
    //    auto &input = input_test;
    //    auto &rules = rules_test;

    ll part1() {
        constexpr ll GENERATIONS = 20;
        constexpr ll OFFSET = GENERATIONS + 2;
        ll result = 0;
        std::string padding(OFFSET, '.');
        std::string padded_input = padding + input + padding;
        auto current_generation = padded_input;
        auto next_generation = std::string(padded_input.length(), '.');

        ll generation_nr = 0;
        for (; generation_nr < GENERATIONS; generation_nr++) {
            for (ll pos = 2; pos < padded_input.size(); pos++) {
                const auto frame = current_generation.substr(pos - 2, 5);
                auto rules_it = rules.find(frame);
                if (rules_it != rules.end()) {
                    next_generation.at(pos) = rules_it->second;
                } else {
                    next_generation.at(pos) = '.';
                }
            }
            std::swap(current_generation, next_generation);
            std::fill(next_generation.begin(), next_generation.end(), '.');
        }

        for (ll pos = 0; pos < current_generation.size(); pos++) {
            if (current_generation.at(pos) == '#') {
                result += (pos - OFFSET);
            }
        }
        return result;
    }

    ll part2(){
        ll result = 0;
        constexpr ll GENERATIONS = 5000;
        constexpr ll OFFSET = GENERATIONS + 2;
        std::string padding(OFFSET, '.');
        std::string padded_input = padding + input + padding;
        auto current_generation = padded_input;
        auto next_generation = std::string(padded_input.length(), '.');

        ll generation_nr = 0;
        std::vector<ll> repeated_shifts;
        for (; generation_nr < GENERATIONS; generation_nr++) {

            for (ll pos = 2; pos < padded_input.size(); pos++) {
                const auto frame = current_generation.substr(pos - 2, 5);
                auto rules_it = rules.find(frame);
                if (rules_it != rules.end()) {
                    next_generation.at(pos) = rules_it->second;
                } else {
                    next_generation.at(pos) = '.';
                }
            }

            // observation:
            // at some point generations come into balance:
            // they literally start having the same pattern shifted right (or left?)
            // solution:
            // 1. detect the cycle, the generation when it happens and the shifting pattern
            // 2. extrapolate generation to the generation 50000000000

            auto current_first_plant_pos = current_generation.find_first_of('#');
            auto current_last_plant_pos = current_generation.find_last_of('#');

            auto next_first_plant_pos = next_generation.find_first_of('#');
            auto next_last_plant_pos = next_generation.find_last_of('#');

            if (current_generation.substr(current_first_plant_pos, current_last_plant_pos - current_first_plant_pos + 1) ==
                next_generation.substr(next_first_plant_pos, next_last_plant_pos - next_first_plant_pos + 1)) {
                ll shift = next_first_plant_pos - current_first_plant_pos;
                if (repeated_shifts.empty() || repeated_shifts.back() == shift) {
                    repeated_shifts.push_back(shift);
                } else  {
                    repeated_shifts.clear();
                }
            } else {
                repeated_shifts.clear();
            }

            std::swap(current_generation, next_generation);
            std::fill(next_generation.begin(), next_generation.end(), '.');

            if (repeated_shifts.size() == 100) {
                break;
            }
        }

        ll generations_done = generation_nr  +1 ;
        ll generations_left_to_do = 50000000000ll - generations_done;
        ll final_shift = (generations_left_to_do * repeated_shifts.back())- OFFSET;

        for (ll pos = 0; pos < current_generation.size(); pos++) {
            if (current_generation.at(pos) == '#') {
                result += (pos + final_shift);
            }
        }
        return result;
    }
}

int main12() {
    ASSERT_EQ(part1(), 1623);
    ASSERT_EQ(part2(), 1600000000401);

    return 0;
}
