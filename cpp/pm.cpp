#include <catch.hpp>
#include <tclap/CmdLine.h>
#include <tclap/json.hpp>
#include <task_manager.hpp>
#include <entry.hpp>
#include <interface.hpp>
#include <entry_collection.hpp>
#include <sequrity.hpp>
#include <file_manager.hpp>

#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using json = nlohmann::json;
using Entry = entry::Entry;

int main(int argc, char** argv)
{
	try {
  
	TCLAP::CmdLine cmd("Here you can find some help info", ' ', "1.0");
  TaskManager tm;
  FileManager fm;

  // comands list
  TCLAP::SwitchArg cmd_view("v", "view", "show list of entries", cmd, false);
  TCLAP::SwitchArg cmd_add ("a", "add", "adds new entry", cmd, false);

	TCLAP::ValueArg<std::string> file_arg ( "f", "file", "file name", false,"temp", "string" );
	TCLAP::ValueArg<std::string> name_arg ( "n", "name", "new name", false,"def_name", "string" );
	TCLAP::ValueArg<std::string> password_arg ("p", "password", "new password", false, "def_password", "string" );
  TCLAP::ValueArg<std::string> login_arg ("l" , "login","new login", false, "def_login", "string");
  
	cmd.add( password_arg );
	cmd.add( login_arg );
  cmd.add( name_arg );
  cmd.add( file_arg);

	// Parse the argv array.
	cmd.parse( argc, argv );

  // find out what user whant's us to do
  if (cmd_add.getValue() == true) {
	  std::string name = name_arg.getValue();
	  std::string password = password_arg.getValue();
	  std::string login = login_arg.getValue();
    std::string file = file_arg.getValue();

    if (!file_arg.isSet()) {
      // ask to enter file name
    }
    
    //check if file is opened
    auto new_entry = 
          tm._add_entry(Entry(name, login, password));

    if (
        fm._append_to_file(new_entry, file)
    ) {
    } else {
      std::cout << "Error in writing to file" << std::endl;
    }
  } else if (cmd_view.getValue() == true) {
    std::cout << "Data list from file: " << std::endl;
    std::string file = file_arg.getValue();

    fm._read_from_file(tm._get_collection(), file);
    for (const auto& _entry : tm._get_collection()._data()) {
      Interface::_output_entry(_entry);
    }
  } else {
    std::cout << "Nothing happend" << std::endl;
  }
	
	} catch (TCLAP::ArgException &e)  // catch any exceptions
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }

  return 0;
}