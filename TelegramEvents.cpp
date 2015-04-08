#include "TelegramEvents.h"

TelegramEvents::TelegramEvents(QObject *parent)
    : QObject(parent)
{
}//TelegramEvents::TelegramEvents

// Errors
void
TelegramEvents::onError(qint64 id,
                        qint32 errorCode,
                        QString errorText)
{
}//TelegramEvents::onError

void
TelegramEvents::onAuthSignInError(qint64 id,
                                  qint32 errorCode,
                                  QString errorText)
{
}//TelegramEvents::onAuthSignInError

void
TelegramEvents::onAuthSignUpError(qint64 id,
                                  qint32 errorCode,
                                  QString errorText)
{
}//TelegramEvents::onAuthSignUpError

// Registration / authorization
void
TelegramEvents::onAuthNeeded()
{
}//TelegramEvents::onAuthNeeded

void
TelegramEvents::onAuthLoggedIn()
{
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

