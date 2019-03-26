#include "soaptestService.h"
#include "test.nsmap"

#include <iostream>

int main(int argc, char** argv) {
  testService calc;
  soap_set_mode(&calc, SOAP_C_UTFSTRING);  //设置编码
  calc.mode |= SOAP_C_UTFSTRING;

  int port = 8090;
  //  if (calc.bind(nullptr, 8090, 1)) {
  if (calc.run(port)) {
    std::cerr << "Calc service run failed" << std::endl;
    exit(0);
  }
  return 0;
}

int testService::test(std::string& result) {
  result = "hello 东";
  return SOAP_OK;
}
