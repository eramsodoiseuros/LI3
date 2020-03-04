INC = ../include/
OBJ = ../src/


objects = $(OBJ)main.o # $(OBJ)IO.o $(OBJ)catalogo_produtos.o $(OBJ)catalogo_clientes.o $(OBJ)vendas.o $(OBJ)faturacao.o $(OBJ)filial.o
CFLAGS = -g -Wall -ansi -std=c99 -pedantic -O2 
CC = gcc


SGV : $(objects)
	$(CC) $(CFLAGS) -o SGV $(objects) 


main.o : $(INC)main.h # $(INC)IO.o $(INC)catalogo_produtos.h $(INC)catalogo_clientes.h $(INC)vendas.h
#IO.o : $(INC)IO.h $(INC)catalogo_produtos.h $(INC)catalogo_clientes.h $(INC)vendas.h $(INC)faturacao.h $(INC)filial.h 
#vendas.o : $(INC)vendas.h $(INC)catalogo_produtos.h $(INC)catalogo_clientes.h 
#catalogo_produtos.o : $(INC)catalogo_produtos.h 
#catalogo_clientes.o : $(INC)catalogo_clientes.h 
#faturacao.o : $(INC)faturacao.h 
#filial.o : $(INC)filial.h 
read.o : $(INC)read.h




.PHONY : clean
clean : 
	rm SGV $(objects)