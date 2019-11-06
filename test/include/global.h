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

#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include "bmx_client.h"
#include "chatManage.h"
#include "userManage.h"
#include "rosterManage.h"
#include "groupManage.h"

using namespace floo;

#define ENTER 10
#define ESCAPE 27

#define CHAT_MENU_SIZE  4
#define USER_MENU_SIZE  3
#define ROSTER_MENU_SIZE  5
#define GROUP_MENU_SIZE  5

extern BMXSDKConfigPtr config;
extern BMXClientPtr client;

extern ChatListener* chatListener;
extern UserListener* userListener;
extern RosterListener* rosterListener;
extern GroupListener* groupListener;

extern WINDOW *menubar; 
extern WINDOW *conversationWindow;
extern WINDOW *notifyWindow; 
extern WINDOW *operWindow;
extern WINDOW *inputWindow;

extern int operationType;