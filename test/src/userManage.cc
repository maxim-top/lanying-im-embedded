//-------------------------------------------------------------------------------------------------
// File    : userManage.cc
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx user manage implementation file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#include "userManage.h"
#include "bmx_cursor.h"

using namespace std;

void UserListener::setClient(BMXClientPtr client) {
  mClient = client;
}

void UserListener::onConnectStatusChanged(BMXConnectStatus status) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "UserListener onConnectStatusChanged");
  switch (status) {
    case BMXConnectStatus::Disconnected:
      mvwaddstr(notifyWindow, 2, 1, "Disconnected");
      break;
    case BMXConnectStatus::Connected:
      mvwaddstr(notifyWindow, 2, 1, "Connected");
      break;
    default:
      break;
  }
  touchwin(stdscr);
  refresh();
}

void UserListener::onUserSignIn(BMXUserProfilePtr profile) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "UserListener onUserSignIn");
  touchwin(stdscr);
  refresh();
}

void UserListener::onUserSignOut(BMXErrorCode error) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "UserListener onUserSignOut");
  touchwin(stdscr);
  refresh();
}

void UserListener::onOtherDeviceSingIn(int deviceSN) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "UserListener onOtherDeviceSingIn");
  mvwaddstr(notifyWindow, 2, 1, std::to_string(deviceSN).c_str());
  touchwin(stdscr);
  refresh();
}

void UserListener::onOtherDeviceSingOut(int deviceSN) {
  draw_notify(notifyWindow);
  mvwaddstr(notifyWindow, 1, 1, "UserListener onOtherDeviceSingOut");
  mvwaddstr(notifyWindow, 2, 1, std::to_string(deviceSN).c_str());
  touchwin(stdscr);
  refresh();
}