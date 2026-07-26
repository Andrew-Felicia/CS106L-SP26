/* File: bounded_value.cpp
 * Author: Preston Seay
 *
 * This file implements the BoundedValue template class.
 * 
 * Somtimes, this implementation of the template would
 * be called a .tpp file, since it's somewhat special
 * as it's included at the bottom of the .h.
 */

#include "bounded_value.h"
#include <string>
#include <iostream>

// TODO: Constructor
template <typename T>
BoundedValue<T>::BoundedValue(T value, T minValue, T maxValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    if (value > maxValue) {
        this->value = maxValue;
    } else if (value < minValue) {
        this->value = minValue;
    } else {
        this->value = value;
    }
}

// TODO: Return stored value
template <typename T>
T BoundedValue<T>::get() const {
    return this->value;
}

// TODO: Set value and enforce bounds
template <typename T>
void BoundedValue<T>::set(T newValue) {
    if (newValue < this->minValue) {
        this->value = this->minValue;
    } else if (newValue > this->maxValue) {
        this->value = this->maxValue;
    } else {
        this->value = newValue;
    }
}

// TODO: Return minimum bound
template <typename T>
T BoundedValue<T>::getMin() const {
    return this->minValue;
}

// TODO: Return maximum bound
template <typename T>
T BoundedValue<T>::getMax() const {
    return this->maxValue;
}

// OPTIONAL TODO:
template <typename T>
void BoundedValue<T>::adjust(T delta) {
    if (this->value + delta < this->minValue) {
        this->value = this->minValue;
    } else if (this->value + delta > this->maxValue) {
        this->value = this->maxValue;
    }else {
        this->value = this->value + delta;
    }
}


template <typename T>
void BoundedValue<T>::printAllValue() {
    std::cout<< "Value: " << this->value << '\n';
    std::cout<< "minValue: " << this->minValue << '\n';
    std::cout<< "maxValue: " << this->maxValue << '\n';
}
