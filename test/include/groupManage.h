//-------------------------------------------------------------------------------------------------
// File    : groupManage.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx group manage define file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __GROUP_LISTENER__
#define __GROUP_LISTENER__

#include "bmx_group_service_listener.h"
#include "bmx_client.h"
#include "bmx_group_service.h"
#include "bmx_error.h"

using namespace floo;
using namespace std;

class GroupListener : public BMXGroupServiceListener {
public:
  GroupListener() {}

  void onGroupCreate(BMXGroupPtr group) {}

  void onGroupListUpdate(const BMXGroupList& list)  {}

  void onGroupJoined(BMXGroupPtr group);

  void onGroupLeft(BMXGroupPtr group, const std::string& reason);

  void onInvitated(int64_t groupId, int64_t inviter, const std::string& message)  {}

  void onInvitationAccepted(BMXGroupPtr group, int64_t inviteeId)  {}

  void onInvitationDeclined(BMXGroupPtr group, int64_t inviteeId, const std::string& reason)  {}

  void onApplied(BMXGroupPtr group, int64_t applicantId, const std::string& message)  {}

  void onApplicationAccepted(BMXGroupPtr group, int64_t approver);

  void onApplicationDeclined(BMXGroupPtr group, int64_t approver, const std::string& reason);

  void onMembersBanned(BMXGroupPtr group, const std::vector<int64_t>& members, int64_t duration)  {}

  void onMembersUnbanned(BMXGroupPtr group, const std::vector<int64_t>& members)  {}

  void onMemberJoined(BMXGroupPtr group, int64_t memberId, int64_t inviter)  {}

  void onMemberLeft(BMXGroupPtr group, int64_t memberId, const std::string& reason)  {}

  void onAdminsAdded(BMXGroupPtr group, const std::vector<int64_t>& members)  {}

  void onAdminsRemoved(BMXGroupPtr group, const std::vector<int64_t>& members, const std::string& reason)  {}

  void onOwnerAssigned(BMXGroupPtr group)  {}

  void onGroupInfoUpdate(BMXGroupPtr group, BMXGroup::UpdateInfoType type) {}

  void onMemberChangeNickName(BMXGroupPtr group, int64_t memberId, const std::string& nickName) {}

  void onAnnouncementUpdate(BMXGroupPtr group, BMXGroup::AnnouncementPtr announcement) {}

  void onSharedFileUploaded(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile) {}

  void onSharedFileDeleted(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile) {}

  void onSharedFileUpdated(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile) {}

  void onBlockListAdded(BMXGroupPtr group, const std::vector<int64_t>& members) {}

  void onBlockListRemoved(BMXGroupPtr group, const std::vector<int64_t>& members) {}

  void onGroupListUpdate() {}

  void setClient(BMXClientPtr client);

public:
  BMXClientPtr mClient;
};

#endif