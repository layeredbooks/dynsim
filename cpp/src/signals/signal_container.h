#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <utility>

enum class SignalType : size_t {
    Input,
    Output,
    State,
    Parameter,
    AuxVar,
    COUNT
};


template <typename ValueType>
class SignalContainer {

  private:
  
    static constexpr size_t NUM_TYPES = static_cast<size_t>(SignalType::COUNT);

    std::array<std::vector<ValueType>, NUM_TYPES> signal_values_;

    std::array<std::unordered_map<std::string, size_t>, NUM_TYPES> signal_indices_;

    // std::string _name_sep = ":";

    // std::unordered_map<std::string, std::string> _connections;

    // std::unordered_map<std::string, std::vector<double>> saved_signal_values;

public:
    SignalContainer() {
    }

    void add_signal(SignalType signal_type, std::string signal_name, ValueType init_value) {
        const auto type_index = std::to_underlying(signal_type);
        const auto signal_index = signal_values_[type_index].size();
        signal_values_[type_index].push_back(init_value);
        signal_indices_[type_index][signal_name] = signal_index;
    }

    void write_signal(SignalType signal_type, std::string signal_name, ValueType value){
        const auto type_index = std::to_underlying(signal_type);
        const auto signal_index = signal_indices_[type_index].at(signal_name);
        signal_values_[type_index][signal_index] = value;
    }

    ValueType read_signal(SignalType signal_type, std::string signal_name){
        const auto type_index = std::to_underlying(signal_type);
        const auto signal_index = signal_indices_[type_index].at(signal_name);
        auto signal_value = signal_values_[type_index][signal_index];
        return signal_value;
    }
};