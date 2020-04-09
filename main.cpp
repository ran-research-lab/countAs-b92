// Rafael A. Arce Nazario
//
// Cliente con pruebas para la clase Racional

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
using namespace std;

int countAs(const string &st) {
    if (st.length() == 0) return 0;

    if (st.length() == 1) {
        if (st == "a") return 1;
        else           return 0;
    }

    int mid = st.length() / 2;
    return countAs(st.substr(0,mid)) +  countAs(st.substr(mid));
}

int countAsMejor(const string &st, int low, int high) {
    if (low > high) return 0;

    if (low == high) return st[low] == 'a';

    int mid = (low + high) / 2;
    return countAsMejor(st, low, mid) +  countAsMejor(st, mid+1,high);
}

TEST_CASE("countAs", "[countAs]") {
    CHECK(countAs("aaa") == 3);
    CHECK(countAs("") == 0);
    CHECK(countAs("abacos") == 2);
    CHECK(countAs("caballas") == 3);
}

TEST_CASE("countAsMejor", "[countAsMejor]") {
    CHECK(countAsMejor("aaa",0,2) == 3);
    CHECK(countAsMejor("abacos",0,5) == 2);
    CHECK(countAsMejor("caballas",0,7) == 3);
}