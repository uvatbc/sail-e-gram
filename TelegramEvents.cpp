#include "TelegramEvents.h"

TelegramEvents::TelegramEvents(Telegram *t, QObject *parent)
: QObject(parent)
, m_telegram(t)
{
    //updates
    connect(m_telegram, SIGNAL(updatesTooLong()), this, SLOT(onUpdatesTooLong()));
    connect(m_telegram, SIGNAL(updateShortMessage(qint32,qint32,QString,qint32,qint32,qint32)), this, SLOT(onUpdateShortMessage(qint32,qint32,QString,qint32,qint32,qint32)));
    connect(m_telegram, SIGNAL(updateShortChatMessage(qint32,qint32,qint32,QString,qint32,qint32,qint32)), this, SLOT(onUpdateShortChatMessage(qint32,qint32,qint32,QString,qint32,qint32,qint32)));
    connect(m_telegram, SIGNAL(updateShort(Update,qint32)), this, SLOT(onUpdateShort(Update,qint32)));
    connect(m_telegram, SIGNAL(updatesCombined(QList<Update>,QList<User>,QList<Chat>,qint32,qint32,qint32)), this, SLOT(onUpdatesCombined(QList<Update>,QList<User>,QList<Chat>,qint32,qint32,qint32)));
    connect(m_telegram, SIGNAL(updates(QList<Update>,QList<User>,QList<Chat>,qint32,qint32)), this, SLOT(onUpdates(QList<Update>,QList<User>,QList<Chat>,qint32,qint32)));
    //errors
    connect(m_telegram, SIGNAL(error(qint64,qint32,QString)), this, SLOT(onError(qint64,qint32,QString)));
    connect(m_telegram, SIGNAL(authSignInError(qint64,qint32,QString)), this, SLOT(onAuthSignInError(qint64,qint32,QString)));
    connect(m_telegram, SIGNAL(authSignUpError(qint64,qint32,QString)), this, SLOT(onAuthSignUpError(qint64,qint32,QString)));
    //responses
    connect(m_telegram, SIGNAL(authNeeded()), this, SLOT(onAuthNeeded()));
    connect(m_telegram, SIGNAL(authCheckPhoneAnswer(qint64,bool,bool)), this, SLOT(onAuthCheckPhoneAnswer(qint64,bool,bool)));
    connect(m_telegram, SIGNAL(authSendCodeAnswer(qint64,bool,qint32)), this, SLOT(onAuthSendCodeAnswer(qint64,bool,qint32)));
    connect(m_telegram, SIGNAL(authSendCallAnswer(qint64,bool)), this, SLOT(onAuthSendCallAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(authLoggedIn()), this, SLOT(onAuthLoggedIn()));
    connect(m_telegram, SIGNAL(accountRegisterDeviceAnswer(qint64,bool)), this, SLOT(onAccountRegisterDeviceAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(accountUnregisterDeviceAnswer(qint64,bool)), this, SLOT(onAccountUnregisterDeviceAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(accountUpdateNotifySettingsAnswer(qint64,bool)), this, SLOT(onAccountUpdateNotifySettingsAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(accountGetNotifySettingsAnswer(qint64,PeerNotifySettings)), this, SLOT(onAccountGetNotifySettingsAnswer(qint64,PeerNotifySettings)));
    connect(m_telegram, SIGNAL(accountResetNotifySettingsAnswer(qint64,bool)), this, SLOT(onAccountResetNotifySettingsAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(accountUpdateProfileAnswer(qint64,User)), this, SLOT(onAccountUpdateProfileAnswer(qint64,User)));
    connect(m_telegram, SIGNAL(accountUpdateStatusAnswer(qint64,bool)), this, SLOT(onAccountUpdateStatusAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(accountGetWallPapersAnswer(qint64,QList<WallPaper>)), this, SLOT(onAccountGetWallPapersAnswer(qint64,QList<WallPaper>)));
    connect(m_telegram, SIGNAL(photosUploadProfilePhotoAnswer(qint64,Photo,QList<User>)), this, SLOT(onPhotosUploadProfilePhotoAnswer(qint64,Photo,QList<User>)));
    connect(m_telegram, SIGNAL(photosUpdateProfilePhotoAnswer(qint64,UserProfilePhoto)), this, SLOT(onPhotosUpdateProfilePhotoAnswer(qint64,UserProfilePhoto)));
    connect(m_telegram, SIGNAL(contactsGetStatusesAnswer(qint64,QList<ContactStatus>)), this, SLOT(onContactsGetStatusesAnswer(qint64,QList<ContactStatus>)));
    connect(m_telegram, SIGNAL(contactsGetContactsAnswer(qint64,bool,QList<Contact>,QList<User>)), this, SLOT(onContactsGetContactsAnswer(qint64,bool,QList<Contact>,QList<User>)));
    connect(m_telegram, SIGNAL(contactsImportContactsAnswer(qint64,QList<ImportedContact>,QList<qint64>,QList<User>)), this, SLOT(onContactsImportContactsAnswer(qint64,QList<ImportedContact>,QList<qint64>,QList<User>)));
    connect(m_telegram, SIGNAL(contactsDeleteContactAnswer(qint64,ContactsMyLink,ContactsForeignLink,User)), this, SLOT(onContactsDeleteContactAnswer(qint64,ContactsMyLink,ContactsForeignLink,User)));
    connect(m_telegram, SIGNAL(contactsDeleteContactsAnswer(qint64,bool)), this, SLOT(onContactsDeleteContactsAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(contactsBlockAnswer(qint64,bool)), this, SLOT(onContactsBlockAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(contactsUnblockAnswer(qint64,bool)), this, SLOT(onContactsUnblockAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(contactsGetBlockedAnswer(qint64,qint32,QList<ContactBlocked>,QList<User>)), this, SLOT(onContactsGetBlockedAnswer(qint64,qint32,QList<ContactBlocked>,QList<User>)));
    connect(m_telegram, SIGNAL(usersGetUsersAnswer(qint64,QList<User>)), this, SLOT(onUsersGetUsersAnswer(qint64,QList<User>)));
    connect(m_telegram, SIGNAL(usersGetFullUserAnswer(qint64,User,ContactsLink,Photo,PeerNotifySettings,bool,QString,QString)), this, SLOT(onUsersGetFullUserAnswer(qint64,User,ContactsLink,Photo,PeerNotifySettings,bool,QString,QString)));
    connect(m_telegram, SIGNAL(photosGetUserPhotosAnswer(qint64,qint32,QList<Photo>,QList<User>)), this, SLOT(onPhotosGetUserPhotosAnswer(qint64,qint32,QList<Photo>,QList<User>)));
    connect(m_telegram, SIGNAL(messagesSendMessageAnswer(qint64,qint32,qint32,qint32,qint32,QList<ContactsLink>)), this, SLOT(onMessagesSendMessageAnswer(qint64,qint32,qint32,qint32,qint32,QList<ContactsLink>)));
    connect(m_telegram, SIGNAL(messagesSendPhotoAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesSendPhotoAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesSendVideoAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesSendVideoAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesSendGeoPointAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesSendGeoPointAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesSendContactAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesSendContactAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesSendDocumentAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesSendDocumentAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesSendAudioAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesSendAudioAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesSetTypingAnswer(qint64,bool)), this, SLOT(onMessagesSetTypingAnswer(qint64,bool)));
    connect(m_telegram, SIGNAL(messagesGetMessagesAnswer(qint64,qint32,QList<Message>,QList<Chat>,QList<User>)), this, SLOT(onMessagesGetMessagesAnswer(qint64,qint32,QList<Message>,QList<Chat>,QList<User>)));
    connect(m_telegram, SIGNAL(messagesGetDialogsAnswer(qint64,qint32,QList<Dialog>,QList<Message>,QList<Chat>,QList<User>)), this, SLOT(onMessagesGetDialogsAnswer(qint64,qint32,QList<Dialog>,QList<Message>,QList<Chat>,QList<User>)));
    connect(m_telegram, SIGNAL(messagesGetHistoryAnswer(qint64,qint32,QList<Message>,QList<Chat>,QList<User>)), this, SLOT(onMessagesGetHistoryAnswer(qint64,qint32,QList<Message>,QList<Chat>,QList<User>)));
    connect(m_telegram, SIGNAL(messagesSearchAnswer(qint64,qint32,QList<Message>,QList<Chat>,QList<User>)), this, SLOT(onMessagesSearchAnswer(qint64,qint32,QList<Message>,QList<Chat>,QList<User>)));
    connect(m_telegram, SIGNAL(messagesReadHistoryAnswer(qint64,qint32,qint32,qint32)), this, SLOT(onMessagesReadHistoryAnswer(qint64,qint32,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesDeleteHistoryAnswer(qint64,qint32,qint32,qint32)), this, SLOT(onMessagesDeleteHistoryAnswer(qint64,qint32,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesDeleteMessagesAnswer(qint64,QList<qint32>)), this, SLOT(onMessagesDeleteMessagesAnswer(qint64,QList<qint32>)));
    connect(m_telegram, SIGNAL(messagesRestoreMessagesAnswer(qint64,QList<qint32>)), this, SLOT(onMessagesRestoreMessagesAnswer(qint64,QList<qint32>)));
    connect(m_telegram, SIGNAL(messagesReceivedMessagesAnswer(qint64,QList<qint32>)), this, SLOT(onMessagesReceivedMessagesAnswer(qint64,QList<qint32>)));
    connect(m_telegram, SIGNAL(messagesForwardMessageAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesForwardMessageAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesForwardMessagesAnswer(qint64,QList<Message>,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesForwardMessagesAnswer(qint64,QList<Message>,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesSendBroadcastAnswer(qint64,QList<Message>,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesSendBroadcastAnswer(qint64,QList<Message>,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesGetChatsAnswer(qint64,QList<Chat>,QList<User>)), this, SLOT(onMessagesGetChatsAnswer(qint64,QList<Chat>,QList<User>)));
    connect(m_telegram, SIGNAL(messagesGetFullChatAnswer(qint64,ChatFull,QList<Chat>,QList<User>)), this, SLOT(onMessagesGetFullChatAnswer(qint64,ChatFull,QList<Chat>,QList<User>)));
    connect(m_telegram, SIGNAL(messagesEditChatTitleAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesEditChatTitleAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesEditChatPhotoAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesEditChatPhotoAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesAddChatUserAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesAddChatUserAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesDeleteChatUserAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesDeleteChatUserAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(messagesCreateChatAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)), this, SLOT(onMessagesCreateChatAnswer(qint64,Message,QList<Chat>,QList<User>,QList<ContactsLink>,qint32,qint32)));
    connect(m_telegram, SIGNAL(updatesGetStateAnswer(qint64,qint32,qint32,qint32,qint32,qint32)), this, SLOT(onUpdatesGetStateAnswer(qint64,qint32,qint32,qint32,qint32,qint32)));
    connect(m_telegram, SIGNAL(updatesGetDifferenceAnswer(qint64,qint32,qint32)), this, SLOT(onUpdatesGetDifferenceAnswer(qint64,qint32,qint32)));
    connect(m_telegram, SIGNAL(updatesGetDifferenceAnswer(qint64,QList<Message>,QList<EncryptedMessage>,QList<Update>,QList<Chat>,QList<User>,UpdatesState,bool)), this, SLOT(onUpdatesGetDifferenceAnswer(qint64,QList<Message>,QList<EncryptedMessage>,QList<Update>,QList<Chat>,QList<User>,UpdatesState,bool)));
    connect(m_telegram, SIGNAL(uploadGetFileAnswer(qint64,StorageFileType,qint32,QByteArray,qint32,qint32,qint32)), this, SLOT(onUploadGetFileAnswer(qint64,StorageFileType,qint32,QByteArray,qint32,qint32,qint32)));

    // Start telegram init!
    m_telegram->init();
}//TelegramEvents::TelegramEvents

// Errors
void
TelegramEvents::onError(qint64 id,
                        qint32 errorCode,
                        QString errorText)
{
    qWarning() << "id = " << id
               << ", errorCode = " << errorCode
               << ", errorText = " << errorText;
}//TelegramEvents::onError

void
TelegramEvents::onAuthSignInError(qint64 id,
                                  qint32 errorCode,
                                  QString errorText)
{
    qWarning() << "id = " << id
               << ", errorCode = " << errorCode
               << ", errorText = " << errorText;
}//TelegramEvents::onAuthSignInError

void
TelegramEvents::onAuthSignUpError(qint64 id,
                                  qint32 errorCode,
                                  QString errorText)
{
    qWarning() << "id = " << id
               << ", errorCode = " << errorCode
               << ", errorText = " << errorText;
}//TelegramEvents::onAuthSignUpError

// Registration / authorization
void
TelegramEvents::onAuthNeeded()
{
    qDebug() << "authNeeded";
    m_telegram->authCheckPhone();
}//TelegramEvents::onAuthNeeded

void
TelegramEvents::onAuthLoggedIn()
{
    qDebug() << "authLoggedIn";
}//TelegramEvents::onAuthLoggedIn

void
TelegramEvents::onAuthCheckPhoneAnswer(qint64 id,
                                       bool phoneRegistered,
                                       bool phoneInvited)
{
}//TelegramEvents::onAuthCheckPhoneAnswer

void
TelegramEvents::onAuthCheckPhoneSent(qint64 msgId,
                                     QString phoneNumber)
{
}//TelegramEvents::onAuthCheckPhoneSent

void
TelegramEvents::onAuthSendCodeAnswer(qint64 id,
                                     bool phoneRegistered,
                                     qint32 sendCallTimeout)
{
}//TelegramEvents::onAuthSendCodeAnswer

void
TelegramEvents::onAuthSendSmsAnswer(qint64 id,
                                    bool ok)
{
}//TelegramEvents::onAuthSendSmsAnswer

void
TelegramEvents::onAuthSendCallAnswer(qint64 id,
                                     bool ok)
{
}//TelegramEvents::onAuthSendCallAnswer

void
TelegramEvents::onAuthLogOutAnswer(qint64 id,
                                   bool ok)
{
}//TelegramEvents::onAuthLogOutAnswer

void
TelegramEvents::onAuthSendInvitesAnswer(qint64 id,
                                        bool ok)
{
}//TelegramEvents::onAuthSendInvitesAnswer

void
TelegramEvents::onAuthResetAuthorizationsAnswer(qint64 id,
                                                bool ok)
{
}//TelegramEvents::onAuthResetAuthorizationsAnswer

// Working with Notifications. Settings
void
TelegramEvents::onAccountRegisterDeviceAnswer(qint64 id,
                                              bool ok)
{
}//TelegramEvents::onAccountRegisterDeviceAnswer

void
TelegramEvents::onAccountUnregisterDeviceAnswer(qint64 id,
                                                bool ok)
{
}//TelegramEvents::onAccountUnregisterDeviceAnswer

void
TelegramEvents::onAccountUpdateNotifySettingsAnswer(qint64 id,
                                                    bool ok)
{
}//TelegramEvents::onAccountUpdateNotifySettingsAnswer

void
TelegramEvents::onAccountGetNotifySettingsAnswer(qint64 id,
                                                 PeerNotifySettings peerNotifySettings)
{
}//TelegramEvents::onAccountGetNotifySettingsAnswer

void
TelegramEvents::onAccountResetNotifySettingsAnswer(qint64 id,
                                                   bool ok)
{
}//TelegramEvents::onAccountResetNotifySettingsAnswer

void
TelegramEvents::onAccountUpdateProfileAnswer(qint64 id,
                                             User user)
{
}//TelegramEvents::onAccountUpdateProfileAnswer

void
TelegramEvents::onAccountUpdateStatusAnswer(qint64 id,
                                            bool ok)
{
}//TelegramEvents::onAccountUpdateStatusAnswer

void
TelegramEvents::onAccountGetWallPapersAnswer(qint64 id,
                                             QList<WallPaper> wallPapers)
{
}//TelegramEvents::onAccountGetWallPapersAnswer

void
TelegramEvents::onPhotosUploadProfilePhotoAnswer(qint64 id,
                                                 Photo photo,
                                                 QList<User> users)
{
}//TelegramEvents::onPhotosUploadProfilePhotoAnswer

void
TelegramEvents::onPhotosUpdateProfilePhotoAnswer(qint64 id,
                                                 UserProfilePhoto userProfilePhoto)
{
}//TelegramEvents::onPhotosUpdateProfilePhotoAnswer

// Working with users
void
TelegramEvents::onUsersGetUsersAnswer(qint64 id,
                                      QList<User> users)
{
}//TelegramEvents::onUsersGetUsersAnswer

void
TelegramEvents::onUsersGetFullUserAnswer(qint64 id,
                                         User user,
                                         ContactsLink link,
                                         Photo profilePhoto,
                                         PeerNotifySettings notifySettings,
                                         bool blocked,
                                         QString realFirstName,
                                         QString realLastName)
{
}//TelegramEvents::onUsersGetFullUserAnswer

void
TelegramEvents::onPhotosGetUserPhotosAnswer(qint64 id,
                                            qint32 sliceCount,
                                            QList<Photo> photos,
                                            QList<User> users)
{
}//TelegramEvents::onPhotosGetUserPhotosAnswer

// Working with contacts
void
TelegramEvents::onContactsGetStatusesAnswer(qint64 id,
                                            QList<ContactStatus> statuses)
{
}//TelegramEvents::onContactsGetStatusesAnswer

void
TelegramEvents::onContactsGetContactsAnswer(qint64 id,
                                            bool modified,
                                            QList<Contact> contacts,
                                            QList<User> users)
{
}//TelegramEvents::onContactsGetContactsAnswer

void
TelegramEvents::onContactsImportContactsAnswer(qint64 id,
                                               QList<ImportedContact> importedContacts,
                                               QList<qint64> retryContacts,
                                               QList<User> users)
{
}//TelegramEvents::onContactsImportContactsAnswer

void
TelegramEvents::onContactsDeleteContactAnswer(qint64 id,
                                              ContactsMyLink myLink,
                                              ContactsForeignLink foreignLink,
                                              User user)
{
}//TelegramEvents::onContactsDeleteContactAnswer

void
TelegramEvents::onContactsDeleteContactsAnswer(qint64 id,
                                               bool ok)
{
}//TelegramEvents::onContactsDeleteContactsAnswer

// Working with blacklist
void
TelegramEvents::onContactsBlockAnswer(qint64 id,
                                      bool ok)
{
}//TelegramEvents::onContactsBlockAnswer

void
TelegramEvents::onContactsUnblockAnswer(qint64 id,
                                        bool ok)
{
}//TelegramEvents::onContactsUnblockAnswer

void
TelegramEvents::onContactsBlockResult(qint64 id,
                                      bool ok)
{
}//TelegramEvents::onContactsBlockResult

void
TelegramEvents::onContactsGetBlockedAnswer(qint64 id,
                                           qint32 sliceCount,
                                           QList<ContactBlocked> blocked,
                                           QList<User> users)
{
}//TelegramEvents::onContactsGetBlockedAnswer

// Working with messages
void
TelegramEvents::onMessagesSendMessageAnswer(qint64 id,
                                            qint32 msgId,
                                            qint32 date,
                                            qint32 pts,
                                            qint32 seq,
                                            QList<ContactsLink> links)
{
}//TelegramEvents::onMessagesSendMessageAnswer

void
TelegramEvents::onMessagesSendMediaAnswer(qint64 id,
                                          Message message,
                                          QList<Chat> chats,
                                          QList<User> users,
                                          QList<ContactsLink> links,
                                          qint32 pts,
                                          qint32 seq)
{
}//TelegramEvents::onMessagesSendMediaAnswer

void
TelegramEvents::onMessagesSendPhotoAnswer(qint64 id,
                                          Message message,
                                          QList<Chat> chats,
                                          QList<User> users,
                                          QList<ContactsLink> links,
                                          qint32 pts,
                                          qint32 seq)
{
}//TelegramEvents::onMessagesSendPhotoAnswer

void
TelegramEvents::onMessagesSendGeoPointAnswer(qint64 id,
                                             Message message,
                                             QList<Chat> chats,
                                             QList<User> users,
                                             QList<ContactsLink> links,
                                             qint32 pts,
                                             qint32 seq)
{
}//TelegramEvents::onMessagesSendGeoPointAnswer

void
TelegramEvents::onMessagesSendContactAnswer(qint64 id,
                                            Message message,
                                            QList<Chat> chats,
                                            QList<User> users,
                                            QList<ContactsLink> links,
                                            qint32 pts,
                                            qint32 seq)
{
}//TelegramEvents::onMessagesSendContactAnswer

void
TelegramEvents::onMessagesSendVideoAnswer(qint64 id,
                                          Message message,
                                          QList<Chat> chats,
                                          QList<User> users,
                                          QList<ContactsLink> links,
                                          qint32 pts,
                                          qint32 seq)
{
}//TelegramEvents::onMessagesSendVideoAnswer

void
TelegramEvents::onMessagesSendAudioAnswer(qint64 id,
                                          Message message,
                                          QList<Chat> chats,
                                          QList<User> users,
                                          QList<ContactsLink> links,
                                          qint32 pts,
                                          qint32 seq)
{
}//TelegramEvents::onMessagesSendAudioAnswer

void
TelegramEvents::onMessagesSendDocumentAnswer(qint64 id,
                                             Message message,
                                             QList<Chat> chats,
                                             QList<User> users,
                                             QList<ContactsLink> links,
                                             qint32 pts,
                                             qint32 seq)
{
}//TelegramEvents::onMessagesSendDocumentAnswer

void
TelegramEvents::onMessagesSetTypingAnswer(qint64 id,
                                          bool ok)
{
}//TelegramEvents::onMessagesSetTypingAnswer

void
TelegramEvents::onMessagesGetMessagesAnswer(qint64 id,
                                            qint32 sliceCount,
                                            QList<Message> messages,
                                            QList<Chat> chats,
                                            QList<User> users)
{
}//TelegramEvents::onMessagesGetMessagesAnswer

void
TelegramEvents::onMessagesGetDialogsAnswer(qint64 id,
                                           qint32 sliceCount,
                                           QList<Dialog> dialogs,
                                           QList<Message> messages,
                                           QList<Chat> chats,
                                           QList<User> users)
{
}//TelegramEvents::onMessagesGetDialogsAnswer

void
TelegramEvents::onMessagesGetHistoryAnswer(qint64 id,
                                           qint32 sliceCount,
                                           QList<Message> messages,
                                           QList<Chat> chats,
                                           QList<User> users)
{
}//TelegramEvents::onMessagesGetHistoryAnswer

void
TelegramEvents::onMessagesSearchAnswer(qint64 id,
                                       qint32 sliceCount,
                                       QList<Message> messages,
                                       QList<Chat> chats,
                                       QList<User> users)
{
}//TelegramEvents::onMessagesSearchAnswer

void
TelegramEvents::onMessagesReadHistoryAnswer(qint64 id,
                                            qint32 pts,
                                            qint32 seq,
                                            qint32 offset)
{
}//TelegramEvents::onMessagesReadHistoryAnswer

void
TelegramEvents::onMessagesDeleteHistoryAnswer(qint64 id,
                                              qint32 pts,
                                              qint32 seq,
                                              qint32 offset)
{
}//TelegramEvents::onMessagesDeleteHistoryAnswer

void
TelegramEvents::onMessagesReadMessageContentsAnswer(qint64 msgId,
                                                    QList<qint32> watchedIds)
{
}//TelegramEvents::onMessagesReadMessageContentsAnswer

void
TelegramEvents::onMessagesDeleteMessagesAnswer(qint64 id,
                                               QList<qint32> deletedMsgIds)
{
}//TelegramEvents::onMessagesDeleteMessagesAnswer

void
TelegramEvents::onMessagesRestoreMessagesAnswer(qint64 id,
                                                QList<qint32> restoredMsgIds)
{
}//TelegramEvents::onMessagesRestoreMessagesAnswer

void
TelegramEvents::onMessagesReceivedMessagesAnswer(qint64 id,
                                                 QList<qint32> confirmedMsgIds)
{
}//TelegramEvents::onMessagesReceivedMessagesAnswer

void
TelegramEvents::onMessagesForwardMessageAnswer(qint64 id,
                                               Message message,
                                               QList<Chat> chats,
                                               QList<User> users,
                                               QList<ContactsLink> links,
                                               qint32 pts,
                                               qint32 seq)
{
}//TelegramEvents::onMessagesForwardMessageAnswer

void
TelegramEvents::onMessagesForwardMessagesAnswer(qint64 id,
                                                QList<Message> messages,
                                                QList<Chat> chats,
                                                QList<User> users,
                                                QList<ContactsLink> links,
                                                qint32 pts,
                                                qint32 seq)
{
}//TelegramEvents::onMessagesForwardMessagesAnswer

void
TelegramEvents::onMessagesSendBroadcastAnswer(qint64 id,
                                              QList<Message> messages,
                                              QList<Chat> chats,
                                              QList<User> users,
                                              QList<ContactsLink> links,
                                              qint32 pts,
                                              qint32 seq)
{
}//TelegramEvents::onMessagesSendBroadcastAnswer

// Working with chats
void
TelegramEvents::onMessagesGetChatsAnswer(qint64 id,
                                         QList<Chat> chats,
                                         QList<User> users)
{
}//TelegramEvents::onMessagesGetChatsAnswer

void
TelegramEvents::onMessagesGetFullChatAnswer(qint64 id,
                                            ChatFull chatFull,
                                            QList<Chat> chats,
                                            QList<User> users)
{
}//TelegramEvents::onMessagesGetFullChatAnswer

void
TelegramEvents::onMessagesEditChatTitleAnswer(qint64 id,
                                              Message message,
                                              QList<Chat> chats,
                                              QList<User> users,
                                              QList<ContactsLink> links,
                                              qint32 pts,
                                              qint32 seq)
{
}//TelegramEvents::onMessagesEditChatTitleAnswer

void
TelegramEvents::onMessagesEditChatPhotoAnswer(qint64 id,
                                              Message message,
                                              QList<Chat> chats,
                                              QList<User> users,
                                              QList<ContactsLink> links,
                                              qint32 pts,
                                              qint32 seq)
{
}//TelegramEvents::onMessagesEditChatPhotoAnswer

void
TelegramEvents::onMessagesAddChatUserAnswer(qint64 id,
                                            Message message,
                                            QList<Chat> chats,
                                            QList<User> users,
                                            QList<ContactsLink> links,
                                            qint32 pts,
                                            qint32 seq)
{
}//TelegramEvents::onMessagesAddChatUserAnswer

void
TelegramEvents::onMessagesDeleteChatUserAnswer(qint64 id,
                                               Message message,
                                               QList<Chat> chats,
                                               QList<User> users,
                                               QList<ContactsLink> links,
                                               qint32 pts,
                                               qint32 seq)
{
}//TelegramEvents::onMessagesDeleteChatUserAnswer

void
TelegramEvents::onMessagesCreateChatAnswer(qint64 id,
                                           Message message,
                                           QList<Chat> chats,
                                           QList<User> users,
                                           QList<ContactsLink> links,
                                           qint32 pts,
                                           qint32 seq)
{
}//TelegramEvents::onMessagesCreateChatAnswer

// Working with secret chats
void
TelegramEvents::onMessagesCreateEncryptedChatAnswer(qint32 chatId,
                                                    qint32 date,
                                                    qint32 peerId,
                                                    qint64 accessHash)
{
}//TelegramEvents::onMessagesCreateEncryptedChatAnswer

void
TelegramEvents::onMessagesEncryptedChatRequested(qint32 chatId,
                                                 qint32 date,
                                                 qint32 peerId,
                                                 qint64 accessHash)
{
}//TelegramEvents::onMessagesEncryptedChatRequested

void
TelegramEvents::onMessagesEncryptedChatCreated(qint32 chatId,
                                               qint32 date,
                                               qint32 peerId,
                                               qint64 accessHash)
{
}//TelegramEvents::onMessagesEncryptedChatCreated

void
TelegramEvents::onMessagesEncryptedChatDiscarded(qint32 chatId)
{
}//TelegramEvents::onMessagesEncryptedChatDiscarded

void
TelegramEvents::onMessagesSetEncryptedTypingAnswer(qint64 id,
                                                   bool ok)
{
}//TelegramEvents::onMessagesSetEncryptedTypingAnswer

void
TelegramEvents::onMessagesReadEncryptedHistoryAnswer(qint64 id,
                                                     bool ok)
{
}//TelegramEvents::onMessagesReadEncryptedHistoryAnswer

void
TelegramEvents::onMessagesSendEncryptedAnswer(qint64 id,
                                              qint32 date,
                                              EncryptedFile encryptedFile
                                              /* = EncryptedFile()*/)
{
}//TelegramEvents::onMessagesSendEncryptedAnswer

void
TelegramEvents::onMessagesSendEncryptedFileAnswer(qint64 id,
                                                  qint32 date,
                                                  EncryptedFile encryptedFile
                                                  /* = EncryptedFile()*/)
{
}//TelegramEvents::onMessagesSendEncryptedFileAnswer

void
TelegramEvents::onMessagesSendEncryptedServiceAnswer(qint64 id,
                                                     qint32 date,
                                                     EncryptedFile encryptedFile
                                                     /* = EncryptedFile()*/)
{
}//TelegramEvents::onMessagesSendEncryptedServiceAnswer

void
TelegramEvents::onMessagesReceivedQueueAnwer(qint64 id,
                                             QList<qint64> msgIds)
{
}//TelegramEvents::onMessagesReceivedQueueAnwer


// Working with geochats
void
TelegramEvents::onGeochatsGetLocatedAnswer(qint64 id,
                                           QList<ChatLocated> results,
                                           QList<GeoChatMessage> messages,
                                           QList<Chat> chats,
                                           QList<User> users)
{
}//TelegramEvents::onGeochatsGetLocatedAnswer

void
TelegramEvents::onGeochatsGetRecentsAnswer(qint64 id,
                                           qint32 sliceCount,
                                           QList<GeoChatMessage> messages,
                                           QList<Chat> chats,
                                           QList<User> users)
{
}//TelegramEvents::onGeochatsGetRecentsAnswer

void
TelegramEvents::onGeochatsCheckinAnswer(qint64 id,
                                        GeoChatMessage message,
                                        QList<Chat> chats,
                                        QList<User> users,
                                        qint32 seq)
{
}//TelegramEvents::onGeochatsCheckinAnswer

void
TelegramEvents::onGeochatsGetFullChatAnswer(qint64 id,
                                            ChatFull fullChat,
                                            QList<Chat> chats,
                                            QList<User> users)
{
}//TelegramEvents::onGeochatsGetFullChatAnswer

void
TelegramEvents::onGeochatsEditChatTitleAnswer(qint64 id,
                                              GeoChatMessage message,
                                              QList<Chat> chats,
                                              QList<User> user,
                                              qint32 seq)
{
}//TelegramEvents::onGeochatsEditChatTitleAnswer

void
TelegramEvents::onGeochatsEditChatPhotoAnswer(qint64 id,
                                              GeoChatMessage message,
                                              QList<Chat> chats,
                                              QList<User> user,
                                              qint32 seq)
{
}//TelegramEvents::onGeochatsEditChatPhotoAnswer

void
TelegramEvents::onGeochatsSearchAnswer(qint64 id,
                                       qint32 sliceCount,
                                       QList<GeoChatMessage> messages,
                                       QList<Chat> chats,
                                       QList<User> users)
{
}//TelegramEvents::onGeochatsSearchAnswer

void
TelegramEvents::onGeochatsGetHistory(qint64 id,
                                     qint32 sliceCount,
                                     QList<GeoChatMessage> messages,
                                     QList<Chat> chats,
                                     QList<User> users)
{
}//TelegramEvents::onGeochatsGetHistory

void
TelegramEvents::onGeochatsSetTyping(qint64 id,
                                    bool ok)
{
}//TelegramEvents::onGeochatsSetTyping

void
TelegramEvents::onGeochatsSendMessage(qint64 id,
                                      GeoChatMessage message,
                                      QList<Chat> chats,
                                      QList<User> user,
                                      qint32 seq)
{
}//TelegramEvents::onGeochatsSendMessage

void
TelegramEvents::onGeochatsSendMedia(qint64 id,
                                    GeoChatMessage message,
                                    QList<Chat> chats,
                                    QList<User> user,
                                    qint32 seq)
{
}//TelegramEvents::onGeochatsSendMedia

void
TelegramEvents::onGeochatsCreateGeoChatAnswer(qint64 id,
                                              GeoChatMessage message,
                                              QList<Chat> chats,
                                              QList<User> users,
                                              qint32 seq)
{
}//TelegramEvents::onGeochatsCreateGeoChatAnswer


// Working with updates
void
TelegramEvents::onUpdatesGetStateAnswer(qint64 id,
                                        qint32 pts,
                                        qint32 qts,
                                        qint32 date,
                                        qint32 seq,
                                        qint32 unreadCount)
{
}//TelegramEvents::onUpdatesGetStateAnswer

void
TelegramEvents::onUpdatesGetDifferenceAnswer(qint64 id,
                                             qint32 date,
                                             qint32 seq)
{
}//TelegramEvents::onUpdatesGetDifferenceAnswer

void
TelegramEvents::onUpdatesGetDifferenceAnswer(qint64 id,
                                             QList<Message> messages,
                                             QList<SecretChatMessage> secretChatMessages,
                                             QList<Update> otherUpdates,
                                             QList<Chat> chats,
                                             QList<User> users,
                                             UpdatesState state,
                                             bool isIntermediateState)
{
}//TelegramEvents::onUpdatesGetDifferenceAnswer


// Working with files
void
TelegramEvents::onUploadGetFileAnswer(qint64 fileId,
                                      StorageFileType type,
                                      qint32 mtime,
                                      QByteArray bytes,
                                      qint32 partId,
                                      qint32 downloaded,
                                      qint32 total)
{
}//TelegramEvents::onUploadGetFileAnswer

void
TelegramEvents::onUploadCancelFileAnswer(qint64 fileId,
                                         bool cancelled)
{
}//TelegramEvents::onUploadCancelFileAnswer

void
TelegramEvents::onUploadSendFileAnswer(qint64 fileId,
                                       qint32 partId,
                                       qint32 uploaded,
                                       qint32 totalSize)
{
}//TelegramEvents::onUploadSendFileAnswer


// Miscellaneous
void
TelegramEvents::onHelpGetSuppportAnswer(qint64 id,
                                        QString phoneNumber,
                                        User user)
{
}//TelegramEvents::onHelpGetSuppportAnswer

void
TelegramEvents::onHelpGetInviteTextAnswer(qint64 id,
                                          QString message)
{
}//TelegramEvents::onHelpGetInviteTextAnswer

void
TelegramEvents::onHelpGetAppUpdateAnswer(qint64 id,
                                         qint32 updateId,
                                         bool critical,
                                         QString url,
                                         QString text)
{
}//TelegramEvents::onHelpGetAppUpdateAnswer

// Updates
void
TelegramEvents::onUpdatesTooLong()
{
}//TelegramEvents::onUpdatesTooLong

void
TelegramEvents::onUpdateShortMessage(qint32 id,
                                     qint32 fromId,
                                     QString message,
                                     qint32 pts,
                                     qint32 date,
                                     qint32 seq)
{
}//TelegramEvents::onUpdateShortMessage

void
TelegramEvents::onUpdateShortChatMessage(qint32 id,
                                         qint32 fromId,
                                         qint32 chatId,
                                         QString message,
                                         qint32 pts,
                                         qint32 date,
                                         qint32 seq)
{
}//TelegramEvents::onUpdateShortChatMessage

void
TelegramEvents::onUpdateShort(Update update,
                              qint32 date)
{
}//TelegramEvents::onUpdateShort

void
TelegramEvents::onUpdatesCombined(QList<Update> updates,
                                  QList<User> users,
                                  QList<Chat> chats,
                                  qint32 date,
                                  qint32 seqStart,
                                  qint32 seq)
{
}//TelegramEvents::onUpdatesCombined

void
TelegramEvents::onUpdates(QList<Update> udts,
                          QList<User> users,
                          QList<Chat> chats,
                          qint32 date,
                          qint32 seq)
{
}//TelegramEvents::onUpdates

void
TelegramEvents::onUpdateSecretChatMessage(const SecretChatMessage &secretChatMessage,
                                          qint32 qts)
{
}//TelegramEvents::onUpdateSecretChatMessage


// Additional signals
void
TelegramEvents::onDisconnected()
{
}//TelegramEvents::onDisconnected

void
TelegramEvents::onConnected()
{
}//TelegramEvents::onConnected

void
TelegramEvents::onWoken()
{
}//TelegramEvents::onWoken


void
TelegramEvents::onFatalError()
{
}//TelegramEvents::onFatalError

