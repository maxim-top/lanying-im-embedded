//-------------------------------------------------------------------------------------------------
// File    : rosterManager.cc
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx roster manage implementation file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#include "rosterManage.h"
#include "bmx_cursor.h"

using namespace std;

void RosterListener::setClient(BMXClientPtr client) {
  mClient = client;
}

void RosterListener::onFriendAdded(int64_t sponsorId, int64_t recipientId) {
  std::string sponsor = "sponsorId " + std::to_string(sponsorId);
  std::string recipient = "recipientId " + std::to_string(recipientId);
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "RosterListener onFriendAdded");
  mvwaddstr(notifyWindow, 2, 1, sponsor.c_str());
  mvwaddstr(notifyWindow, 3, 1, recipient.c_str());
  touchwin(stdscr);
  refresh();
}

void RosterListener::onFriendRemoved(int64_t sponsorId, int64_t recipientId) {
  std::string sponsor = "sponsorId " + std::to_string(sponsorId);
  std::string recipient = "recipientId " + std::to_string(recipientId);
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "RosterListener onFriendRemoved");
  mvwaddstr(notifyWindow, 2, 1, sponsor.c_str());
  mvwaddstr(notifyWindow, 3, 1, recipient.c_str());
  touchwin(stdscr);
  refresh();
}

void RosterListener::onApplied(int64_t sponsorId, int64_t recipientId, const std::string& message) {
  std::string sponsor = "sponsorId " + std::to_string(sponsorId);
  std::string recipient = "recipientId " + std::to_string(recipientId);
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "RosterListener onApplied");
  mvwaddstr(notifyWindow, 2, 1, sponsor.c_str());
  mvwaddstr(notifyWindow, 3, 1, recipient.c_str());
  mvwaddstr(notifyWindow, 3, 1, message.c_str());
  touchwin(stdscr);
  refresh();
}