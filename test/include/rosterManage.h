//-------------------------------------------------------------------------------------------------
// File    : rosterManage.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx roster manage define file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __ROSTER_LISTENER__
#define __ROSTER_LISTENER__

#include "bmx_roster_service_listener.h"
#include "bmx_client.h"
#include "bmx_roster_service.h"
#include "bmx_error.h"

using namespace floo;
using namespace std;

class RosterListener : public BMXRosterServiceListener {
public:
  RosterListener() {}

  void onFriendAdded(int64_t sponsorId, int64_t recipientId);

  void onFriendRemoved(int64_t sponsorId, int64_t recipientId);

  void onApplied(int64_t sponsorId, int64_t recipientId, const std::string& message);
  
  void onApplicationAccepted(int64_t sponsorId, int64_t recipientId) {}

  void onApplicationDeclined(int64_t sponsorId, int64_t recipientId, const std::string& reason) {}

  void onBlockListAdded(int64_t sponsorId, int64_t recipientId) {}

  void onBlockListRemoved(int64_t sponsorId, int64_t recipientId) {}

  void onRosterInfoUpdate(BMXRosterItemPtr item) {}

  void onRosterListUpdate() {}

  void setClient(BMXClientPtr client);

public:
  BMXClientPtr mClient;
};

#endif