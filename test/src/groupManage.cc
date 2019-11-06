
//-------------------------------------------------------------------------------------------------
// File    : groupManage.cc
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx group manage implementation file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#include "groupManage.h"
#include "bmx_cursor.h"

using namespace std;

void GroupListener::setClient(BMXClientPtr client) {
  mClient = client;
}

void GroupListener::onGroupJoined(BMXGroupPtr group) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "GroupListener onGroupJoined");
  mvwaddstr(notifyWindow, 2, 1, std::to_string(group->groupId()).c_str());
  touchwin(stdscr);
  refresh();
}

void GroupListener::onGroupLeft(BMXGroupPtr group, const std::string& reason) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "GroupListener onGroupLeft");
  mvwaddstr(notifyWindow, 2, 1, std::to_string(group->groupId()).c_str());
  mvwaddstr(notifyWindow, 3, 1, reason.c_str());
  touchwin(stdscr);
  refresh();
}

void GroupListener::onApplicationAccepted(BMXGroupPtr group, int64_t approver) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "GroupListener onApplicationAccepted");
  mvwaddstr(notifyWindow, 2, 1, std::to_string(group->groupId()).c_str());
  mvwaddstr(notifyWindow, 3, 1, std::to_string(approver).c_str());
  touchwin(stdscr);
  refresh();
}

void GroupListener::onApplicationDeclined(BMXGroupPtr group, int64_t approver, const std::string& reason) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "GroupListener onApplicationDeclined");
  mvwaddstr(notifyWindow, 2, 1, std::to_string(group->groupId()).c_str());
  mvwaddstr(notifyWindow, 3, 1, std::to_string(approver).c_str());
  mvwaddstr(notifyWindow, 4, 1, reason.c_str());
  touchwin(stdscr);
  refresh();
}