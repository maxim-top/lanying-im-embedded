UNAME := $(shell sh -c 'uname 2>/dev/null || echo not')

debug:
	g++ -Wall -std=c++11 -g src/global.cc src/chatManage.cc src/userManage.cc src/rosterManage.cc src/groupManage.cc src/bmx_cursor.cc src/main.cc -o embedded.out -I./include -I../floo/include -lcurses ../floo/libs/mac/libfloo.a ../floo/libs/mac/libcrypto.dylib -lz -lcurl -lsqlite3 

linux_demo:
	g++ -Wall -std=c++11 src/global.cc src/chatManage.cc src/userManage.cc src/rosterManage.cc src/groupManage.cc src/bmx_cursor.cc src/main.cc -o embedded.out -I./include -I../floo/include -lcurses ../floo/libs/ubuntu/libfloo.a -lcrypto -lz -lcurl -lsqlite3

mac_demo:
	g++ -Wall -std=c++11 src/global.cc src/chatManage.cc src/userManage.cc src/rosterManage.cc src/groupManage.cc src/bmx_cursor.cc src/main.cc -o embedded.out -I./include -I../floo/include -lcurses ../floo/libs/mac/libfloo.a ../floo/libs/mac/libcrypto.dylib -lz -lcurl -lsqlite3

clean:
	rm -rf embedded.out