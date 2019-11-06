//-------------------------------------------------------------------------------------------------
// File    : chat.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx chat manage define file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __CHAT_LISTENER__
#define __CHAT_LISTENER__

#include "bmx_chat_service_listener.h"
#include "bmx_client.h"
#include "bmx_chat_service.h"
#include "bmx_user_service.h"
#include "bmx_message.h"
#include "bmx_error.h"

using namespace floo;
using namespace std;

class ChatListener : public BMXChatServiceListener {
public:
  ChatListener() {}

  void onStatusChanged(BMXMessagePtr msg, BMXErrorCode error);

  void onAttachmentUploadProgressChanged(BMXMessagePtr msg, int percent)  {}

  void onRecallStatusChanged(BMXMessagePtr msg, BMXErrorCode error)  {}

  void onReceive(const BMXMessageList& list);

  void onReceiveSystemMessages(const BMXMessageList& list)  {}

  void onReceiveReadAcks(const BMXMessageList& list);

  void onReceiveDeliverAcks(const BMXMessageList& list)  {}

  void onReceiveRecallMessages(const BMXMessageList& list)  {}

  void onReceiveReadCancels(const BMXMessageList& list) {}

  void onReceiveReadAllMessages(const BMXMessageList& list) {}

  void onReceiveDeleteMessages(const BMXMessageList& list) {}

  void onAttachmentStatusChanged(BMXMessagePtr msg, BMXErrorCode error, int percent)  {}

  void onRetrieveHistoryMessages(BMXConversationPtr conversation) {}

  void onLoadAllConversation() {}

  void onConversationCreate(BMXConversationPtr conversation, BMXMessagePtr msg) {}

  void onConversationDelete(int64_t conversationId, BMXErrorCode error) {}

  void setClient(BMXClientPtr client);

public:
  BMXClientPtr mClient;
};

#endif