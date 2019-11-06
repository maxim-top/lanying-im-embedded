//-------------------------------------------------------------------------------------------------
// File    : chat.cc
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx chat manage implementation file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#include "chatManage.h"
#include "bmx_cursor.h"

using namespace std;

void ChatListener::onStatusChanged(BMXMessagePtr msg, BMXErrorCode error) {
  mvwaddstr(notifyWindow, 1, 1, "ChatListener onStatusChanged message");
  mvwaddstr(notifyWindow, 2, 1, std::to_string(msg->msgId()).c_str());
  char* status = "unkonw status";
  switch (msg->deliveryStatus()) {
    case BMXMessage::DeliveryStatus::New:
      status = "New";
      break;
    case BMXMessage::DeliveryStatus::Delivering:
      status = "Delivering";
      break;
    case BMXMessage::DeliveryStatus::Deliveried:
      status = "Deliveried";
      showConversation(); //发送成功展示消息 （仅展示maximtest1 和 maximtest2的对话）
      break;
    case BMXMessage::DeliveryStatus::Failed:
      status = "Failed";
      break;
    case BMXMessage::DeliveryStatus::Recalled:
      status = "Recalled";
      break;
    default:
      break;
  }
  mvwaddstr(notifyWindow, 3, 1, status);
  mvwaddstr(notifyWindow, 4, 1, msg->content().c_str());
  touchwin(stdscr);
  refresh();
}

void ChatListener::onReceive(const BMXMessageList& list) {
  for (auto msg : list) {
    draw_notify(notifyWindow);
    mvwaddstr(notifyWindow, 1, 1, "ChatListener onReceive message");
    mvwaddstr(notifyWindow, 2, 1, msg->senderName().c_str());
    if (msg->extension().size()) {
      if (msg->extension().find("typing") != std::string::npos) {
        mvwaddstr(notifyWindow, 3, 1, "sender is typing");
      } else {
        mvwaddstr(notifyWindow, 3, 1, "sender is endtyping");
      }
    } else {
      mvwaddstr(notifyWindow, 3, 1, msg->content().c_str());
    }
  }
  showConversation(); //接收消息展示消息  （仅展示maximtest1 和 maximtest2的对话）
  touchwin(stdscr);
  refresh();
}

void ChatListener::onReceiveReadAcks(const BMXMessageList& list) {
  for (auto msg : list) {
    draw_notify(notifyWindow);
    mvwaddstr(notifyWindow, 1, 1, "ChatListener onReceiveReadAcks message");
    mvwaddstr(notifyWindow, 2, 1, std::to_string(msg->msgId()).c_str());
    mvwaddstr(notifyWindow, 3, 1, msg->content().c_str());
  }
  touchwin(stdscr);
  refresh();
}

void ChatListener::setClient(BMXClientPtr client) {
  mClient = client;
}
  /*
  BMXErrorCode errorCode = client->getUserService().signInByName("jwfan", "1");
  cout << static_cast<int>(errorCode) << endl;

  BMXMessagePtr msg = BMXMessage::createMessage(66112, 131712, (BMXMessage::MessageType)0, 131712, "test00001");
  msg->setSenderName("jwfan");
  client->getChatService().sendMessage(msg);
  printf("maxim embedded demo!!!!!!");

  ChatListener* listener = new ChatListener();
  listener->setClient(client);
  client->getChatService().addChatListener(listener);
  */