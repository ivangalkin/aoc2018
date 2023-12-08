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

    constexpr ll SIZE = 300;
    constexpr ll SERIAL_NR = 5535;

    std::vector<std::vector<ll>> matrix(SIZE);
    ll max = INT64_MIN;
    ll max_j = 0;
    ll max_i = 0;
    ll max_size = 0;

    void part1() {
        max = INT64_MIN;
        max_j = 0;
        max_i = 0;

        for (ll j = 0; j < SIZE - 2; j++) {
            for (ll i = 0; i < SIZE - 2; i++) {
                ll sum = 0;
                for (ll jx = 0; jx < 3; jx++) {
                    for (ll ix = 0; ix < 3; ix++) {
                        sum += matrix.at(j + jx).at(i + ix);
                    }
                }
                if (sum > max) {
                    max = sum;
                    max_j = j + 1;
                    max_i = i + 1;
                }
            }
        }

        std::cout << max_i << "," << max_j << std::endl;
    }

    void calculate(ll i, ll j, ll size, ll previous_sum) {
        ll sum;
        if (size == 1) {
            sum = matrix.at(j).at(i);
            if (sum > max) {
                max = sum;
                max_j = j + 1;
                max_i = i + 1;
                max_size = size;
            }
        } else {
            const ll new_index_j = j + size - 1;
            const ll new_index_i = i + size - 1;

            if (new_index_j >= matrix.size() || new_index_i >= matrix.size()) {
                return;
            }

            sum = previous_sum;
            for (ll ix = 0; ix < size; ix++) {
                sum += matrix.at(new_index_j).at(i + ix);
            }
            for (ll jx = 0; jx < size - 1; jx++) {
                sum += matrix.at(j + jx).at(new_index_i);
            }

            if (sum > max) {
                max = sum;
                max_j = j + 1;
                max_i = i + 1;
                max_size = size;
            }

        }
        calculate(i, j, size + 1, sum);
    }

    void part2() {
        max = INT64_MIN;
        max_j = 0;
        max_i = 0;
        max_size = 0;

        for (ll j = 0; j < SIZE; j++) {
            for (ll i = 0; i < SIZE; i++) {
                calculate(i, j, 1, 0);
            }
        }

        std::cout << max_i << "," << max_j << "," << max_size << std::endl;
    }
}

int main11() {
    int64_t result0 = 0;
    int64_t result1 = 0;


    for (ll j = 0; j < SIZE; j++) {
        matrix.at(j).resize(SIZE);
        for (ll i = 0; i < SIZE; i++) {
            const ll x = i + 1;
            const ll y = j + 1;
            const ll rack_id = x + 10;
            ll power_level = rack_id * y;
            power_level += SERIAL_NR;
            power_level *= rack_id;
            power_level = (power_level / 100) % 10;
            power_level -= 5;
            matrix.at(j).at(i) = power_level;
        }
    }

    part1();
    part2();

    return 0;
}
