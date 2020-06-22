#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

void teste_de_uso(const std::string &prog_name);


std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}



int main(int argc, char *argv[]) {


	std::string data;
	data = "# " + format_current_date("%d/%m/%Y");
	std::string hora;
	hora = "- " + format_current_date("%H:%M:%S") + " ";


	if (argc == 1) {
       teste_de_uso(argv[0]);
       return 1;
    }


	std::ofstream arquivo_saida{"diary.md", std::ios::app};

	  if (!arquivo_saida.is_open()) {
    std::cerr << "O arquivo não pode ser criado." << std::endl;
    return 1;
  }

  arquivo_saida.close();

	std::string msn;
	std::string msninput;
	std::string teste = argv[1];

	if (argc == 2 && teste == "list") {

		std::ifstream arquivo_entrada{"diary.md"};


		while (!arquivo_entrada.eof()) {

			std::getline(arquivo_entrada, msn);


				if(msn.substr(0,1) !="#"){
			   	   std::cout  << msn << std::endl;
				}
			
		}

		arquivo_entrada.close();

		return 0;
	}

	else if (teste == "add") {

        if (argc == 2) {
   		   std::cout << "escreva sua mensagem: ";
		   std:getline(std::cin,msninput);
	    }

	    else {
  			msninput = argv[2];
	    }

        std::ifstream arquivo_entrada{"diary.md"};

		while (!arquivo_entrada.eof()) {
			std::getline(arquivo_entrada, msn);

			if (msn == data){
				break;
			}
		}

		std::ofstream arquivo_saida{"diary.md", std::ios::app};
		if (arquivo_entrada.eof()) {
			arquivo_saida << std::endl << data << std::endl << std::endl;
		}

		arquivo_saida << hora << msninput << std::endl;
		std::cout << "mensagem adicionada: " << msninput << std::endl;
		arquivo_saida.close();
		arquivo_entrada.close();

		return 0;		

	}



}

void teste_de_uso(const std::string &prog_name) {
	std::cout << "Favor usar: " << prog_name << " add ou " << prog_name << " add <sua mensagem>" << std::endl;
	std::cout << "ou" << std::endl;
	std::cout << "Use: " << prog_name << " list" << std::endl;

}