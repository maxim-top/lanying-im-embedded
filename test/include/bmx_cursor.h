//-------------------------------------------------------------------------------------------------
// File    : cursor.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx cursor define file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

#include "global.h"

#define ENTER 10
#define ESCAPE 27

#define CHAT_MENU_SIZE  4

typedef enum {
  CLIENT_SIGN_IN,
  CLIENT_SIGN_OUT,
  CLIENT_SEND_MESSAGE,

  USER_SET_NICK_NAME,
  USER_SET_MOBILE_PHONE,

  ROSTER_APPLY,
  ROSTER_REMOVE,
  ROSTER_ACCEPT,
  ROSTER_DECLINE,

  GROUP_SET_MY_NICK_NAME,
  GROUP_JOIN,
  GROUP_LEAVE,
  GROUP_SEARCH
} OperationType;

void init_curses();

void draw_menubar(WINDOW *menubar);
void draw_conversation(WINDOW *conversation);
void draw_notify(WINDOW* notify);
void draw_operation(WINDOW* oper);
void draw_input(WINDOW* in);

WINDOW **draw_menu(int start_col);
void delete_menu(WINDOW **items,int count);

WINDOW **draw_chat_menu(int start_col);
WINDOW **draw_user_menu(int start_col);
WINDOW **draw_roster_menu(int start_col);
WINDOW **draw_group_menu(int start_col);
//WINDOW **draw_conversation_menu(int start_col);

void initWindow();
void deleteWindow();

void PressUpDown(WINDOW **items, int key, int count, int &selected);
void changeMenu(WINDOW **items, int type, int offset, int oldSize, int newSize);

void scroll_chat_menu(WINDOW **items, int count);
void scroll_user_menu(WINDOW **items, int count);
void scroll_roster_menu(WINDOW **items, int count);
void scroll_group_menu(WINDOW **items, int count);

void register_listener();
void unregister_listener();

void showConversation();

string trimWhiteSpace(const string& str);
void split(const string& str, const string& delim, vector<string> &ret);

void showOpeartionNotify();
void getParams(std::vector<std::string>& params);
void processOperation();