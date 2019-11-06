//-------------------------------------------------------------------------------------------------
// File    : userManage.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx user manage define file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __USER_LISTENER__
#define __USER_LISTENER__

#include "bmx_user_service_listener.h"
#include "bmx_client.h"
#include "bmx_user_service.h"
#include "bmx_error.h"

using namespace floo;
using namespace std;

class UserListener : public BMXUserServiceListener {
public:
  UserListener() {}

  void onConnectStatusChanged(BMXConnectStatus status);

  void onUserSignIn(BMXUserProfilePtr profile);

  void onUserSignOut(BMXErrorCode error);

  void onInfoUpdated(BMXUserProfilePtr profile) {}

  void onOtherDeviceSingIn(int deviceSN);

  void onOtherDeviceSingOut(int deviceSN);

  void setClient(BMXClientPtr client);

public:
  BMXClientPtr mClient;
};

#endif