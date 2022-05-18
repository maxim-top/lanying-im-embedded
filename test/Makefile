UNAME := $(shell sh -c 'uname 2>/dev/null || echo not')

debug:
	g++ -Wall -std=c++11 -g src/global.cc src/chatManage.cc src/userManage.cc src/rosterManage.cc src/groupManage.cc src/bmx_cursor.cc src/main.cc -o embedded.out -I./include -I../floo/include -lcurses -pthread -ldl ../floo/libs/ubuntu/libfloo.a -lcrypto -lz -lcurl -ldl

linux_demo:
	g++ -Wall -std=c++11 src/global.cc src/chatManage.cc src/userManage.cc src/rosterManage.cc src/groupManage.cc src/bmx_cursor.cc src/main.cc -o embedded.out -I./include -I../floo/include -lcurses -pthread ../floo/libs/ubuntu/libfloo.a -lcrypto -lz -lcurl -ldl

mac_demo:
	g++ -Wall -std=c++11 src/global.cc src/chatManage.cc src/userManage.cc src/rosterManage.cc src/groupManage.cc src/bmx_cursor.cc src/main.cc -o embedded.out -I./include -I../floo/include -lcurses -pthread -ldl ../floo/libs/mac/libfloo.a ../floo/libs/mac/libcrypto.dylib -lz -lcurl -ldl

clean:
	rm -rf embedded.out