//-------------------------------------------------------------------------------------------------
// File    : main.cc
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx embedded demo file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#include "global.h"
#include "bmx_cursor.h"

using namespace floo;
using namespace std;

/*
测试账号          密码
maximtest1       1      6597271134048
maximtest2       1      6597271134656
*/

void initSDK() {
  std::string path = "/Users/jiangwei/Code/bmx/embedded/test/data";
  config = BMXSDKConfigPtr(new BMXSDKConfig(BMXClientType::macOS, "10", path, path, "2.0", "1234", "userAgent"));
  config->setAppID("welovemaxim");
  config->setDeviceUuid("b81f412e-fcb2-44fb-9f44-5e8e5b1e809e");
  config->setConsoleOutput(false);
  client = BMXClient::create(config);

  chatListener = new ChatListener();
  chatListener->setClient(client);

  userListener = new UserListener();
  userListener->setClient(client);

  rosterListener = new RosterListener();
  rosterListener->setClient(client);

  groupListener = new GroupListener();
  groupListener->setClient(client);
}

int main(int argc, char* argv[])
{

  initSDK();
  initWindow();

  int key;
  do {
    WINDOW **menu_items;
    key = getch();
    if (key == KEY_F(1)) {
      menu_items = draw_chat_menu(0);
      scroll_chat_menu(menu_items, CHAT_MENU_SIZE - 1);
    } else if (key == KEY_F(2)) {
      menu_items = draw_user_menu(10);
      scroll_user_menu(menu_items, USER_MENU_SIZE - 1);
    } else if (key == KEY_F(3)) {
      menu_items = draw_roster_menu(20);
      scroll_roster_menu(menu_items, ROSTER_MENU_SIZE - 1);
    } else if (key == KEY_F(4)) {
      menu_items = draw_group_menu(30);
      scroll_group_menu(menu_items, GROUP_MENU_SIZE - 1);
    }
    touchwin(stdscr);
    refresh();
  } while (key!=ESCAPE);

  deleteWindow();

  return 0;
}