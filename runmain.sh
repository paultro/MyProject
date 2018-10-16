gcc -c -I./include ./src/addclass/addclass.c -o ./obj/addclass.o
gcc -c -I./include ./src/addstu/addstu.c -o ./obj/addstu.o
gcc -c -I./include ./src/alterclass/alterclass.c -o ./obj/alterclass.o
gcc -c -I./include ./src/alterstu/alterstu.c -o ./obj/alterstu.o
gcc -c -I./include ./src/deleteclass/deleteclass.c -o ./obj/deleteclass.o
gcc -c -I./include ./src/deletestu/deletestu.c -o ./obj/deletestu.o
gcc -c -I./include ./src/initcla/initcla.c -o ./obj/initcla.o
gcc -c -I./include ./src/initstu/initstu.c -o ./obj/initstu.o
gcc -c -I./include ./src/scanfcla/clakb.c -o ./obj/clakb.o
gcc -c -I./include ./src/scanfstu/stukb.c -o ./obj/stukb.o
gcc -c -I./include ./src/searchclass/searchclass.c -o ./obj/searchclass.o
gcc -c -I./include ./src/searchstu/searchstu.c -o ./obj/searchstu.o

ar -rsv ./obj/libtest.a ./obj/*.o

gcc  -o main1 ./maintest/maintest.c -I./include -L./obj/ -ltest
