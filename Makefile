CXX=g++
OBJECTS= main.cpp pika_ssdb_client.cpp pika_ssdb_test.cpp libhiredis.a

ssdb-benchmark: ${OBJECTS}
	${CXX} -g -std=c++1y -o ssdb-benchmark ${OBJECTS} 

#main.o: main.cpp pika_ssdb_client.cpp
#	${CXX} -std=c++1y -o main.o  main.cpp pika_ssdb_client.cpp libhiredis.a

#pikaclient.o: pika_ssdb_client.cpp libhiredis.a
#	${CXX} -std=c++1y -o pikaclient.o  -c pika_ssdb_client.cpp libhiredis.a

clean:
	rm -rf *.o
