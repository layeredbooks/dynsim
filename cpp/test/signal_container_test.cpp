#include <doctest/doctest.h>
#include <stdexcept>

#include<signals/signal_container.h>

TEST_CASE("Create") {
    auto sc_double = SignalContainer<double>{};
    auto sc_bool = SignalContainer<bool>{};
}

TEST_CASE("Signal creation") {
    auto sc = SignalContainer<double>{};
    constexpr auto signal_name = "Controller:sig";
    for (size_t i = 0; i < static_cast<size_t>(SignalType::COUNT); ++i) {
        auto signal_type = static_cast<SignalType>(i);
        CAPTURE(i);
        double expected = 3.14;
        sc.add_signal(signal_type, signal_name, expected);
        auto res = sc.read_signal(signal_type, signal_name);
        CHECK(doctest::Approx(res) == expected);
        CHECK_THROWS_AS(sc.read_signal(signal_type, "Process:sig"), const std::out_of_range&);    
    }
}

TEST_CASE("Signal access") {
    auto sc = SignalContainer<double>{};
    constexpr auto signal_name = "Controller:sig";
    for (size_t i = 0; i < static_cast<size_t>(SignalType::COUNT); ++i) {
        auto signal_type = static_cast<SignalType>(i);
        sc.add_signal(signal_type, signal_name, -1);
        double expected = 2.718;
        sc.write_signal(signal_type, signal_name, expected);
        auto res = sc.read_signal(signal_type, signal_name);
        CHECK(doctest::Approx(res) == expected);
        CHECK_THROWS_AS(sc.read_signal(signal_type, "Process:sig"), const std::out_of_range&);    
    }
}