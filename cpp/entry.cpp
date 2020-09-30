#include <entry.hpp>

void entry::to_json(json& j, const Entry& e) {
    j = json{{"name", e._name}, {"login", e._login}, {"password", e._password}};
}

void entry::from_json(const json& j, Entry& e) {
    j.at("name").get_to(e._name);
    j.at("login").get_to(e._login);
    j.at("password").get_to(e._password);
}
