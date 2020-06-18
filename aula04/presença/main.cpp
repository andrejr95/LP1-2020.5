#include <iostream>
#include <string>
#include <fstream>

void teste_de_uso(const std::string &prog_name);

int main(int argc, char *argv[]) {

	if (argc == 1) {
    teste_de_uso(argv[0]);
    return 1;
  }

	std::string msn;
	std::string teste = argv[1];

	if (argc == 2 && teste == "list") {

		std::ifstream arquivo_entrada{"bloco.txt"};

		int i = 0;

		while (!arquivo_entrada.eof()) {

			i++;
			std::getline(arquivo_entrada, msn);

			if (msn != ""){

				std::cout << i << ". " << msn << std::endl;
			}
		}

		arquivo_entrada.close();

		return 0;
	}

	else if (argc == 2 && teste == "add") {

		std::cout << "escreva sua mensagem entre aspas: ";
		std:getline(std::cin, msn);
	}

	else if (argc == 3 && teste == "add") {

		msn = argv[2];
	}


	std::ofstream arquivo_saida{"bloco.txt", std::ios::app};
	arquivo_saida << msn << std::endl;
	std::cout << "mensagem adicionada: " << msn << std::endl;
	arquivo_saida.close();

	return 0;
}

void teste_de_uso(const std::string &prog_name) {
	std::cout << "Favor usar: " << prog_name << " add ou " << prog_name << " add <sua mensagem entre aspas>" << std::endl;
	std::cout << "ou" << std::endl;
	std::cout << "Use: " << prog_name << " list" << std::endl;

}