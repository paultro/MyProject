CC = gcc
OBJ = addclass.o addstu.o alterclass.o alterstu.o deleteclass.o deletestu.o initcla.o initstu.o clakb.o stukb.o searchclass.o searchstu.o
TOP_DIR = ~/shixun/MyProject
OBJ_BIR = $(TOP_DIR)/obj
BIN_DIR = $(TOP_DIR)/bin
CFLAGS = -I$(TOP_DIR)/include/ -g -C -o
BFLAGS = $(TOP_DIR)/include/student.h $(TOP_DIR)/include/class.h
GFLAGS = $(TOP_DIR)/src/addclass/ $(TOP_DIR)/src/addstu/ $(TOP_DIR)/src/alterclass/ $(TOP_DIR)/src/alterstu/ $(TOP_DIR)/src/deleteclass/ $(TOP_DIR)/src/deletestu/ $(TOP_DIR)/src/initcla/ $(TOP_DIR)/src/initstu/ $(TOP_DIR)/src/scanfcla/ $(TOP_DIR)/src/scanfstu/ $(TOP_DIR)/src/searchclass/ $(TOP_DIR)/src/searchstu/
WFLAGS = $(TOP_DIR)/src/addclass/addclass.h $(TOP_DIR)/src/addstu/addstu.h $(TOP_DIR)/src/alterclass/alterclass.h $(TOP_DIR)/src/alterstu/alterstu.h $(TOP_DIR)/src/deleteclass/deleteclass.h $(TOP_DIR)/src/deletestu/deletestu.h $(TOP_DIR)/src/initcla/initcla.h $(TOP_DIR)/src/initstu/initstu.h $(TOP_DIR)/src/scanfcla/scanfcla.h $(TOP_DIR)/src/scanfstu/scanfstu.h $(TOP_DIR)/src/searchclass/searchclass.h $(TOP_DIR)/src/searchstu/searchstu.h
BIN = main2
SUB_DIR = src/addclass \
          src/addstu \
          src/alterclass \
          src/alterstu \
          src/deleteclass \
          src/deletestu \
          src/initcla \
          src/initstu \
          src/scanfcla \
          src/scanfstu \
          src/searchclass \
          src/searchstu \
          obj
          

export CC SRC INCLUDE OBJ TOP_DIR OBJ_DIR BIN_DIR BIN CFLAGS GFLAGS WFLAGS BFLAGS

all: $(SUB_DIR) LAST

CHECKDIR:
	mkdir -p $(SUB_DIR) $(BIN_DIR)
$(SUB_DIR):ECHO
	make -C $@
ECHO:
	@echo $(SUB_DIR)
	@echo begin compile
LAST:
	gcc -o main2 ./maintest/maintest.c -I./include -L./obj/ -ltest2

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)

