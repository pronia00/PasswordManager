#pragma once
#include <string>
#include <entry_collection.hpp>

class TaskManager 
{
  public: 
    void _open_file(std::string _path) {
      // try open file
      // ask for the password if exists
      // decypt file
      // load to the _passwords
      
    }
    void _save_data() {
      // open file
      // load data from _passwords
      // close file
    }
    void _close_file() {
      // if opened
      // ecnrypt file
      // close
    }
    const Entry& _add_entry (Entry _entry) {
      _passwords_collection._add_new_entry(std::move(_entry));
      return _passwords_collection._get_last_entry();
    }
    PasswordCollection& _get_collection() {
      return _passwords_collection;
    }

    private:
      PasswordCollection _passwords_collection{};
};