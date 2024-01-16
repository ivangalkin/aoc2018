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

    std::vector<std::string> input_real{

    };

    decltype(input_real) input_test;
//    auto &input = input_test;
    auto &input = input_real;
}

int main14() {
    int64_t result0 = 0;
    int64_t result1 = 0;

    std::vector<ll> cards{3, 7};
    ll idx_0 = 0;
    ll idx_1 = 1;

    auto do_turn = [&cards](ll &idx) {
        auto nr_steps = cards.at(idx) + 1;
        for (ll step = 0; step < nr_steps; step++) {
            idx = (idx + 1) % cards.size();
        }
    };

    const std::vector<ll> expected_ending = {7, 6, 5, 0, 7, 1};
    auto check_last_6_digits = [&cards, &expected_ending]() {
        if (cards.size() < 6) {
            return false;
        }
        std::vector<ll> last_6_digits = {
                cards.at(cards.size() - 6),
                cards.at(cards.size() - 5),
                cards.at(cards.size() - 4),
                cards.at(cards.size() - 3),
                cards.at(cards.size() - 2),
                cards.at(cards.size() - 1),
        };
        if (last_6_digits == expected_ending) {
            return true;
        }
        return false;
    };
    //ll expected_cards = 9;
    ll expected_cards = 765071;
    while (true) {

        do_turn(idx_0);
        do_turn(idx_1);
        auto sum = cards.at(idx_0) + cards.at(idx_1);
        if (sum < 10) {
            cards.push_back(sum);
            if (check_last_6_digits()) {
                std::cout << "Part2: nr of cards before = " << cards.size() - 6 << std::endl;
                break;
            }
        } else {
            cards.push_back(sum / 10);
            if (check_last_6_digits()) {
                std::cout << "Part2: nr of cards before = " << cards.size() - 6 << std::endl;
                break;
            }
            cards.push_back(sum % 10);
            if (check_last_6_digits()) {
                std::cout << "Part2: nr of cards before = " << cards.size() - 6 << std::endl;
                break;
            }
        }
    }

    assert(cards.size() > expected_cards + 10);
    std::cout << "Part1: ";
    for (ll card = expected_cards; card < expected_cards + 10; card++) {
        std::cout << cards.at(card);
    }
    std::cout << std::endl;

    return 0;
}
