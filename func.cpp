#include <iostream>

using namespace std;

bool starts_with(const string& s, const string& prefix)
{
    auto size = prefix.size();
    if (s.size() < size) return false;
    return equal(begin(prefix), end(prefix), begin(s));
}

bool check_option(const string& s, const string option_name)
{
    return starts_with(s, "--" + option_name + "=");
}
