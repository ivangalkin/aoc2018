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

    std::vector<std::tuple<ll, ll>> input_real{
            {350, 353},
            {238, 298},
            {248, 152},
            {168, 189},
            {127, 155},
            {339, 202},
            {304, 104},
            {317, 144},
            {83,  106},
            {78,  106},
            {170, 230},
            {115, 194},
            {350, 272},
            {159, 69},
            {197, 197},
            {190, 288},
            {227, 215},
            {228, 124},
            {131, 238},
            {154, 323},
            {54,  185},
            {133, 75},
            {242, 184},
            {113, 273},
            {65,  245},
            {221, 66},
            {148, 82},
            {131, 351},
            {97,  272},
            {72,  93},
            {203, 116},
            {209, 295},
            {133, 115},
            {355, 304},
            {298, 312},
            {251, 58},
            {81,  244},
            {138, 115},
            {302, 341},
            {286, 103},
            {111, 95},
            {148, 194},
            {235, 262},
            {41,  129},
            {270, 275},
            {234, 117},
            {273, 257},
            {98,  196},
            {176, 122},
            {121, 258},
    };

    decltype(input_real) input_test{
            {1, 1},
            {1, 6},
            {8, 3},
            {3, 4},
            {5, 5},
            {8, 9}
    };
//    auto &input = input_test;
    auto &input = input_real;

    ll belongs_to_center(std::tuple<ll, ll> center, std::tuple<ll, ll> point) {
        assert(point != center);
        auto distance_center =
                llabs(std::get<0>(point) - std::get<0>(center)) + llabs(std::get<1>(point) - std::get<1>(center));
        for (auto other: input) {
            if (other != center && other != point) {
                auto distance_other =
                        llabs(std::get<0>(point) - std::get<0>(other)) + llabs(std::get<1>(point) - std::get<1>(other));
                if (distance_other <= distance_center) {
                    return 0;
                }
            }
        }
        return 1;
    }

    ll amount_radius(std::tuple<ll, ll> center, ll radius) {
        auto [center_x, center_y] = center;
        ll amount_radius = 0;
        // horizontal up
        for (ll x = center_x - radius; x <= center_x + radius; x++) {
            auto y = center_y - radius;
            amount_radius += belongs_to_center(center, {x, y});
        }
        // horizontal bottom
        for (ll x = center_x - radius; x <= center_x + radius; x++) {
            auto y = center_y + radius;
            amount_radius += belongs_to_center(center, {x, y});
        }
        // vertical left
        for (ll y = center_y - radius + 1; y <= center_y + radius - 1; y++) {
            auto x = center_x - radius;
            amount_radius += belongs_to_center(center, {x, y});
        }
        // vertical right
        for (ll y = center_y - radius + 1; y <= center_y + radius - 1; y++) {
            auto x = center_x + radius;
            amount_radius += belongs_to_center(center, {x, y});
        }
        return amount_radius;
    }

    ll amount(std::tuple<ll, ll> center) {
        ll amount = 0;
        ll radius = 1;
        do {
            ll amount_r = amount_radius(center, radius);
            if (amount_r == 0) {
                return amount;
            }
            amount += amount_r;
            ++radius;
            if (radius == 1000) {
                return 0;
            }
        } while (true);
    }

    ll solve_1() {
        ll max = -1;

        for (auto center: input) {
            auto center_amount = amount(center);
            myprint(center_amount);
            if (center_amount > max) {
                max = center_amount;
            }
        }

        return max;
    }

    ll belongs_to_area(std::tuple<ll, ll> point) {
        ll sum_distance = 0;
        for (auto center: input) {
            auto distance =
                    llabs(std::get<0>(point) - std::get<0>(center)) + llabs(std::get<1>(point) - std::get<1>(center));
            sum_distance += distance;
            if (sum_distance >= 10000) {
                return 0;
            }
        }
        return 1;
    }

    ll solve_2() {
        ll min_x = INT64_MAX;
        ll max_x = INT64_MIN;
        ll min_y = INT64_MAX;
        ll max_y = INT64_MIN;
        for (auto [x, y]: input) {
            min_x = std::min(min_x, x);
            max_x = std::max(max_x, x);
            min_y = std::min(min_y, y);
            max_y = std::max(max_y, y);
        }

        ll count_in_area = 0;
        constexpr ll luft = 500;
        for (ll x = min_x - luft; x <= max_x + luft; x++) {
            for (ll y = min_y - luft; y <= max_y + luft; y++) {
                count_in_area += belongs_to_area({x, y});
            }
        }
        return count_in_area;
    }
}

int main06() {

    myprint(solve_1());
    myprint(solve_2());

    return 0;
}
