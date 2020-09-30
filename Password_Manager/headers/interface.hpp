#pragma once

#include <iostream>
#include <entry.hpp>

class Interface {
  public:
    static void _output_entry(const entry::Entry& _entry) {
      std::cout << "name: " 
                << _entry._name << "\nlogin: " 
                << _entry._login << "\npassword: " 
                << _entry._password << "\n";
    }
};