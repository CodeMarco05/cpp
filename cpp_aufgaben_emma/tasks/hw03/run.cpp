#include "contact_list.h"
#include "hw03.h"

#include <iostream>

namespace contact_list {

void test_contact_list() {
  storage abook;
  add(abook, "Best Friend", 421234);
  add(abook, "False Friend", 10032331);
  int num = get_number_by_name(abook, "Best Friend");
  std::cout << "Number for Best Friend: " << num << std::endl;

  std::string res = to_string(abook);
  std::cout << "Res: \n" << res << std::endl;
}

} // namespace contact_list

int main() {
  contact_list::test_contact_list();

  return 0;
}
