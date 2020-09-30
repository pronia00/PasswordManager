#pragma once

#include <entry.hpp>
#include <vector>

using Entry = entry::Entry;

class PasswordCollection {

  public:
    void _add_new_entry(Entry _p) {
      _passwords.push_back(std::move(_p));
      return;
    }
    const Entry& _get_last_entry() const {
      return _passwords[_passwords.size() - 1];
    }
    std::vector<Entry>& _data() {
      return _passwords;
    }

    const std::vector<Entry>& _data() const {
      return _passwords;
    }
  private: 
    std::vector<Entry> _passwords;
};