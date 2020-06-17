#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {

	std::string msn;
	std::ifstream arquivo_entrada("entrada.txt");
  std::ofstream arquivo_saida("saida.txt", std::ios::app);

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

	 if(arquivo_saida.fail()){

        std::cout << "Arquivo não localizado" << std::endl;

        return -1;
 }

	arquivo_saida << msn << std::endl;
	arquivo_saida.close();
  
	std::cout << "mensagem adicionada com sucesso" << std::endl;


  return 0;
}