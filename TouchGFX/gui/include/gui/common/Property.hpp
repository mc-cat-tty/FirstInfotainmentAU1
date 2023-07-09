#ifndef GUI_COMMON_PROPERTY_HPP
#define GUI_COMMON_PROPERTY_HPP

// Property forward declaration
template <typename T>
class Property;

// Value changed callback
template <typename T>
using PropertyValueChangedCallback = void (*)(Property<T>*);

// Property definition
template <typename T>
class Property {
protected:
  T value;
  PropertyValueChangedCallback<T> valueChangedCallback;

public:
  Property(T defaultValue, PropertyValueChangedCallback<T> valueChangedCallback) {
    this->value = defaultValue;
    this->valueChangedCallback = valueChangedCallback;
  }

  T getValue() { return value; }

  void setValue(T newValue) {
    if (value != newValue) {
      value = newValue;

      if (valueChangedCallback)
        valueChangedCallback(this);
    }
  }
};

#endif