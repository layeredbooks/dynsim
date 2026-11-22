```
    void add_input(std::string name, ValueType init_value) {
        add_signal(SignalType::Input, name, init_value);
    }

    void write_input(std::string name, ValueType value) {
        write_signal(SignalType::Input, name, value);
    }

    ValueType read_input(std::string name) {
        return read_signal(SignalType::Input, name);
    }
```
