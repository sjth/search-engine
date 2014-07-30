binaries=covtest search_srv

all: covtest search_srv

search_srv: search_srv.cpp settings.h crow.h http_server.h http_connection.h parser.h http_response.h routing.h common.h utility.h json.h datetime.h logging.h
	${CXX} -Wall -g -O3 -std=c++1y -o search_srv search_srv.cpp http-parser/http_parser.c -pthread -lboost_system -lboost_thread -ltcmalloc_minimal -I http-parser/

test: covtest

runtest: search_srv
	pkill search_srv || exit 0
	./search_srv &
	python test.py || exit 0
	pkill search_srv

unittest: unittest.cpp routing.h utility.h crow.h http_server.h http_connection.h parser.h http_response.h common.h json.h datetime.h logging.h
	${CXX} -Wall -g -std=c++1y -o unittest unittest.cpp http-parser/http_parser.c -pthread -lboost_system -lboost_thread -I http-parser/
	./unittest

covtest: unittest.cpp routing.h utility.h crow.h http_server.h http_connection.h parser.h http_response.h common.h json.h datetime.h logging.h
	${CXX} -Wall -g -std=c++1y -o covtest --coverage unittest.cpp http-parser/http_parser.c -pthread -lboost_system -lboost_thread -I http-parser/
	./covtest
	gcov  unittest.cpp

.PHONY: clean

clean:
	rm -f $(binaries) *.o
