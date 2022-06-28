#Makefile

EXECUTAVEL=app
CFLAGS=-c -std=c++11

all: ${EXECUTAVEL}

${EXECUTAVEL}: main.o Cnpj.o Endereco.o Produto.o Produtos.o Empresa.o Nfe.o Desconto.o DescontoCombinado.o DescontoLMPN.o DescontoSimples.o Program.o
	@g++ main.o Cnpj.o Endereco.o Produto.o Produtos.o Empresa.o Nfe.o Desconto.o DescontoCombinado.o DescontoLMPN.o DescontoSimples.o Program.o -o ${EXECUTAVEL}

main.o: main.cpp dependencies/Program.hpp
	@g++ ${CFLAGS} main.cpp

Cnpj.o: dependencies/Cnpj.cpp dependencies/Cnpj.hpp
	@g++ ${CFLAGS} dependencies/Cnpj.cpp

Endereco.o: dependencies/Endereco.cpp dependencies/Endereco.hpp
	@g++ ${CFLAGS} dependencies/Endereco.cpp

Produto.o: dependencies/Produto.cpp dependencies/Produto.hpp
	@g++ ${CFLAGS} dependencies/Produto.cpp

Produtos.o: dependencies/Produtos.cpp dependencies/Produtos.hpp dependencies/Produto.hpp
	@g++ ${CFLAGS} dependencies/Produtos.cpp

Empresa.o: dependencies/Empresa.cpp dependencies/Empresa.hpp dependencies/Endereco.hpp dependencies/Cnpj.hpp
	@g++ ${CFLAGS} dependencies/Empresa.cpp

Nfe.o: dependencies/Nfe.cpp dependencies/Nfe.hpp 
	@g++ ${CFLAGS} dependencies/Nfe.cpp

Desconto.o: dependencies/Desconto.cpp dependencies/Desconto.hpp 
	@g++ ${CFLAGS} dependencies/Desconto.cpp

DescontoCombinado.o: dependencies/DescontoCombinado.cpp dependencies/DescontoCombinado.hpp dependencies/Desconto.hpp 
	@g++ ${CFLAGS} dependencies/DescontoCombinado.cpp

DescontoLMPN.o: dependencies/DescontoLMPN.cpp dependencies/DescontoLMPN.hpp dependencies/Desconto.hpp 
	@g++ ${CFLAGS} dependencies/DescontoLMPN.cpp

DescontoSimples.o: dependencies/DescontoSimples.cpp dependencies/DescontoSimples.hpp dependencies/Desconto.hpp 
	@g++ ${CFLAGS} dependencies/DescontoSimples.cpp

Program.o: dependencies/Program.cpp dependencies/Program.hpp dependencies/Empresa.hpp dependencies/Produtos.hpp dependencies/Nfe.hpp dependencies/Desconto.hpp dependencies/DescontoSimples.hpp dependencies/DescontoLMPN.hpp dependencies/DescontoCombinado.hpp
	@g++ ${CFLAGS} dependencies/Program.cpp

run: ${EXECUTAVEL}
	@./${EXECUTAVEL}

clean:
	@rm -f main.o Cnpj.o Endereco.o Produto.o Produtos.o Empresa.o Nfe.o Desconto.o DescontoCombinado.o DescontoLMPN.o DescontoSimples.o Program.o ${EXECUTAVEL}