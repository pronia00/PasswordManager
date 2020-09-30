#pragma once

#include <fstream>
#include <entry.hpp>
#include <string>
#include <entry_collection.hpp>

using Entry = entry::Entry;

class FileManager {
  public: 

    bool _append_to_file(const Entry& _entry, const std::string& _path);

    bool _write_single_entry(std::fstream& _fout, const Entry& _entry);

    std::string _read_json_entry(std::ifstream& _fin) {
      //read string size
      size_t size = 0;
      _fin.read(reinterpret_cast<char*>(&size), sizeof(size_t));

      //read string
      char str[size + 1];
      _fin.read(str, size);
      return std::string(str);
    }
    
    bool _read_from_file(PasswordCollection& _data, const std::string& _path) {
      std::ifstream fin(_path, std::ios::binary);
      if (!fin) {
        return false;
      }

      if (fin.eof()) {
        return true;
      }
      do {
        json _j_temp;
        

      } while (!fin.eof());
    fin.close();
    return true;
  }
    
  private:
    std::string _file_path;
    bool _is_opened = false;
};