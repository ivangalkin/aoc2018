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
            "ubkfmdjxyzlbgkrotcepvswaqx",
            "uikfmdkuyzlbgerotcepvswaqh",
            "uikfmdpxyzlbgnrotcepvswoeh",
            "nikfmdjxyzlbgnrotqepvswyqh",
            "qgkfmdjxyzlbgnmotcepvswaqh",
            "uikfmdjxyzqbgnrytcepvsbaqh",
            "uikfmdjxyzibgprotcecvswaqh",
            "uikfmajxyzlcgnrojcepvswaqh",
            "uvkfsdjxyzlbgnrotcepvjwaqh",
            "uikfmdjxfzlbggrotcepvswawh",
            "uikfmhjxyzlbgnuotcepvjwaqh",
            "uikfmdjxyzlbuzcotcepvswaqh",
            "uikfmdwxyzlbgnrotcepvfwamh",
            "uikfmdexyzlbgnroecepvswhqh",
            "uikfmdjuyzlbgnrotcqpvswafh",
            "uikfddjxyzvbgnrotceppswaqh",
            "yikfwdjxyzlbgnrotcepvswagh",
            "uiktmdjxyzlbgnrotceposwajh",
            "uikfmdsxyzlbgnroteetvswaqh",
            "uikfpdjxyzlbgnroncepvswuqh",
            "uikfmtjxyzlbgurotcepvswaoh",
            "eikfmdjxyjlbgnrotcepyswaqh",
            "uikfkdjxyzlbgnrotcepvszaqv",
            "uikfrdjxtwlbgnrotcepvswaqh",
            "uikfmdjxyzlbgnrotpepwswahh",
            "kikfmdjxyzlbgnkotcepvswqqh",
            "uikfkduxyzlbgnrotcepvswafh",
            "uikfxhjxyzlbgnrotcegvswaqh",
            "uikfmdjxyzlmgnrotcenvawaqh",
            "uzkfmddxyzlbgnrltcepvswaqh",
            "uikfmdjxyzlbgnrobcepisqaqh",
            "uijfmdjxyzlbgnrotcexvrwaqh",
            "uiwjmdjxyzlbgnrotceprswaqh",
            "uhkqmdjxwzlbgnrotcepvswaqh",
            "uiktmsjxyzwbgnrotcepvswaqh",
            "uikfmdjxyztbgnqotcepvswcqh",
            "uibfmdjxyzlbgnroqcepvswaqx",
            "uwkfmdjxyxlbgnrotcfpvswaqh",
            "uikumdjxyzlbgnrstceposwaqh",
            "uikfzdjxyznhgnrotcepvswaqh",
            "uikuydjxyzlbgnrotqepvswaqh",
            "uikfmdqxyzlbgnrotfefvswaqh",
            "yikfmdjxyzlbrnrqtcepvswaqh",
            "uiifmdjxyzlbenrotcfpvswaqh",
            "uxkjmdjxyzlbgnrotcmpvswaqh",
            "uikgmdjxyzlbgnrotceovlwaqh",
            "uikfmdjxyzvbgzrotcenvswaqh",
            "uiufmdjxyzlbgnrotceposwazh",
            "uiafmdjxyzlignmotcepvswaqh",
            "uikfmdjxyzwbgnsotlepvswaqh",
            "uikjmdjvyzlbgnrotcenvswaqh",
            "uikfmdjxyzlbonroteepvswaqi",
            "uikfmdjxyzldgnroxcepviwaqh",
            "uikvmdjxyzlbgdrotrepvswaqh",
            "uikfmdjyyzwbgnrotcepvzwaqh",
            "uikfmdjxyzzbnnvotcepvswaqh",
            "uikomdjxyzlbgnrotcepvuwhqh",
            "uikfmmjxyzbbgnrotcepvswayh",
            "uikfmdjfezlbgprotcepvswaqh",
            "uzkfmojxmzlbgnrotcepvswaqh",
            "uipfmdjxyzlbgnrotceyuswaqh",
            "uikfmdjxyzlkgnmotcepvswadh",
            "uikfmdjxyzlbgnuctcbpvswaqh",
            "uikfqdjxyzlbogrotcepvswaqh",
            "uikfmdjxyzlfynrotcepvswash",
            "uikfmdjxizzmgnrotcepvswaqh",
            "uhkfmdjxyzlbhnrotcenvswaqh",
            "uipfmdjxyzlbgorotcepfswaqh",
            "uikfmdjxyznbgnrotcepvswfah",
            "uikfmujxyzlbgnrotnepvssaqh",
            "uikfmdjxyzlxgnrotcepvsrwqh",
            "uikfmdjxszlbgnrottvpvswaqh",
            "umkfmdskyzlbgnrotcepvswaqh",
            "uikfmdjxyzlbgorotcwpzswaqh",
            "uikfmdhxyzzbgnzotcepvswaqh",
            "jikfmdjxyzlbgnrotcepveyaqh",
            "uirfmdlxyzlbgnjotcepvswaqh",
            "uikfmdjxyzlbgnrorxepvswazh",
            "uikfmdjxyzltgnrotcepvsxaqi",
            "uikfmdjxyzlbxlrotcepkswaqh",
            "uvkfmdjxyzlbgnrotcopvswxqh",
            "uxkfmdjxkzlbgnrotcepvswqqh",
            "uikfmdjxyzlbqnrotcepvhwrqh",
            "uikfmdjxyzlvgnrolcepvswrqh",
            "urkfmdixyzlbgnrotcepvsjaqh",
            "uikfmdjxymlbsnrotcepvswcqh",
            "uikfmdjxyilbgnrotcepvcwzqh",
            "uikfadjxlzlbgnrotcepvswaql",
            "uikfmdjxuzlbgdrotcgpvswaqh",
            "yikfmdgxyzlbgnrotcepvswarh",
            "uikfmdjxyzlbgorotcepcswaqv",
            "uikkmdjxyzlbvnrotcepvvwaqh",
            "uwzfmdjxyxlbgnrotcfpvswaqh",
            "uikfmdjxyztbgnrotcrtvswaqh",
            "uiufmdjxyzhbgnrotcupvswaqh",
            "uikfzdjcyzlbgnrotcfpvswaqh",
            "uipfmdjxyzlbgnrotavpvswaqh",
            "uikfmajxyzlbgnrotcepbsxaqh",
            "uikfmdjfyzlbgnrotbepvswmqh",
            "gikkmdjxyzlbgnrptcepvswaqh",
            "uikfmdjxqvlbgnrotsepvswaqh",
            "fikfmdjxyzlbgnrotcegvswoqh",
            "idkfmdjxyzlbgnrotcepwswaqh",
            "uikfmdqxyzlbmnrobcepvswaqh",
            "uikfmdjxyzpbgnroicepvsyaqh",
            "uikfmkoxyzlbgnrotcgpvswaqh",
            "unkfmdjxyzlbpnrolcepvswaqh",
            "uikfmdjmyzlbgfrotcupvswaqh",
            "ujkfmdjxynlbgnroteepvswaqh",
            "uikfmljxyzlbgnaotcepvsiaqh",
            "uikfmdjdyzlbgnrotcepvtwaqd",
            "uikfmdjxyzlbgnyotcepimwaqh",
            "uikfmdjxyzfbjnrotcepvxwaqh",
            "eiwfmdjxyzlbgnrdtcepvswaqh",
            "umkhmdjxyzlbgnrotceivswaqh",
            "uikfmdjxyzlbgnrotcwpvswneh",
            "uckfmdjxyzlbknrotcepvswauh",
            "uiofmdjoyzlbgnrbtcepvswaqh",
            "uikfmdbxyzlbgnrotcepaslaqh",
            "uimfmdjxyalbgnrotcepvswaxh",
            "uqkfmdjxyzlbwnrotcepmswaqh",
            "uiyfmdjxyzlbgnrotcepvswxuh",
            "uikfmdjxyzlbgmrotgepvswamh",
            "uikfmdjxyqlbgarozcepvswaqh",
            "uikfmdjxyzabanpotcepvswaqh",
            "uikfmdjgyzlbsnrotcepvswaqj",
            "uikfmdjxyzlbwnrottepvsvaqh",
            "uikfmdjxyzlbbnrotcepvofaqh",
            "uikfudjxyzlbgnustcepvswaqh",
            "cskfmqjxyzlbgnrotcepvswaqh",
            "uiwfmddxyzlbgnrotccpvswaqh",
            "eikpmdjxyzlbgnrotcesvswaqh",
            "uikfmdzxyzlngnrrtcepvswaqh",
            "uikfmdjxyzlbgnrotcepaswtph",
            "uirfmdjxyzlbgnrotcepvswsqe",
            "uikjmdjxqzlbgirotcepvswaqh",
            "uikfmdjxsllbknrotcepvswaqh",
            "uikfmdjxyqlbgcrotcepvswaqu",
            "uikfmdjsymlbgnrotcebvswaqh",
            "uikfmdjxezlbgnroccepviwaqh",
            "uikfmdjiyzjbgnrotcepvswarh",
            "uqkfmdjxyzmbgnrotcepvslaqh",
            "unkfmdjxyzlbinrotceplswaqh",
            "uikfmdjxyzpbgnrjtcedvswaqh",
            "uicfmdjxyzlbgrrotcepvswamh",
            "ukknmdjxyzlbgnqotcepvswaqh",
            "uikfudjxyzlbdnrztcepvswaqh",
            "uikfmdjxyzlbgnrozcepvswawk",
            "uikfmduxyzsbgnrotcepvswauh",
            "uikfmdjxyzljbnrotcenvswaqh",
            "uukfmdjxyzlbgnrotcckvswaqh",
            "uilfldjxyzlbgnrotcdpvswaqh",
            "uckfmdjxyvybgnrotcepvswaqh",
            "qikfmdjxyglbgnrotcepvrwaqh",
            "uikfmhjxyzltgnrotcepvswbqh",
            "uikfmdjxipabgnrotcepvswaqh",
            "uikfmdjxyzlbgnrotceovswanl",
            "uikfmdjxyzlbgirotcapvswahh",
            "uikfucjxyflbgnrotcepvswaqh",
            "pikfmdjxyzpbgnrotcepvswaeh",
            "uikfmdjiyylbgnrotcervswaqh",
            "uikfmdjgyzlbgnrotcaevswaqh",
            "uikvmdjxyzlbunrotcepvswarh",
            "uikfadjuyzpbgnrotcepvswaqh",
            "uikfmdjxyzlbgnrotcepsawaqj",
            "eikfmdjxyflbgnrotcepvswaeh",
            "uisfmdaxyzlbgnrotcepvswlqh",
            "vikfmdjxyzlzgnrotcepvswanh",
            "ukkfmdoxyzlbgnrotcewvswaqh",
            "uikfmdhxyzlbgnrotcrpvbwaqh",
            "uhkfmdjwezlbgnrotcepvswaqh",
            "uikfddjxyzlbgnroteepvpwaqh",
            "uikfmdjxczlbgncotiepvswaqh",
            "uikfvdjxyzlbgnrotcnpvsaaqh",
            "uikfmdjxyzlbgnritcepvlwmqh",
            "uikfmdjxczlcgnrotcecvswaqh",
            "mikfmdjxyzlbgnrotcepvswasi",
            "uifvmdjxyzlbgnrotpepvswaqh",
            "uikzmdjxyzlbgnrotrepvswaqs",
            "uikfmqjqyzlbunrotcepvswaqh",
            "uikfpdyxyzlbgnrotcepvswagh",
            "uikfmdjxyzobgnrotrlpvswaqh",
            "zisdmdjxyzlbgnrotcepvswaqh",
            "uikfmdjxyzlbgnlotiesvswaqh",
            "uikfddixyzlbgnroucepvswaqh",
            "uijfmdrxyzlbgnrotoepvswaqh",
            "uikfmdcxbzlbgnrotcepvpwaqh",
            "uikfmdjxxzlbfnrotcecvswaqh",
            "upkfmdjxyzmtgnrotcepvswaqh",
            "uikfmdrxyzlbgnrjtcepvswaqp",
            "uizfmdjxyzlbsnrotcepviwaqh",
            "uidfmdjxyslbgnrotcxpvswaqh",
            "uikfmdjxyzlbgnrovyepvsdaqh",
            "uiafmdjxyzlbgnrxtcepvsdaqh",
            "ugkfmdjxyzlbgnrodcepvswawh",
            "pikfmtjxyzhbgnrotcepvswaqh",
            "uikfmdjxyzlfgnvotcepvswtqh",
            "uikbmdjxyzlbgerotcepvswaqm",
            "uikfmdjxyhlbdnrotcepvswaqy",
            "uikfgdjxyzlbgnhotcepvswdqh",
            "uikfmdpxyzlbgnrotcepvscanh",
            "uikfmdjxyzsbgnretcepvswaqn",
            "uikfddjxyzlrgnrotcepvsbaqh",
            "uikfmdjxyzlbgnrotcqnrswaqh",
            "uhkfmejxyzlbgnrotvepvswaqh",
            "uikimdjxyzlngnrotceprswaqh",
            "uikfmdjxyzwbunrotiepvswaqh",
            "rikfmdjxyzlbgnrotcypvssaqh",
            "uikfmdjxyzlbdnrotcrpvswsqh",
            "uekfmdjxkzlbznrotcepvswaqh",
            "uikfmdjxyglbgvrotcepvswaqv",
            "uikfmcjxyzlbgnrotmeovswaqh",
            "uikfmdjxyznbgnrozcepvswaqm",
            "uikfmdjxyzlbdnrotcepdsyaqh",
            "umkfmdjxfzlbgnrotiepvswaqh",
            "uitfmdjxyzvbcnrotcepvswaqh",
            "uikfmdjqyzlbgnrvtcepvlwaqh",
            "uikfmdjxyzkbworotcepvswaqh",
            "uikfmdzxyzlbwnrotcypvswaqh",
            "uikfmdjxyklbgnrftyepvswaqh",
            "uinfmsjxyzlbgnrotcepsswaqh",
            "xisfmdjxymlbgnrotcepvswaqh",
            "uikfmdjxjzlbgnropcepvswaqv",
            "uikfmdjxyalegyrotcepvswaqh",
            "uikfydjxyzlbgnrotcekvswtqh",
            "uikwmojxyzlbgnromcepvswaqh",
            "uikdmdjayzlbgnrotcepvswzqh",
            "uikfmdjxyzlmvnrotctpvswaqh",
            "uikfmbjxyzlbgnrotceptsweqh",
            "yvkfmdjxyzlbgqrotcepvswaqh",
            "uikomdjxfxlbgnrotcepvswaqh",
            "uikfmdjxczlbgnroocepgswaqh",
            "uikemdjxizlbgnrotcegvswaqh",
            "uikdmdjxyzlbgwrotceprswaqh",
            "tiyfmdjfyzlbgnrotcepvswaqh",
            "tmkfmdjxyzlbgirotcepvswaqh",
            "uikfmdjxyzebgnzotcepqswaqh",
            "uikfmljxyzlbgnrwtcepvswaeh",
            "uikfmojxyzlbgnrotcepbswwqh",
            "uikfmdjxyzlbgsrotcewvswwqh",
            "uikfmdjhyzlbgdrogcepvswaqh",
            "uikfmvjxyzlbrnrltcepvswaqh",
            "jikfmdjxyzlbgnrotcepvgcaqh",
            "uikhtdjxyzlbgnrotcepvswarh",
            "uikfmdjxyezbgnritcepvswaqh",
            "uikfwdjxyzlbgnrotzepvsnaqh",
            "uikfmdjxqylbgnrobcepvswaqh",
            "zikzmdjxyzlbgnrhtcepvswaqh",
            "uiksmzjxyzlbgnrftcepvswaqh",
            "uikfmdjxuzlbgnrotcepvsvaqc",

    };

    decltype(input_real) input_test;
//    auto &input = input_test;
    auto &input = input_real;

    ll calculate_diff(const std::string &lhs, const std::string &rhs) {
        assert(lhs.size() == rhs.size());
        ll diff = 0;
        for (ll i = 0; i < lhs.size(); ++i) {
            if (lhs.at(i) != rhs.at(i)) {
                ++diff;
            }
        }
        return diff;
    }
}

int main02() {
    {
        int64_t result0 = 0;
        ll total_two = 0;
        ll total_three = 0;
        for (const auto &i: input_real) {
            std::map<char, ll> appearances;
            for (auto c: i) {
                appearances[c]++;
            }
            ll two = 0;
            ll three = 0;
            for (auto [key, value]: appearances) {
                if (value == 2) {
                    two = std::max<ll>(two++, 1);
                } else if (value == 3) {
                    three = std::max<ll>(three++, 1);
                }
            }
            total_two += two;
            total_three += three;
        }
        result0 = total_two * total_three;
        myprint(result0);
    }


    {
        int64_t result1 = 0;
        for (ll i = 0; i < input_real.size() - 1; ++i) {
            for (ll j = i + 1; j < input_real.size(); j++) {
                auto diff = calculate_diff(input_real.at(i), input_real.at(j));
                if (diff == 1) {
                    myprint(input_real.at(i));
                    myprint(input_real.at(j));
                }
            }
        }
        myprint(result1);
    }
    return 0;
}
