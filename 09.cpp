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
#include <iomanip>

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
    // 412 players; last marble is worth 71646 points
    ll PLAYERS = 412;
    ll MAX_MARBLE = 71646;

    struct Node {
        ll value = INT64_MAX;
        Node *prev = nullptr;
        Node *next = nullptr;
    };


    ll calculate(ll players, ll max_marble) {
        std::vector<Node> arena;
        arena.reserve(max_marble + 1);
        Node &root = arena.emplace_back();
        root.value = 0;
        root.next = &root;
        root.prev = &root;

        std::vector<ll> score(players);
        ll current_player = -1;

        Node *current_node = &root;

        for (ll value = 1; value <= max_marble; value++) {
            current_player = (current_player + 1) % players;
            if (value % 23 != 0) {
                Node *insert_after = current_node->next;
                Node *insert_before = current_node->next->next;

                Node *new_node = &arena.emplace_back();

                new_node->value = value;
                new_node->prev = insert_after;
                new_node->next = insert_before;

                insert_after->next = new_node;
                insert_before->prev = new_node;
                current_node = new_node;
            } else {
                score.at(current_player) += value;
                Node *node_to_remove = current_node->prev->prev->prev->prev->prev->prev->prev;
                score.at(current_player) += node_to_remove->value;
                current_node = node_to_remove->next;

                Node *node_before_node_to_remove = node_to_remove->prev;
                node_before_node_to_remove->next = current_node;
                current_node->prev = node_before_node_to_remove;

                node_to_remove->prev = nullptr;
                node_to_remove->next = nullptr;
            }
        }
        return *std::max_element(score.begin(), score.end());
    }
}

int main09() {
    ASSERT_EQ(calculate(9, 25), 32);
    ASSERT_EQ(calculate(10, 1618), 8317);
    ASSERT_EQ(calculate(13, 7999), 146373);
    ASSERT_EQ(calculate(17, 1104), 2764);
    ASSERT_EQ(calculate(21, 6111), 54718);
    ASSERT_EQ(calculate(30, 5807), 37305);
    ASSERT_EQ(calculate(PLAYERS, MAX_MARBLE), 439635);
    ASSERT_EQ(calculate(PLAYERS, MAX_MARBLE * 100), 3562722971);
    return 0;
}
