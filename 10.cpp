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

struct Point {
    ll x;
    ll y;

    bool operator<(const Point &other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }
};

std::vector<std::tuple<Point, Point>> input_real{
        {{-50948, 20587},  {5,  -2}},
        {{20732,  -51094}, {-2, 5}},
        {{-30471, -10131}, {3,  1}},
        {{-40758, 10355},  {4,  -1}},
        {{30912,  20590},  {-3, -2}},
        {{30927,  30827},  {-3, -3}},
        {{-20237, 20591},  {2,  -2}},
        {{51423,  -51086}, {-5, 5}},
        {{-40732, -20370}, {4,  2}},
        {{-20271, -51094}, {2,  5}},
        {{-40764, -30605}, {4,  3}},
        {{-30492, 41073},  {3,  -4}},
        {{-30473, -30614}, {3,  3}},
        {{-51004, 41074},  {5,  -4}},
        {{-30481, 30829},  {3,  -3}},
        {{-50961, -10130}, {5,  1}},
        {{-50968, 51306},  {5,  -5}},
        {{-30489, -40850}, {3,  4}},
        {{-20273, 51307},  {2,  -5}},
        {{-40732, 10351},  {4,  -1}},
        {{-40764, -30612}, {4,  3}},
        {{10483,  51307},  {-1, -5}},
        {{-30511, -30614}, {3,  3}},
        {{20719,  -40848}, {-2, 4}},
        {{-20249, -10129}, {2,  1}},
        {{30919,  -51090}, {-3, 5}},
        {{-20281, 20595},  {2,  -2}},
        {{30931,  30830},  {-3, -3}},
        {{-20240, 41071},  {2,  -4}},
        {{-9988,  -51087}, {1,  5}},
        {{-50991, 51315},  {5,  -5}},
        {{-10022, 30826},  {1,  -3}},
        {{-20241, 30830},  {2,  -3}},
        {{10492,  -30610}, {-1, 3}},
        {{-30525, 51313},  {3,  -5}},
        {{10492,  -20370}, {-1, 2}},
        {{10492,  -20371}, {-1, 2}},
        {{-20255, 30830},  {2,  -3}},
        {{51403,  20595},  {-5, -2}},
        {{10489,  -20370}, {-1, 2}},
        {{10492,  41067},  {-1, -4}},
        {{20722,  -40854}, {-2, 4}},
        {{10451,  30830},  {-1, -3}},
        {{10452,  -10125}, {-1, 1}},
        {{41151,  51306},  {-4, -5}},
        {{51410,  -30610}, {-5, 3}},
        {{-20289, -51093}, {2,  5}},
        {{-40708, 30828},  {4,  -3}},
        {{-20244, -40851}, {2,  4}},
        {{-20257, -30612}, {2,  3}},
        {{30943,  -10131}, {-3, 1}},
        {{-40718, 10346},  {4,  -1}},
        {{-40769, -51091}, {4,  5}},
        {{30967,  41074},  {-3, -4}},
        {{-40728, -30614}, {4,  3}},
        {{-40711, 20589},  {4,  -2}},
        {{10487,  -51090}, {-1, 5}},
        {{10459,  20595},  {-1, -2}},
        {{-10025, 10346},  {1,  -1}},
        {{30913,  41066},  {-3, -4}},
        {{51407,  20595},  {-5, -2}},
        {{30911,  -10134}, {-3, 1}},
        {{-40769, 51310},  {4,  -5}},
        {{-10001, -51085}, {1,  5}},
        {{-10004, 20594},  {1,  -2}},
        {{-20281, -40849}, {2,  4}},
        {{51444,  -20365}, {-5, 2}},
        {{-40769, 20593},  {4,  -2}},
        {{41183,  20588},  {-4, -2}},
        {{30932,  51315},  {-3, -5}},
        {{41192,  -10130}, {-4, 1}},
        {{10488,  41068},  {-1, -4}},
        {{-10022, -20370}, {1,  2}},
        {{30954,  30831},  {-3, -3}},
        {{-30513, -40845}, {3,  4}},
        {{51428,  30831},  {-5, -3}},
        {{-40760, -40845}, {4,  4}},
        {{-10009, 30832},  {1,  -3}},
        {{41151,  20586},  {-4, -2}},
        {{30972,  30831},  {-3, -3}},
        {{20675,  -30607}, {-2, 3}},
        {{51436,  -30606}, {-5, 3}},
        {{-50977, -40852}, {5,  4}},
        {{10471,  -40847}, {-1, 4}},
        {{10463,  20590},  {-1, -2}},
        {{30911,  -10129}, {-3, 1}},
        {{10476,  41074},  {-1, -4}},
        {{51423,  51309},  {-5, -5}},
        {{-50948, -20367}, {5,  2}},
        {{51419,  30835},  {-5, -3}},
        {{10474,  51306},  {-1, -5}},
        {{10431,  51308},  {-1, -5}},
        {{-40733, 41074},  {4,  -4}},
        {{30915,  51306},  {-3, -5}},
        {{30959,  10354},  {-3, -1}},
        {{30972,  20595},  {-3, -2}},
        {{30913,  -30610}, {-3, 3}},
        {{-10041, -20368}, {1,  2}},
        {{-50972, -20368}, {5,  2}},
        {{-30476, 30828},  {3,  -3}},
        {{41196,  -40851}, {-4, 4}},
        {{-40753, -20374}, {4,  2}},
        {{30927,  -20368}, {-3, 2}},
        {{-20271, -10130}, {2,  1}},
        {{-10046, -40850}, {1,  4}},
        {{-20244, 51308},  {2,  -5}},
        {{-20280, 30835},  {2,  -3}},
        {{51391,  -30610}, {-5, 3}},
        {{20724,  -20365}, {-2, 2}},
        {{-40710, 10352},  {4,  -1}},
        {{-20289, 41075},  {2,  -4}},
        {{20690,  -51085}, {-2, 5}},
        {{-40729, 30834},  {4,  -3}},
        {{51428,  51313},  {-5, -5}},
        {{-9998,  -10129}, {1,  1}},
        {{20728,  -30612}, {-2, 3}},
        {{51447,  41075},  {-5, -4}},
        {{41159,  -30605}, {-4, 3}},
        {{-40744, -20374}, {4,  2}},
        {{41188,  -51085}, {-4, 5}},
        {{30943,  -10126}, {-3, 1}},
        {{-10006, -10134}, {1,  1}},
        {{51399,  -10131}, {-5, 1}},
        {{41204,  30834},  {-4, -3}},
        {{30914,  -40850}, {-3, 4}},
        {{30948,  -51093}, {-3, 5}},
        {{-30486, 30826},  {3,  -3}},
        {{10439,  10346},  {-1, -1}},
        {{20721,  -51089}, {-2, 5}},
        {{-50956, -10130}, {5,  1}},
        {{10464,  -30613}, {-1, 3}},
        {{10492,  -30608}, {-1, 3}},
        {{-10031, 10346},  {1,  -1}},
        {{30953,  30830},  {-3, -3}},
        {{41204,  51308},  {-4, -5}},
        {{20695,  -10127}, {-2, 1}},
        {{-40709, -10126}, {4,  1}},
        {{-30497, -20369}, {3,  2}},
        {{51396,  10354},  {-5, -1}},
        {{20698,  41075},  {-2, -4}},
        {{-20286, -51089}, {2,  5}},
        {{30955,  41066},  {-3, -4}},
        {{-10046, 30830},  {1,  -3}},
        {{-20254, 10352},  {2,  -1}},
        {{-9993,  -51094}, {1,  5}},
        {{-50967, -40850}, {5,  4}},
        {{-40753, -51088}, {4,  5}},
        {{-20272, 30835},  {2,  -3}},
        {{10475,  51313},  {-1, -5}},
        {{-40769, -40851}, {4,  4}},
        {{51447,  -10128}, {-5, 1}},
        {{-10036, 20595},  {1,  -2}},
        {{51431,  -40852}, {-5, 4}},
        {{41204,  -10127}, {-4, 1}},
        {{51448,  51307},  {-5, -5}},
        {{-51008, -51094}, {5,  5}},
        {{20727,  -20369}, {-2, 2}},
        {{-50969, 41075},  {5,  -4}},
        {{20707,  10353},  {-2, -1}},
        {{51447,  -10130}, {-5, 1}},
        {{10439,  20588},  {-1, -2}},
        {{10490,  -20368}, {-1, 2}},
        {{-40769, 41068},  {4,  -4}},
        {{30915,  -51090}, {-3, 5}},
        {{-20273, 30831},  {2,  -3}},
        {{10463,  20586},  {-1, -2}},
        {{51417,  41075},  {-5, -4}},
        {{-50948, 41071},  {5,  -4}},
        {{-30470, 20591},  {3,  -2}},
        {{51439,  51311},  {-5, -5}},
        {{51399,  51307},  {-5, -5}},
        {{-30478, -40849}, {3,  4}},
        {{-40727, 41070},  {4,  -4}},
        {{-30503, 51306},  {3,  -5}},
        {{-20252, 51308},  {2,  -5}},
        {{-20265, -51094}, {2,  5}},
        {{-30468, -40846}, {3,  4}},
        {{-30501, -30611}, {3,  3}},
        {{-20263, -40849}, {2,  4}},
        {{20714,  20591},  {-2, -2}},
        {{-20252, -40854}, {2,  4}},
        {{-40729, -40853}, {4,  4}},
        {{-10047, 30826},  {1,  -3}},
        {{10479,  -51088}, {-1, 5}},
        {{51443,  41071},  {-5, -4}},
        {{-50969, -40854}, {5,  4}},
        {{-40742, -20374}, {4,  2}},
        {{41155,  20592},  {-4, -2}},
        {{41175,  41074},  {-4, -4}},
        {{20679,  20594},  {-2, -2}},
        {{-20265, 10355},  {2,  -1}},
        {{41184,  20587},  {-4, -2}},
        {{41177,  -40845}, {-4, 4}},
        {{30938,  -20374}, {-3, 2}},
        {{20732,  30830},  {-2, -3}},
        {{-20273, 51314},  {2,  -5}},
        {{41178,  51310},  {-4, -5}},
        {{20687,  30829},  {-2, -3}},
        {{-50964, 10347},  {5,  -1}},
        {{51391,  -51093}, {-5, 5}},
        {{-30485, -51088}, {3,  5}},
        {{-30468, -30611}, {3,  3}},
        {{-30513, 51312},  {3,  -5}},
        {{-40753, 10347},  {4,  -1}},
        {{-50993, 51308},  {5,  -5}},
        {{41194,  -51089}, {-4, 5}},
        {{30919,  -30607}, {-3, 3}},
        {{51436,  51315},  {-5, -5}},
        {{-20245, -20368}, {2,  2}},
        {{30913,  -20370}, {-3, 2}},
        {{30943,  -51086}, {-3, 5}},
        {{-20273, 41073},  {2,  -4}},
        {{10484,  -40850}, {-1, 4}},
        {{10492,  -40848}, {-1, 4}},
        {{-10009, 30826},  {1,  -3}},
        {{20679,  -20368}, {-2, 2}},
        {{-50959, -30614}, {5,  3}},
        {{-40741, -10134}, {4,  1}},
        {{30919,  30834},  {-3, -3}},
        {{-10033, 30833},  {1,  -3}},
        {{-30489, 30831},  {3,  -3}},
        {{-30492, -40848}, {3,  4}},
        {{-40720, -30613}, {4,  3}},
        {{-50993, -30612}, {5,  3}},
        {{-40745, -20365}, {4,  2}},
        {{-10024, -20368}, {1,  2}},
        {{41152,  30830},  {-4, -3}},
        {{30951,  20586},  {-3, -2}},
        {{-40740, 41075},  {4,  -4}},
        {{51416,  -40845}, {-5, 4}},
        {{-30527, -51090}, {3,  5}},
        {{41161,  51315},  {-4, -5}},
        {{-40764, -20365}, {4,  2}},
        {{51448,  -51093}, {-5, 5}},
        {{-30521, 10349},  {3,  -1}},
        {{-20249, 51312},  {2,  -5}},
        {{-30513, 10354},  {3,  -1}},
        {{30945,  30830},  {-3, -3}},
        {{-9996,  30832},  {1,  -3}},
        {{10468,  -51085}, {-1, 5}},
        {{-30487, 10346},  {3,  -1}},
        {{51391,  10352},  {-5, -1}},
        {{10471,  41067},  {-1, -4}},
        {{-10033, 30830},  {1,  -3}},
        {{30932,  30835},  {-3, -3}},
        {{41199,  51308},  {-4, -5}},
        {{-40713, -10134}, {4,  1}},
        {{-10005, -51088}, {1,  5}},
        {{10475,  -20370}, {-1, 2}},
        {{10484,  41071},  {-1, -4}},
        {{10439,  -20367}, {-1, 2}},
        {{10448,  -51090}, {-1, 5}},
        {{-30529, 20591},  {3,  -2}},
        {{41188,  41068},  {-4, -4}},
        {{51419,  10349},  {-5, -1}},
        {{-20289, 10348},  {2,  -1}},
        {{-20265, -10134}, {2,  1}},
        {{30927,  30831},  {-3, -3}},
        {{41183,  -40849}, {-4, 4}},
        {{10487,  -10128}, {-1, 1}},
        {{-20236, -51086}, {2,  5}},
        {{30943,  -20371}, {-3, 2}},
        {{30948,  20589},  {-3, -2}},
        {{-10015, -30611}, {1,  3}},
        {{41208,  -20372}, {-4, 2}},
        {{51431,  -20372}, {-5, 2}},
        {{-10016, 41068},  {1,  -4}},
        {{41180,  -40852}, {-4, 4}},
        {{-20230, -10129}, {2,  1}},
        {{-40713, -51092}, {4,  5}},
        {{-40712, 41067},  {4,  -4}},
        {{51418,  20595},  {-5, -2}},
        {{41191,  30827},  {-4, -3}},
        {{-20233, -10133}, {2,  1}},
        {{51395,  10352},  {-5, -1}},
        {{41212,  -30609}, {-4, 3}},
        {{41167,  -51086}, {-4, 5}},
        {{-40737, 20595},  {4,  -2}},
        {{-10040, -10125}, {1,  1}},
        {{-40753, -10129}, {4,  1}},
        {{30927,  51310},  {-3, -5}},
        {{20676,  20589},  {-2, -2}},
        {{-30529, -10128}, {3,  1}},
        {{20729,  51310},  {-2, -5}},
        {{-20229, -40847}, {2,  4}},
        {{41196,  20587},  {-4, -2}},
        {{10468,  51314},  {-1, -5}},
        {{20676,  41067},  {-2, -4}},
        {{-9993,  30834},  {1,  -3}},
        {{-51004, 51307},  {5,  -5}},
        {{51410,  30835},  {-5, -3}},
        {{-30476, 41075},  {3,  -4}},
        {{-20281, 20590},  {2,  -2}},
        {{20727,  -40852}, {-2, 4}},
        {{-10001, -30609}, {1,  3}},
        {{20691,  30826},  {-2, -3}},
        {{-51001, 20587},  {5,  -2}},
        {{-51001, 51310},  {5,  -5}},
        {{-20252, -30612}, {2,  3}},
        {{-20257, -30610}, {2,  3}},
        {{20703,  -20370}, {-2, 2}},
        {{41207,  -51093}, {-4, 5}},
        {{-30481, 20593},  {3,  -2}},
        {{-30510, -30614}, {3,  3}},
        {{-10001, -20366}, {1,  2}},
        {{-30485, 20590},  {3,  -2}},
        {{10460,  -51094}, {-1, 5}},
        {{51410,  -40850}, {-5, 4}},
        {{-20236, 20589},  {2,  -2}},
        {{-20241, 20594},  {2,  -2}},
        {{-10044, -10132}, {1,  1}},
        {{-10048, 20586},  {1,  -2}},
        {{-20245, -10130}, {2,  1}},
        {{30951,  -10131}, {-3, 1}},
        {{-9993,  -40852}, {1,  4}},
        {{30971,  -30607}, {-3, 3}},
        {{51391,  20594},  {-5, -2}},
        {{-50951, -51091}, {5,  5}},
        {{-9993,  20593},  {1,  -2}},
        {{10480,  -10129}, {-1, 1}},
        {{41211,  51314},  {-4, -5}},
        {{30912,  -10134}, {-3, 1}},
        {{30944,  30828},  {-3, -3}},
        {{30915,  -51090}, {-3, 5}},
        {{-9999,  10351},  {1,  -1}},
        {{51395,  51312},  {-5, -5}},
        {{-40729, 20588},  {4,  -2}},
        {{-20229, -40846}, {2,  4}},
        {{-10033, 30833},  {1,  -3}},
        {{41168,  41066},  {-4, -4}},
        {{20703,  51306},  {-2, -5}},
        {{20732,  51309},  {-2, -5}},
        {{-10020, 10347},  {1,  -1}},
        {{-40716, -10130}, {4,  1}},
        {{41212,  10352},  {-4, -1}},
        {{10464,  -51093}, {-1, 5}},
        {{10434,  41066},  {-1, -4}},
        {{10451,  51315},  {-1, -5}},
        {{-40764, -10133}, {4,  1}},
        {{-10049, -10126}, {1,  1}},
        {{10463,  10347},  {-1, -1}},
        {{20732,  41075},  {-2, -4}},
        {{-30488, -10130}, {3,  1}},
        {{-10009, 10349},  {1,  -1}},
        {{-40744, -10134}, {4,  1}},
        {{20703,  41073},  {-2, -4}},
        {{41204,  -51092}, {-4, 5}},
        {{-50960, -51093}, {5,  5}},
        {{-40748, 20586},  {4,  -2}},
        {{51428,  20591},  {-5, -2}},
        {{-30489, 30831},  {3,  -3}},
        {{10472,  10350},  {-1, -1}},
        {{41199,  -20371}, {-4, 2}},
        {{-30489, 41069},  {3,  -4}},
        {{-20241, 10352},  {2,  -1}},
        {{41188,  -51090}, {-4, 5}},
        {{-10004, -40845}, {1,  4}},
        {{-30497, -51088}, {3,  5}},
        {{30943,  20591},  {-3, -2}},
        {{-50956, -10129}, {5,  1}},
        {{41186,  -20369}, {-4, 2}},
        {{30948,  41066},  {-3, -4}},
        {{30919,  51309},  {-3, -5}},
        {{10451,  10355},  {-1, -1}},
        {{10475,  20586},  {-1, -2}},
        {{30959,  20588},  {-3, -2}},
        {{41187,  -51087}, {-4, 5}},
        {{30956,  51309},  {-3, -5}},
        {{-30497, 41075},  {3,  -4}},
        {{51396,  51309},  {-5, -5}},
        {{30962,  -51094}, {-3, 5}},
        {{30967,  -51091}, {-3, 5}},
        {{10487,  20587},  {-1, -2}},
        {{-40732, 30826},  {4,  -3}},
        {{-50985, 10354},  {5,  -1}},
        {{-40753, -40850}, {4,  4}},
        {{10476,  -51092}, {-1, 5}},
        {{-50966, 10350},  {5,  -1}},
        {{30930,  51306},  {-3, -5}},
};

decltype(input_real) input_test{
        {{9,  1},  {0,  2}},
        {{7,  0},  {-1, 0}},
        {{3,  -2}, {-1, 1}},
        {{6,  10}, {-2, -1}},
        {{2,  -4}, {2,  2}},
        {{-6, 10}, {2,  -2}},
        {{1,  8},  {1,  -1}},
        {{1,  7},  {1,  0}},
        {{-3, 11}, {1,  -2}},
        {{7,  6},  {-1, -1}},
        {{-2, 3},  {1,  0}},
        {{-4, 3},  {2,  0}},
        {{10, -3}, {-1, 1}},
        {{5,  11}, {1,  -2}},
        {{4,  7},  {0,  -1}},
        {{8,  -2}, {0,  1}},
        {{15, 0},  {-2, 0}},
        {{1,  6},  {1,  0}},
        {{8,  9},  {0,  -1}},
        {{3,  3},  {-1, 1}},
        {{0,  5},  {0,  -1}},
        {{-2, 2},  {2,  0}},
        {{5,  -2}, {1,  2}},
        {{1,  4},  {2,  1}},
        {{-2, 7},  {2,  -2}},
        {{3,  6},  {-1, -1}},
        {{5,  0},  {1,  0}},
        {{-6, 0},  {2,  0}},
        {{5,  9},  {1,  -2}},
        {{14, 7},  {-2, 0}},
        {{-3, 6},  {2,  -1}},
};
//    auto &input = input_test;
auto &input = input_real;
}

int main10() {
    for (ll time = 0; time < INT64_MAX; ++time) {
        std::set < Point > points;
        bool all_positive = true;
        Point min_point{INT64_MAX, INT64_MAX};
        Point max_point{INT64_MIN, INT64_MIN};
        for (const auto &[point, velocity]: input) {
            const Point new_point{point.x + time * velocity.x, point.y + time * velocity.y};
            points.insert(new_point);

            min_point.x = std::min(min_point.x, new_point.x);
            min_point.y = std::min(min_point.y, new_point.y);

            max_point.x = std::max(max_point.x, new_point.x);
            max_point.y = std::max(max_point.y, new_point.y);

            all_positive &= (new_point.x >= 0);
            all_positive &= (new_point.y >= 0);

            if (!all_positive) break;
        }

        if (!all_positive) {
            continue;
        }

        // heuristic checking that at least one fully filled vertical line exists
        for (ll check_x = min_point.x; check_x <= max_point.x; check_x++) {
            bool column_found = true;
            for (ll check_y = min_point.y; check_y <= max_point.y; check_y++) {
                column_found &= points.contains({check_x, check_y});
            }

            if (column_found) {
                myprint(time);
                for (ll y = min_point.y; y <= max_point.y; y++) {
                    for (ll x = min_point.x; x <= max_point.x; x++) {
                        if (points.contains({x, y})) {
                            std::cout << '#';
                        } else {
                            std::cout << ' ';
                        }
                    }
                    std::cout << std::endl;
                }

                return 0;
            }
        }
    }

    return 0;
}
