# 蓝莺IM 嵌入式版

蓝莺IM，是由[美信拓扑](https://www.lanyingim.com/)团队研发的新一代即时通讯云服务，SDK设计简单集成方便，服务采用云原生技术和多云架构，私有云也可按月付费。

蓝莺IM APP 为方便体验试用蓝莺 IMSDK 的 DemoApp。开发者可直接[在线试用](https://chat-h5.lanyingim.com)，也可在官网[下载页面](https://www.lanyingim.com/downloads/)选择试用所有客户端。

[![Scc Count Badge](https://sloc.xyz/github/maxim-top/lanying-im-embedded/?category=total&avg-wage=1)](https://github.com/maxim-top/lanying-im-embedded/) [![Scc Count Badge](https://sloc.xyz/github/maxim-top/lanying-im-embedded/?category=code&avg-wage=1)](https://github.com/maxim-top/lanying-im-embedded/)

## 准备运行环境
操作系统：Ubuntu 64位系统

1. 安装g++开发环境
>`sudo apt-get install build-essential`
2. 安装openssl系统库
>`sudo apt-get install libssl-dev && sudo apt-get install openssl`
3. 安装zlib系统库
>`sudo apt-get install zlib1g-dev`
4. 安装libcurl系统库
>`sudo apt-get install libcurl4-openssl-dev`
5. 安装ncurses系统库
>`sudo apt-get install libncurses5-dev`

## 开发

1.修改main.cc文件中path的路径地址，修改为本地环境下代码存在的实际路径地址。
2.安装依赖后，进入test文件夹进行编译：

>`cd test && make linux_demo`

然后运行即可。

当前默认登陆是 DemoApp（AppID:welovemaxim）下 maximtest1 用户，发送消息与 maximtest2 用户互通。

### 开发自己的应用

请先修改美信拓扑 AppID

打开文件 `./test/src/main.cc`, 将默认 AppID: welovemaxim 更改为你的应用AppID，此 AppID 为在[蓝莺IM后台](https://console.lanyingim.com/)创建应用后获取。

了解更多信息可以阅读[在线文档](https://docs.lanyingim.com)，或者在本仓库提问，好好玩 :)

-- --
**蓝莺IM 专业SDK，私有云按月付费**
