#pragma once


class HashEntidad {
private:
    int key;
    string value;

public:
    HashEntidad() {}
    HashEntidad(int key, string value) {
        this->key = key;
        this->value = value;
    }
    int getKey() {
        return key;
    }
    string getValue() {
        return value;
    }
};
