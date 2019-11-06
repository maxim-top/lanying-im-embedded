//-------------------------------------------------------------------------------------------------
// File    : cursor.cc
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx cursor implementation file.
// Created : 12 Sep 24 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#include "bmx_cursor.h"

void init_curses() {
  setlocale(LC_ALL, "");
  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  init_pair(3, COLOR_RED, COLOR_WHITE);
  init_pair(4, COLOR_BLACK, COLOR_WHITE);
  curs_set(0);
  cbreak();
  noecho();
  keypad(stdscr,TRUE);
  box(stdscr, ACS_VLINE, ACS_HLINE);
}

void draw_menubar(WINDOW *menubar) {
  wbkgd(menubar, COLOR_PAIR(2));

  waddstr(menubar, "Chat");
  wattron(menubar, COLOR_PAIR(3));
  waddstr(menubar, "(F1)");
  wattroff(menubar, COLOR_PAIR(3));

  wmove(menubar, 0, 10);
  waddstr(menubar, "User");
  wattron(menubar, COLOR_PAIR(3));
  waddstr(menubar, "(F2)");
  wattroff(menubar, COLOR_PAIR(3));

  wmove(menubar, 0, 20);
  waddstr(menubar, "Roster");
  wattron(menubar, COLOR_PAIR(3));
  waddstr(menubar, "(F3)");
  wattroff(menubar, COLOR_PAIR(3));

  wmove(menubar, 0, 30);
  waddstr(menubar, "Group");
  wattron(menubar, COLOR_PAIR(3));
  waddstr(menubar, "(F4)");
  wattroff(menubar, COLOR_PAIR(3));

  wmove(menubar, 0, 55);
  waddstr(menubar, "Conversation");
  wattron(menubar, COLOR_PAIR(3));
  waddstr(menubar, "(F5)");
  wattroff(menubar, COLOR_PAIR(3));
}

void draw_conversation(WINDOW *conversation) {
  werase(conversation);
  wbkgd(conversation, COLOR_PAIR(1));
  box(conversation, ACS_VLINE, ACS_HLINE);
}

void draw_notify(WINDOW* notify) {
  werase(notify);
  wbkgd(notify, COLOR_PAIR(1));
  box(notify, ACS_VLINE, ACS_HLINE);
}

void draw_operation(WINDOW* oper) {
  werase(oper);
  wbkgd(oper, COLOR_PAIR(1));
  box(oper, ACS_VLINE, ACS_HLINE);
}

void draw_input(WINDOW* in) {
  werase(in);
  wbkgd(in, COLOR_PAIR(1));
  box(in, ACS_VLINE, ACS_HLINE);
  wmove(in, 1, 1);
  wrefresh(in);
}

WINDOW **draw_menu(int start_col) {
  int i;
  WINDOW **items;
  items=(WINDOW **)malloc(9*sizeof(WINDOW *));

  items[0]=newwin(10,19,1,start_col);
  wbkgd(items[0],COLOR_PAIR(2));
  box(items[0],ACS_VLINE,ACS_HLINE);
  items[1] = subwin(items[0], 1, 17, 2, start_col + 1);
  items[2] = subwin(items[0], 1, 17, 3, start_col + 1);
  items[3] = subwin(items[0], 1, 17, 4, start_col + 1);
  items[4] = subwin(items[0], 1, 17, 5, start_col + 1);
  items[5] = subwin(items[0], 1, 17, 6, start_col + 1);
  items[6] = subwin(items[0], 1, 17, 7, start_col + 1);
  items[7] = subwin(items[0], 1, 17, 8, start_col + 1);
  items[8] = subwin(items[0], 1, 17, 9, start_col + 1);
  for (i = 1; i < 9; i++) {
    wprintw(items[i], "Item%d", i);
  }
  wbkgd(items[1], COLOR_PAIR(1));
  wrefresh(items[0]);
  return items;
}

void delete_menu(WINDOW **items,int count) {
  int i;
  for (i = count; i > 0; --i) {
    delwin(items[i]);
    items[i] = nullptr;
  }
  //free(items);
}

WINDOW **draw_chat_menu(int start_col) {
  WINDOW **items;
  items = (WINDOW **)malloc(CHAT_MENU_SIZE * sizeof(WINDOW *));
  items[0] = newwin(10, 19, 1, start_col);
  wbkgd(items[0], COLOR_PAIR(2));
  box(items[0], ACS_VLINE, ACS_HLINE);
  
  items[1] = subwin(items[0], 1, 17, 2, start_col + 1);
  items[2] = subwin(items[0], 1, 17, 3, start_col + 1);
  items[3] = subwin(items[0], 1, 17, 4, start_col + 1);

  wprintw(items[1], "SignIn");
  wprintw(items[2], "Signout");
  wprintw(items[3], "SendMessage");
  
  wbkgd(items[1], COLOR_PAIR(1));
  wrefresh(items[0]);
  return items;
}

WINDOW **draw_user_menu(int start_col) {
  WINDOW **items;
  items = (WINDOW **)malloc(USER_MENU_SIZE * sizeof(WINDOW *));
  items[0] = newwin(10, 19, 1, start_col);
  wbkgd(items[0], COLOR_PAIR(2));
  box(items[0], ACS_VLINE, ACS_HLINE);

  items[1] = subwin(items[0], 1, 17, 2, start_col + 1);
  items[2] = subwin(items[0], 1, 17, 3, start_col + 1);

  wprintw(items[1], "setNickname");
  wprintw(items[2], "setMobilePhone");

  wbkgd(items[1], COLOR_PAIR(1));
  wrefresh(items[0]);
  return items;
}

WINDOW **draw_roster_menu(int start_col) {
  WINDOW **items;
  items = (WINDOW **)malloc(ROSTER_MENU_SIZE * sizeof(WINDOW *));
  items[0] = newwin(10, 19, 1, start_col);
  wbkgd(items[0], COLOR_PAIR(2));
  box(items[0], ACS_VLINE, ACS_HLINE);

  items[1] = subwin(items[0], 1, 17, 2, start_col + 1);
  items[2] = subwin(items[0], 1, 17, 3, start_col + 1);
  items[3] = subwin(items[0], 1, 17, 4, start_col + 1);
  items[4] = subwin(items[0], 1, 17, 5, start_col + 1);

  wprintw(items[1], "apply");
  wprintw(items[2], "remove");
  wprintw(items[3], "accept");
  wprintw(items[4], "decline");
  
  wbkgd(items[1], COLOR_PAIR(1));
  wrefresh(items[0]);
  return items;
}

WINDOW **draw_group_menu(int start_col) {
  WINDOW **items;
  items = (WINDOW **)malloc(GROUP_MENU_SIZE * sizeof(WINDOW *));
  items[0] = newwin(10, 19, 1, start_col);
  wbkgd(items[0], COLOR_PAIR(2));
  box(items[0], ACS_VLINE, ACS_HLINE);

  items[1] = subwin(items[0], 1, 17, 2, start_col + 1);
  items[2] = subwin(items[0], 1, 17, 3, start_col + 1);
  items[3] = subwin(items[0], 1, 17, 4, start_col + 1);
  items[4] = subwin(items[0], 1, 17, 5, start_col + 1);

  wprintw(items[1], "setMyNickname");
  wprintw(items[2], "join");
  wprintw(items[3], "leave");
  wprintw(items[4], "search");
  
  wbkgd(items[1], COLOR_PAIR(1));
  wrefresh(items[0]);
  return items;
}

void initWindow() {
  init_curses();
  bkgd(COLOR_PAIR(1));

  menubar = subwin(stdscr, 1, 78, 1, 1);
  conversationWindow = subwin(stdscr, 18, 30, 2, 49);
  notifyWindow = subwin(stdscr, 7, 47, 2, 2);
  operWindow = subwin(stdscr, 11, 47, 9, 2);
  inputWindow = subwin(stdscr, 3, 78, 20, 1);

  draw_menubar(menubar);
  draw_conversation(conversationWindow);
  draw_notify(notifyWindow);
  draw_operation(operWindow);
  draw_input(inputWindow);

  refresh();
}

void deleteWindow() {
  delwin(menubar);
  delwin(conversationWindow);
  delwin(notifyWindow);
  delwin(operWindow);
  delwin(inputWindow);
  endwin();
}

void PressUpDown(WINDOW **items, int key, int count, int &selected) {
  wbkgd(items[selected + 1], COLOR_PAIR(2));
  wnoutrefresh(items[selected + 1]);
  if (key == KEY_DOWN) {
    selected = (selected + 1) % count;
  } else {
    selected = (selected + count - 1) % count;
  }
  wbkgd(items[selected + 1], COLOR_PAIR(1));
  wnoutrefresh(items[selected + 1]);
  doupdate();
}

void changeMenu(WINDOW **items, int type, int offset, int oldSize, int newSize) {
  delete_menu(items, oldSize);
  touchwin(stdscr);
  refresh();
  switch (type) {
    case 0: // chat
      items = draw_chat_menu(offset);
      scroll_chat_menu(items, newSize);
      break;
    case 1: // user
      items = draw_user_menu(offset);
      scroll_user_menu(items, newSize);
      break;
    case 2: // roster
      items = draw_roster_menu(offset);
      scroll_roster_menu(items, newSize);
      break;
    case 3: // group
      items = draw_group_menu(offset);
      scroll_group_menu(items, newSize);
      break;
    case 4: // conversation
      break;
    default:
      return;
  }
}

void scroll_chat_menu(WINDOW **items, int count) {
  int key;
  int selected = 0;
  while (1) {
    key = getch();
    if (key == KEY_DOWN || key == KEY_UP) {
      PressUpDown(items, key, count, selected);
    } else if (key == KEY_RIGHT) {
      changeMenu(items, 1, 10, count, USER_MENU_SIZE - 1);
      return;
    } else if (key == KEY_LEFT) {
      changeMenu(items, 3, 30, count, GROUP_MENU_SIZE - 1);
      return;
    } else if (key == ESCAPE) {
      return;
    } else if (key == ENTER) {      
      switch (selected) {
        case 0: //Login
        {
          operationType = OperationType::CLIENT_SIGN_IN;
          showOpeartionNotify();
          processOperation();
          return;
        }
        case 1: //Logout
        {
          operationType = OperationType::CLIENT_SIGN_OUT;
          showOpeartionNotify();
          processOperation();
          return;
        }
        case 2: //sendMessage
        {
          operationType = OperationType::CLIENT_SEND_MESSAGE;
          showOpeartionNotify();
          processOperation();
          return;
        }
        default:
          return;
      }
    }
  }
}

void scroll_user_menu(WINDOW **items, int count) {
  int key;
  int selected = 0;
  while (1) {
    key = getch();
    if (key == KEY_DOWN || key == KEY_UP) {
      PressUpDown(items, key, count, selected);
    } else if (key == KEY_LEFT) {
      changeMenu(items, 0, 0, count, CHAT_MENU_SIZE - 1);
      return;
    } else if (key == KEY_RIGHT) {
      changeMenu(items, 2, 20, count, ROSTER_MENU_SIZE - 1);
      return;
    } else if (key == ESCAPE) {
      return;
    } else if (key == ENTER) {
      switch (selected) {
        case 0: //setNickname
        {
          operationType = OperationType::USER_SET_NICK_NAME;
          showOpeartionNotify();
          processOperation();
          return;
        }
        case 1: //setMobilePhone
        {
          operationType = OperationType::USER_SET_MOBILE_PHONE;
          showOpeartionNotify();
          processOperation();
          return;
        }
        default:
          return;
      }
    }
  }
}

void scroll_roster_menu(WINDOW **items, int count) {
  int key;
  int selected = 0;
  while (1) {
    key = getch();
    if (key == KEY_DOWN || key == KEY_UP) {
      PressUpDown(items, key, count, selected);
    } else if (key == KEY_LEFT) {
      changeMenu(items, 1, 10, count, USER_MENU_SIZE - 1);
      return;
    } else if (key == KEY_RIGHT) {
      changeMenu(items, 3, 30, count, GROUP_MENU_SIZE - 1);
      return;
    } else if (key == ESCAPE) {
      return;
    } else if (key == ENTER) {
      switch (selected) {
        case 0:
        {
          operationType = OperationType::ROSTER_APPLY;
          showOpeartionNotify();
          processOperation();
          return;
        }
        case 1:
        {
          operationType = OperationType::ROSTER_REMOVE;
          showOpeartionNotify();
          processOperation();
          return;
        }
        case 2:
        {
          operationType = OperationType::ROSTER_ACCEPT;
          showOpeartionNotify();
          processOperation();
          return;
        }
        case 3:
        {
          operationType = OperationType::ROSTER_DECLINE;
          showOpeartionNotify();
          processOperation();
          return;
        }
        default:
          return;
      }
    }
  }
}

void scroll_group_menu(WINDOW **items, int count) {
  int key;
  int selected = 0;
  while (1) {
    key = getch();
    if (key == KEY_DOWN || key == KEY_UP) {
      PressUpDown(items, key, count, selected);
    } else if (key == KEY_LEFT) {
      changeMenu(items, 2, 20, count, ROSTER_MENU_SIZE - 1);
      return;
    } else if (key == KEY_RIGHT) {
      changeMenu(items, 0, 0, count, CHAT_MENU_SIZE - 1);
      return;
    } else if (key == ESCAPE) {
      return;
    } else if (key == ENTER) {
      switch (selected) {
        case 0: //setMyNickname
        {
          operationType = OperationType::GROUP_SET_MY_NICK_NAME;
          showOpeartionNotify();
          processOperation();
          return;
        }
        case 1: //join
        {
          operationType = OperationType::GROUP_JOIN;
          showOpeartionNotify();
          processOperation();
          return; 
        }
        case 2: //leave
        {
          operationType = OperationType::GROUP_LEAVE;
          showOpeartionNotify();
          processOperation();
          return;
        }
        case 3: //search
        {
          operationType = OperationType::GROUP_SEARCH;
          showOpeartionNotify();
          processOperation();
          return;
        }
        default:
          return;
      }
    }
  }
}

void register_listener() {
  client->getChatService().addChatListener(chatListener);
  client->getUserService().addUserListener(userListener);
  client->getRosterService().addRosterListener(rosterListener);
  client->getGroupService().addGroupListener(groupListener);
}

void unregister_listener() {
  client->getChatService().removeChatListener(chatListener);
  client->getUserService().removeUserListener(userListener);
  client->getRosterService().removeRosterListener(rosterListener);
  client->getGroupService().removeGroupListener(groupListener);
}

static bool compareConversation(BMXConversationPtr left, BMXConversationPtr right) {
  if (left->lastMsg() && right->lastMsg()) {
    return left->lastMsg()->serverTimestamp() > right->lastMsg()->serverTimestamp();
  } else if (left->lastMsg()) {
    return 1;
  } else {
    return -1;
  }
}

//（仅展示maximtest1 6597271134048 和 maximtest2 6597271134656 的对话）
void showConversation() {
  draw_conversation(conversationWindow);
  BMXConversationList conversationList = client->getChatService().getAllConversations();
  if (conversationList.size()) {
    std::sort(conversationList.begin(), conversationList.end(), compareConversation);
    BMXMessageList list;
    BMXErrorCode errorCode = client->getChatService().retrieveHistoryMessages(conversationList[0], 0, 10, list);
    if (errorCode == BMXErrorCode::NoError) {
      for (int i = 0; i < list.size(); i++) {
        if (list[i]->isReceiveMsg()) {
          wattron(conversationWindow, COLOR_PAIR(3));
          mvwaddstr(conversationWindow, 1 + i, 1, list[i]->content().c_str());
          wattroff(conversationWindow, COLOR_PAIR(3));
        } else {
          mvwaddstr(conversationWindow, 1 + i, 6, list[i]->content().c_str());
        }
      }
    }
  }
}

string trimWhiteSpace(const string& str) {
  string trimstr = str;
  if (str.empty()) {
    return trimstr;
  }

  trimstr.erase(0, trimstr.find_first_not_of(" \t\n\r\v"));
  trimstr.erase(trimstr.find_last_not_of(" \t\n\r\v") + 1);

  return trimstr;
}

void split(const string& str, const string& delim, vector<string> &ret) {
  if (str.empty()) {
    return;
  }

  ret.clear();
  if (delim.empty()) {
    ret.push_back(str);
    return;
  }

  size_t last = 0;
  size_t index = str.find_first_of(delim, last);
  while (index != string::npos) {
    ret.push_back(str.substr(last, index-last));
    last = index + 1;
    index = str.find_first_of(delim, last);
  }

  if (index-last > 0) {
    ret.push_back(str.substr(last, index-last));
  }
}

void showOpeartionNotify() {
  char* notify = nullptr;
  switch(operationType) {
    case CLIENT_SIGN_IN:
      notify = "input: username password";
      break;
    case CLIENT_SIGN_OUT:
      notify = "input: no params";
      break;
    case CLIENT_SEND_MESSAGE:
      notify = "input: conversationId type content\n type:0 signal, 1 group";
      break;
    case USER_SET_NICK_NAME:
      notify = "input: nickname";
      break;
    case USER_SET_MOBILE_PHONE:
      notify = "input: mobilephone";
      break;
    case ROSTER_APPLY:
      notify = "input: rosterId reason";
      break;
    case ROSTER_REMOVE:
      notify = "input: rosterId";
      break;
    case ROSTER_ACCEPT:
      notify = "input: rosterId";
      break;
    case ROSTER_DECLINE:
      notify = "input: rosterId reason";
      break;
    case GROUP_SET_MY_NICK_NAME:
      notify = "input: groupId myNickName";
      break;
    case GROUP_JOIN:
      notify = "input: groupId message";
      break;
    case GROUP_LEAVE:
      notify = "input: groupId";
      break;
    case GROUP_SEARCH:
      notify = "input: no params";
      break;
  }

  touchwin(stdscr);
  refresh();

  draw_operation(operWindow);
  mvwprintw(operWindow, 1, 1, notify);
  box(operWindow, ACS_VLINE, ACS_HLINE);
  wrefresh(operWindow);

  curs_set(1);

  draw_input(inputWindow);
  wrefresh(inputWindow);
}

void getParams(std::vector<std::string>& params) {
  char input[256] = { 0 };
  int i = 0;
  
  while( i != 256 && (input[i] = getch()) != ENTER) {
    i++;
    mvwprintw(inputWindow, 1, 1, input);
    wrefresh(inputWindow);
  }

  mvwprintw(operWindow, 1, 1, "%s", input);
  box(operWindow, ACS_VLINE, ACS_HLINE);
  wrefresh(operWindow);

  split(trimWhiteSpace(input), " ", params);
}

void processOperation() {
  std::vector<std::string> params;
  switch (operationType) {
    case CLIENT_SIGN_IN:
    {
      getParams(params);
      if (params.size() >= 2) {
        BMXErrorCode errorCode = client->signInByName(params[0], params[1]);
        if (BMXErrorCode::NoError == errorCode) {
          register_listener();
          mvwaddstr(operWindow, 1, 1, "SignIn success!");
        } else {
          mvwaddstr(operWindow, 1, 1, "SignIn failure!");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      }
      break;
    }
    case CLIENT_SIGN_OUT:
    {
      box(operWindow, ACS_VLINE, ACS_HLINE);
      wrefresh(operWindow);

      if (client->signInStatus() == BMXSignInStatus::SignIn) {
        BMXErrorCode errorCode = client->signOut();
        if (BMXErrorCode::NoError == errorCode) {
          unregister_listener();
          draw_notify(notifyWindow);
          draw_conversation(conversationWindow);
          mvwaddstr(operWindow, 1, 1, "Signout success");
        } else {
          mvwaddstr(operWindow, 1, 1, "Signout failure");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn!");
      }
      break;
    }
    case CLIENT_SEND_MESSAGE:
    {
      getParams(params);
      if (params.size() >= 3 && client->signInStatus() == BMXSignInStatus::SignIn) {
        BMXUserProfilePtr profile;
        uint64_t toId = std::stoull(params[0]);
        BMXMessage::MessageType type = (BMXMessage::MessageType)std::stoi(params[1]);
        BMXErrorCode errorCode = client->getUserService().getProfile(profile, false);
        if (profile.get() != nullptr) {
          BMXMessagePtr msg = BMXMessage::createMessage(profile->userId(), toId, (BMXMessage::MessageType)type, toId, params[2]);
          client->sendMessage(msg);
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case USER_SET_NICK_NAME:
    {
      getParams(params);
      if (params.size() >= 1 && client->signInStatus() == BMXSignInStatus::SignIn) {
        BMXErrorCode errorCode = client->getUserService().setNickname(params[0]);
        if (BMXErrorCode::NoError == errorCode) {
          mvwaddstr(operWindow, 1, 1, "setNickname success");
        } else {
          mvwaddstr(operWindow, 1, 1, "setNickname failure");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case USER_SET_MOBILE_PHONE:
    {
      getParams(params);
      if (params.size() >= 1 && client->signInStatus() == BMXSignInStatus::SignIn) {
        BMXErrorCode errorCode = client->getUserService().setMobilePhone(params[0]);
        if (BMXErrorCode::NoError == errorCode) {
          mvwaddstr(operWindow, 1, 1, "setMobilePhone success");
        } else {
          mvwaddstr(operWindow, 1, 1, "setMobilePhone failure");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case ROSTER_APPLY:
    {
      getParams(params);
      if (params.size() >= 2 && client->signInStatus() == BMXSignInStatus::SignIn) {
        uint64_t rosterId = std::stoull(params[0]);
        BMXErrorCode errorCode = client->getRosterService().apply(rosterId, params[1]);
        if (BMXErrorCode::NoError == errorCode) {
          mvwaddstr(operWindow, 1, 1, "apply success");
        } else {
          mvwaddstr(operWindow, 1, 1, "apply failure");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case ROSTER_REMOVE:
    {
      getParams(params);
      if (params.size() >= 1 && client->signInStatus() == BMXSignInStatus::SignIn) {
        uint64_t rosterId = std::stoull(params[0]);
        BMXErrorCode errorCode = client->getRosterService().remove(rosterId);
        if (BMXErrorCode::NoError == errorCode) {
          mvwaddstr(operWindow, 1, 1, "remove success");
        } else {
          mvwaddstr(operWindow, 1, 1, "remove failure");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case ROSTER_ACCEPT:
    {
      getParams(params);
      if (params.size() >= 1 && client->signInStatus() == BMXSignInStatus::SignIn) {
        uint64_t rosterId = std::stoull(params[0]);
        BMXErrorCode errorCode = client->getRosterService().accept(rosterId);
        if (BMXErrorCode::NoError == errorCode) {
          mvwaddstr(operWindow, 1, 1, "accept success");
        } else {
          mvwaddstr(operWindow, 1, 1, "accept failure");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case ROSTER_DECLINE:
    {
      getParams(params);
      if (params.size() >= 2 && client->signInStatus() == BMXSignInStatus::SignIn) {
        uint64_t rosterId = std::stoull(params[0]);
        BMXErrorCode errorCode = client->getRosterService().decline(rosterId, params[1]);
        if (BMXErrorCode::NoError == errorCode) {
          mvwaddstr(operWindow, 1, 1, "decline success");
        } else {
          mvwaddstr(operWindow, 1, 1, "decline failure");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case GROUP_SET_MY_NICK_NAME:
    {
      getParams(params);
      if (params.size() >= 2 && client->signInStatus() == BMXSignInStatus::SignIn) {
        uint64_t groupId = std::stoull(params[0]);
        BMXGroupPtr group;
        BMXErrorCode errorCode = client->getGroupService().search(groupId, group, false);
        if (BMXErrorCode::NoError == errorCode && group.get() != nullptr) {
          errorCode = client->getGroupService().setMyNickname(group, params[1]);
          if (BMXErrorCode::NoError == errorCode) {
            mvwaddstr(operWindow, 1, 1, "setMyNickname success");
          } else {
            mvwaddstr(operWindow, 1, 1, "setMyNickname failure");
            mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
          }
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case GROUP_JOIN:
    {
      getParams(params);
      if (params.size() >= 2 && client->signInStatus() == BMXSignInStatus::SignIn) {
        uint64_t groupId = std::stoull(params[0]);
        BMXGroupPtr group;
        BMXErrorCode errorCode = client->getGroupService().search(groupId, group, false);
        if (BMXErrorCode::NoError == errorCode && group.get() != nullptr) {
          errorCode = client->getGroupService().join(group, params[1]);
          if (BMXErrorCode::NoError == errorCode) {
            mvwaddstr(operWindow, 1, 1, "join success");
          } else {
            mvwaddstr(operWindow, 1, 1, "join failure");
            mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
          }
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case GROUP_LEAVE:
    {
      getParams(params);
      if (params.size() >= 1 && client->signInStatus() == BMXSignInStatus::SignIn) {
        uint64_t groupId = std::stoull(params[0]);
        BMXGroupPtr group;
        BMXErrorCode errorCode = client->getGroupService().search(groupId, group, false);
        if (BMXErrorCode::NoError == errorCode && group.get() != nullptr) {
          errorCode = client->getGroupService().leave(group);
          if (BMXErrorCode::NoError == errorCode) {
            mvwaddstr(operWindow, 1, 1, "join success");
          } else {
            mvwaddstr(operWindow, 1, 1, "join failure");
            mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
          }
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn or param invalid!");
      }
      break;
    }
    case GROUP_SEARCH:
    {
      box(operWindow, ACS_VLINE, ACS_HLINE);
      wrefresh(operWindow);

      if (client->signInStatus() == BMXSignInStatus::SignIn) {
        BMXGroupList list;
        BMXErrorCode errorCode = client->getGroupService().search(list, true);
        if (BMXErrorCode::NoError == errorCode) {
          int count = 1;
          if (list.size()) {
            for (auto group : list) {
              mvwaddstr(operWindow, count++, 1, std::to_string(group->groupId()).c_str());
            }
          } else {
            mvwaddstr(operWindow, 1, 1, "user has no group");
          }
        } else {
          mvwaddstr(operWindow, 1, 1, "search failure");
          mvwaddstr(operWindow, 2, 1, getErrorMessage(errorCode).c_str());
        }
      } else {
        mvwaddstr(operWindow, 1, 1, "user not signIn!");
      }
      
      break;
    }
    default:
      break;
  }

  curs_set(0);
}