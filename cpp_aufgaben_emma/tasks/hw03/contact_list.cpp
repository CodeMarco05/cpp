#include "contact_list.h"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>

// TODO create implementation here!
namespace contact_list {

bool add(storage &contacts, std::string_view name, number_t number) {
  contacts.names.push_back(std::string(name));
  contacts.numbers.push_back(number);
  return true;
}

size_t size(const storage &contacts) {
  int sizeNames = contacts.names.size();
  int sizeNumbers = contacts.numbers.size();
  if (sizeNames == sizeNumbers) {
    return sizeNames;
  }
  return -1;
}

number_t get_number_by_name(storage &contacts, std::string_view name) {
  for (int i = 0; i < contacts.names.size(); i++) {
    if (contacts.names[i] == name) {
      return contacts.numbers[i];
    }
  }
  return -1;
}

bool remove(storage &contacts, std::string_view name) {

  for (int i = 0; i < contacts.names.size(); i++) {
    if (contacts.names[i] == name) {
      contacts.names.erase(contacts.names.begin() + i);
      contacts.numbers.erase(contacts.numbers.begin() + i);
      return true;
    }
  }

  return false;
}

std::string to_string(const storage &contacts) {
  std::stringstream ss;
  for (int i = 0; i < contacts.names.size(); i++) {
    ss << "Name: " << contacts.names[i] << " Number: " << contacts.numbers[i]
       << '\n';
  }
  return ss.str();
}

void sort(storage &contacts) {
  size_t n = contacts.numbers.size();
  for (size_t i = 0; i < n - 1; ++i) {
    for (size_t j = 0; j < n - i - 1; ++j) {
      if (contacts.numbers[j] > contacts.numbers[j + 1]) {
        std::swap(contacts.numbers[j], contacts.numbers[j + 1]);
        // Swap corresponding names
        std::swap(contacts.names[j], contacts.names[j + 1]);
      }
    }
  }
}

} // namespace contact_list
