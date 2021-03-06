#include "soaptestProxy.h"
#include "test.nsmap"

#include <iostream>

int main(int argc, char **argv) {
  std::string result = "";

  testProxy calc;
  calc.soap_endpoint = "http://localhost:8090";
  if (calc.test(result) == SOAP_OK) {
    std::cout << "result: " << result << std::endl;
  } else {
    calc.soap_stream_fault(std::cerr);
  }
  calc.destroy();  // delete data and release memory

  return 0;
}
