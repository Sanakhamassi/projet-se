//evertrime my files ... changes recompiles them with g++ and save then in output
outut: traitement.o fifo.o sjf.o rr.o  
       g++ traitement.o fifo.o sjf.o rr.o -o output
//crete the files . 
traitement.o: traitement.c
     g++ -c traitement.c

clean: 
    rm *.o output