#include "soaptestService.h"
#include "test.nsmap"

#include <iostream>

int main(int argc, char** argv) {
  testService calc;
  int port = 8090;
  if (calc.run(port)) {
    std::cerr << "Calc service run failed" << std::endl;
    exit(0);
  }
  return 0;
}

int testService::test(std::string& result) {
  result = "hello dong";
  return SOAP_OK;
}
