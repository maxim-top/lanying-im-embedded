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

BMXSDKConfigPtr config = nullptr;
BMXClientPtr client = nullptr;
ChatListener* chatListener = nullptr;
UserListener* userListener = nullptr;
RosterListener* rosterListener = nullptr;
GroupListener* groupListener = nullptr;
WINDOW* menubar = nullptr;
WINDOW* conversationWindow = nullptr;
WINDOW* notifyWindow = nullptr;
WINDOW* operWindow = nullptr;
WINDOW* inputWindow = nullptr;
int operationType = 0;