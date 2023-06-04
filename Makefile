all: st_pipeline

st_pipeline: st_pipeline.o activeObject.o queue.o prime.o
	gcc -o st_pipeline st_pipeline.o activeObject.o queue.o prime.o -lm -lpthread

st_pipeline.o: st_pipeline.c activeObject.h queue.h prime.h
	gcc -c st_pipeline.c -lm -lpthread

activeObject.o: activeObject.c activeObject.h queue.h prime.h
	gcc -c activeObject.c -lm -lpthread

queue.o: queue.c queue.h
	gcc -c queue.c -lpthread

prime.o: prime.c prime.h
	gcc -c prime.c

clean:
	rm *.o st_pipeline