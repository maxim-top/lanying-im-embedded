# README #

embedded版本的demo以 ubuntu系统为例，其它操作系统版本及交叉编译请联系商务或者提交Issue获取。

## embedded demo运行条件 ##
+ Ubuntu 64位系统。
+ 安装g++开发环境。执行 sudo apt-get install build-essential 指令来安装C++编译环境。
+ 安装openssl系统库。 执行 sudo apt-get install libssl-dev 和 sudo apt-get install openssl 指令来安装openssl库。
+ 安装zlib系统库。执行 sudo apt-get install zlib1g-dev 指令来安装zlib库。
+ 安装sqlite3系统库。执行 sudo apt-get install libsqlite3-dev 和 sudo apt-get install sqlite3 指令来安装sqlite3库。
+ 安装sqlcipher系统库。执行 sudo apt-get install libsqlcipher-dev 指令来安装sqlcipher库。
+ 安装libcurl系统库。执行 sudo apt-get install libcurl4-openssl-dev 指令来安装libcurl库。
+ 安装ncurses系统库。执行 sudo apt-get install libncurses5-dev 指令来安装ncurses库。

## embedded demo 运行 ##
安装上环境依赖后，在test文件夹下运行make linux_demo即可编译软件。然后运行即可。现在demo中默认嵌入maximtest1用户，发送消息与maximtest2用户互通。
