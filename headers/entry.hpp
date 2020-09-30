#pragma once

#include <string>
#include <tclap/json.hpp>

using json = nlohmann::json;

namespace entry {
  
  class Entry {
    public:
    Entry(void) {};
    Entry(const std::string& name, const std::string& login, const std::string& password) 
      : _name(name)
      , _login(login)
      , _password(password)
    {}; 

    std::string _name;
    std::string _login;
    std::string _password;
  };

    // needed for json library to perform casting from Entry to json
  void to_json(json& j, const Entry& e);
  
  // parsing json to Entry
  void from_json(const json& j, Entry& e);
}