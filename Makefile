#Makefile

EXECUTAVEL=app
CFLAGS=-c -std=c++11

all: ${EXECUTAVEL}

${EXECUTAVEL}: main.o Empresa.o Cnpj.o Endereco.o Produtos.o Produto.o Head.o
	@g++ main.o Empresa.o Cnpj.o Endereco.o Produtos.o Produto.o Program.o -o ${EXECUTAVEL}

main.o: main.cpp dependencies/Cnpj.hpp "dependencies/Endereco.hpp" dependencies/Empresa.hpp dependencies/Produto.hpp dependencies/Produtos.hpp dependencies/Program.hpp
	@g++ ${CFLAGS} main.cpp

Produto.o: dependencies/Produto.cpp dependencies/Produto.hpp
	@g++ ${CFLAGS} Produto.cpp

Produtos.o: dependencies/Produtos.cpp dependencies/Produtos.hpp dependencies/Produto.hpp
	@g++ ${CFLAGS} Produtos.cpp

Cnpj.o: dependencies/Cnpj.cpp dependencies/Cnpj.hpp
	@g++ ${CFLAGS} Cnpj.cpp

Empresa.o: dependencies/Empresa.cpp dependencies/Empresa.hpp dependencies/Endereco.hpp dependencies/Cnpj.hpp
	@g++ ${CFLAGS} Empresa.cpp

Endereco.o: dependencies/Endereco.cpp dependencies/Endereco.hpp
	@g++ ${CFLAGS} Endereco.cpp

Program.o: dependencies/Program.cpp dependencies/Program.hpp dependencies/Empresa.hpp dependencies/Produtos.hpp
	@g++ ${CFLAGS} Program.cpp

run: ${EXECUTAVEL}
	@./${EXECUTAVEL}

clean:
	@rm -f main.o Empresa.o Cnpj.o Endereco.o Produtos.o Produto.o Program.o ${EXECUTAVEL}