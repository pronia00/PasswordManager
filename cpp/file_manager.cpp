#include <file_manager.hpp>

bool FileManager::_append_to_file(const Entry& _entry, const std::string& _path) {
      std::fstream fout(_path, std::ios::app);
      if (!fout) {
        return false;
      }
      _write_single_entry(fout, _entry);
      return true;
    }

bool FileManager::_write_single_entry(std::fstream& _fout, const Entry& _entry) {
      json j = _entry;
      _fout << j << std::endl;

      return true;
    }