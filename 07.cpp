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

    const std::vector<std::tuple<char, char>> input_real{
            {'F', 'Q'},
            {'A', 'K'},
            {'K', 'R'},
            {'D', 'X'},
            {'L', 'T'},
            {'V', 'W'},
            {'J', 'N'},
            {'B', 'W'},
            {'X', 'C'},
            {'W', 'I'},
            {'Q', 'P'},
            {'E', 'M'},
            {'C', 'N'},
            {'U', 'O'},
            {'O', 'R'},
            {'N', 'Z'},
            {'R', 'I'},
            {'G', 'H'},
            {'T', 'H'},
            {'M', 'P'},
            {'Y', 'I'},
            {'S', 'Z'},
            {'I', 'H'},
            {'H', 'P'},
            {'P', 'Z'},
            {'Y', 'P'},
            {'A', 'O'},
            {'V', 'O'},
            {'G', 'Y'},
            {'K', 'B'},
            {'I', 'P'},
            {'D', 'L'},
            {'A', 'P'},
            {'O', 'T'},
            {'F', 'C'},
            {'M', 'S'},
            {'V', 'Q'},
            {'G', 'I'},
            {'O', 'I'},
            {'N', 'I'},
            {'E', 'O'},
            {'N', 'S'},
            {'J', 'H'},
            {'C', 'P'},
            {'E', 'N'},
            {'T', 'P'},
            {'A', 'G'},
            {'A', 'V'},
            {'C', 'H'},
            {'A', 'Y'},
            {'E', 'U'},
            {'T', 'Y'},
            {'Q', 'S'},
            {'Y', 'S'},
            {'E', 'P'},
            {'N', 'T'},
            {'T', 'M'},
            {'Q', 'M'},
            {'H', 'Z'},
            {'D', 'Y'},
            {'J', 'R'},
            {'U', 'R'},
            {'K', 'N'},
            {'A', 'W'},
            {'A', 'H'},
            {'X', 'G'},
            {'V', 'J'},
            {'W', 'C'},
            {'I', 'Z'},
            {'V', 'H'},
            {'R', 'H'},
            {'U', 'N'},
            {'O', 'Z'},
            {'X', 'S'},
            {'E', 'G'},
            {'W', 'U'},
            {'U', 'G'},
            {'D', 'Z'},
            {'E', 'R'},
            {'L', 'B'},
            {'B', 'R'},
            {'G', 'T'},
            {'F', 'K'},
            {'R', 'S'},
            {'J', 'Z'},
            {'Q', 'U'},
            {'X', 'O'},
            {'F', 'I'},
            {'W', 'R'},
            {'W', 'Y'},
            {'M', 'Y'},
            {'S', 'I'},
            {'F', 'O'},
            {'C', 'Y'},
            {'N', 'G'},
            {'O', 'S'},
            {'Q', 'O'},
            {'K', 'T'},
            {'X', 'Z'},
            {'L', 'N'},
            {'S', 'P'},
    };

    decltype(input_real) input_test;
//    auto &input = input_test;
    auto &input = input_real;

    struct Node {
        char name = 0;
        std::set<char> parents;
        std::set<char> children;
    };

    struct NodeTask {
        Node node;
        ll remaining_time;
    };

    bool visited_all_parents(const std::vector<char> &path, const std::set<char> &parents) {
        for (auto parent: parents) {
            if (auto parent_it = std::find(path.begin(), path.end(), parent); parent_it == path.end()) {
                return false;
            }
        }
        return true;
    }

    void
    traverse_1(const std::map<char, Node> &all_nodes, std::vector<char> &path, std::map<char, Node> &available_nodes) {
        if (available_nodes.empty()) {
            return;
        }
        for (auto it = available_nodes.begin(); it != available_nodes.end();) {
            if (visited_all_parents(path, it->second.parents)) {
                Node current_node = it->second;
                it = available_nodes.erase(it);
                path.push_back(current_node.name);
                for (auto child: current_node.children) {
                    available_nodes.insert({child, all_nodes.at(child)});
                }
                break;
            } else {
                ++it;
            }
        }
        traverse_1(all_nodes, path, available_nodes);
    }

    void iterate_2(const std::map<char, Node> &all_nodes, std::vector<char> &path, std::vector<NodeTask> &work_pool,
                   std::map<char, Node> &available_nodes, ll &counter) {
        ++counter;
        for (auto it = available_nodes.begin(); it != available_nodes.end() && work_pool.size() < 5;) {
            if (visited_all_parents(path, it->second.parents)) {
                if (work_pool.size() < 5) {
                    work_pool.push_back({it->second, 61 + it->second.name - 'A'});
                    it = available_nodes.erase(it);
                    continue;
                }
            }
            ++it;
        }

        for (auto it = work_pool.begin(); it != work_pool.end();) {
            if ((--it->remaining_time) == 0) {

                path.push_back(it->node.name);
                for (auto child: it->node.children) {
                    available_nodes.insert({child, all_nodes.at(child)});
                }

                it = work_pool.erase(it);
            } else {
                ++it;
            }
        }
    }

    std::string solve_1(const std::map<char, Node> &all_nodes, std::map<char, Node> available_nodes) {
        std::vector<char> path;
        traverse_1(all_nodes, path, available_nodes);

        std::string result;
        for (auto p: path) {
            result.push_back(p);
        }
        return result;
    }

    ll solve_2(const std::map<char, Node> &all_nodes, std::map<char, Node> available_nodes) {
        std::vector<char> path;
        std::vector<NodeTask> work_pool;
        ll counter = 0;
        do {
            iterate_2(all_nodes, path, work_pool, available_nodes, counter);
        } while (!work_pool.empty() || !available_nodes.empty());

        return counter;
    }
}

int main07() {

    std::map<char, Node> map;
    std::set<char> unique_points;

    for (auto [from, to]: input) {
        Node &from_node = map[from];
        Node &to_node = map[to];

        if (!from_node.name) {
            from_node.name = from;
        }

        if (!to_node.name) {
            to_node.name = to;
        }

        from_node.children.insert(to);
        to_node.parents.insert(from);

        unique_points.insert(from);
        unique_points.insert(to);
    }

    std::map<char, Node> available_nodes;

    for (auto &[key, node]: map) {
        if (node.parents.empty()) {
            available_nodes.insert({key, node});
        }
    }

    auto result1 = solve_1(map, available_nodes);
    myprint(result1);
    assert(result1 == "ADEFKLBVJQWUXCNGORTMYSIHPZ");

    auto result2 = solve_2(map, available_nodes);
    myprint(result2);
    assert(result2 == 1120);

    return 0;
}
