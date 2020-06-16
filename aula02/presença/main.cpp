#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

	std::string msn;

  if (argc <= 1) {
    std::cout << "Uso: " << argv[0] << " add <mensagem>";
    return 1;
  }
 
  if (argc == 2 && std::string(argv[1]) == "add"){ 

      std::cout << "Digite uma mensagem: ";
      std::getline(std::cin, msn);
      std::cout << msn << std::endl;
    
  }

  else if (argc == 3 && std::string(argv[1]) == "add") {
		
      std::cout << "mensagem adicionada: " << argv[2] << std::endl;
    
  }
  
  return 0;
}