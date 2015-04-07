#ifndef TELEGRAMEVENTS_H
#define TELEGRAMEVENTS_H

#include <QObject>

class TelegramEvents : public QObject
{
    Q_OBJECT
public:
    explicit TelegramEvents(QObject *parent = 0);

protected slots:
    // Errors
    void onError(qint64 id, qint32 errorCode, QString errorText);
    void onAuthSignInError(qint64 id, qint32 errorCode, QString errorText);
    void onAuthSignUpError(qint64 id, qint32 errorCode, QString errorText);

    // Registration / authorization
    void onAuthNeeded();
    void onAuthLoggedIn();
    void onAuthCheckPhoneAnswer(qint64 id, bool phoneRegistered, bool phoneInvited);
    void onAuthCheckPhoneSent(qint64 msgId, QString phoneNumber);
    void onAuthSendCodeAnswer(qint64 id, bool phoneRegistered, qint32 sendCallTimeout);
    void onAuthSendSmsAnswer(qint64 id, bool ok);
    void onAuthSendCallAnswer(qint64 id, bool ok);
    void onAuthLogOutAnswer(qint64 id, bool ok);
    void onAuthSendInvitesAnswer(qint64 id, bool ok);
    void onAuthResetAuthorizationsAnswer(qint64 id, bool ok);

    // Working with Notifications. Settings
    void onAccountRegisterDeviceAnswer(qint64 id, bool ok);
    void onAccountUnregisterDeviceAnswer(qint64 id, bool ok);
    void onAccountUpdateNotifySettingsAnswer(qint64 id, bool ok);
    void onAccountGetNotifySettingsAnswer(qint64 id, PeerNotifySettings peerNotifySettings);
    void onAccountResetNotifySettingsAnswer(qint64 id, bool ok);
    void onAccountUpdateProfileAnswer(qint64 id, User user);
    void onAccountUpdateStatusAnswer(qint64 id, bool ok);
    void onAccountGetWallPapersAnswer(qint64 id, QList<WallPaper> wallPapers);
    void onPhotosUploadProfilePhotoAnswer(qint64 id, Photo photo, QList<User> users);
    void onPhotosUpdateProfilePhotoAnswer(qint64 id, UserProfilePhoto userProfilePhoto);

    // Working with users
    void onUsersGetUsersAnswer(qint64 id, QList<User> users);
    void onUsersGetFullUserAnswer(qint64 id, User user, ContactsLink link, Photo profilePhoto, PeerNotifySettings notifySettings, bool blocked, QString realFirstName, QString realLastName);
    void onPhotosGetUserPhotosAnswer(qint64 id, qint32 sliceCount, QList<Photo> photos, QList<User> users);

    // Working with contacts
    void onContactsGetStatusesAnswer(qint64 id, QList<ContactStatus> statuses);
    void onContactsGetContactsAnswer(qint64 id, bool modified, QList<Contact> contacts, QList<User> users);
    void onContactsImportContactsAnswer(qint64 id, QList<ImportedContact> importedContacts, QList<qint64> retryContacts, QList<User> users);
    void onContactsDeleteContactAnswer(qint64 id, ContactsMyLink myLink, ContactsForeignLink foreignLink, User user);
    void onContactsDeleteContactsAnswer(qint64 id, bool ok);

    // Working with blacklist
    void onContactsBlockAnswer(qint64 id, bool ok);
    void onContactsUnblockAnswer(qint64 id, bool ok);
    void onContactsBlockResult(qint64 id, bool ok);
    void onContactsGetBlockedAnswer(qint64 id, qint32 sliceCount, QList<ContactBlocked> blocked, QList<User> users);

    // Working with messages
    void onMessagesSendMessageAnswer(qint64 id, qint32 msgId, qint32 date, qint32 pts, qint32 seq, QList<ContactsLink> links);
    void onMessagesSendMediaAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesSendPhotoAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesSendGeoPointAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesSendContactAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesSendVideoAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesSendAudioAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesSendDocumentAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesSetTypingAnswer(qint64 id, bool ok);
    void onMessagesGetMessagesAnswer(qint64 id, qint32 sliceCount, QList<Message> messages, QList<Chat> chats, QList<User> users);
    void onMessagesGetDialogsAnswer(qint64 id, qint32 sliceCount, QList<Dialog> dialogs, QList<Message> messages, QList<Chat> chats, QList<User> users);
    void onMessagesGetHistoryAnswer(qint64 id, qint32 sliceCount, QList<Message> messages, QList<Chat> chats, QList<User> users);
    void onMessagesSearchAnswer(qint64 id, qint32 sliceCount, QList<Message> messages, QList<Chat> chats, QList<User> users);
    void onMessagesReadHistoryAnswer(qint64 id, qint32 pts, qint32 seq, qint32 offset);
    void onMessagesDeleteHistoryAnswer(qint64 id, qint32 pts, qint32 seq, qint32 offset);
    void onMessagesReadMessageContentsAnswer(qint64 msgId, QList<qint32> watchedIds);
    void onMessagesDeleteMessagesAnswer(qint64 id, QList<qint32> deletedMsgIds);
    void onMessagesRestoreMessagesAnswer(qint64 id, QList<qint32> restoredMsgIds);
    void onMessagesReceivedMessagesAnswer(qint64 id, QList<qint32> confirmedMsgIds);
    void onMessagesForwardMessageAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesForwardMessagesAnswer(qint64 id, QList<Message> messages, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);
    void onMessagesSendBroadcastAnswer(qint64 id, QList<Message> messages, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);

    // Working with chats
    void onMessagesGetChatsAnswer(qint64 id, QList<Chat> chats, QList<User> users);
    void onMessagesGetFullChatAnswer(qint64 id, ChatFull chatFull, QList<Chat> chats, QList<User> users);
    void onMessagesEditChatTitleAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq);// statedMessage or statedMessageLink
    void onMessagesEditChatPhotoAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq); // statedMessage or statedMessageLink
    void onMessagesAddChatUserAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq); // statedMessage or statedMessageLink
    void onMessagesDeleteChatUserAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq); // statedMessage or statedMessageLink
    void onMessagesCreateChatAnswer(qint64 id, Message message, QList<Chat> chats, QList<User> users, QList<ContactsLink> links, qint32 pts, qint32 seq); // statedMessage or statedMessageLink

    // Working with secret chats
    void onMessagesCreateEncryptedChatAnswer(qint32 chatId, qint32 date, qint32 peerId, qint64 accessHash);
    void onMessagesEncryptedChatRequested(qint32 chatId, qint32 date, qint32 peerId, qint64 accessHash);
    void onMessagesEncryptedChatCreated(qint32 chatId, qint32 date, qint32 peerId, qint64 accessHash);
    void onMessagesEncryptedChatDiscarded(qint32 chatId);
    void onMessagesSetEncryptedTypingAnswer(qint64 id, bool ok);
    void onMessagesReadEncryptedHistoryAnswer(qint64 id, bool ok);
    void onMessagesSendEncryptedAnswer(qint64 id, qint32 date, EncryptedFile encryptedFile = EncryptedFile()); // messagesSentEncryptedMessage/messagesSentEncryptedFile
    void onMessagesSendEncryptedFileAnswer(qint64 id, qint32 date, EncryptedFile encryptedFile = EncryptedFile()); // messagesSentEncryptedMessage/messagesSentEncryptedFile
    void onMessagesSendEncryptedServiceAnswer(qint64 id, qint32 date, EncryptedFile encryptedFile = EncryptedFile()); // messagesSentEncryptedMessage/messagesSentEncryptedFile
    void onMessagesReceivedQueueAnwer(qint64 id, QList<qint64> msgIds);

    // Working with geochats
    void onGeochatsGetLocatedAnswer(qint64 id, QList<ChatLocated> results, QList<GeoChatMessage> messages, QList<Chat> chats, QList<User> users);
    void onGeochatsGetRecentsAnswer(qint64 id, qint32 sliceCount, QList<GeoChatMessage> messages, QList<Chat> chats, QList<User> users);
    void onGeochatsCheckinAnswer(qint64 id, GeoChatMessage message, QList<Chat> chats, QList<User> users, qint32 seq);
    void onGeochatsGetFullChatAnswer(qint64 id, ChatFull fullChat, QList<Chat> chats, QList<User> users);
    void onGeochatsEditChatTitleAnswer(qint64 id, GeoChatMessage message, QList<Chat> chats, QList<User> user, qint32 seq);
    void onGeochatsEditChatPhotoAnswer(qint64 id, GeoChatMessage message, QList<Chat> chats, QList<User> user, qint32 seq);
    void onGeochatsSearchAnswer(qint64 id, qint32 sliceCount, QList<GeoChatMessage> messages, QList<Chat> chats, QList<User> users);
    void onGeochatsGetHistory(qint64 id, qint32 sliceCount, QList<GeoChatMessage> messages, QList<Chat> chats, QList<User> users);
    void onGeochatsSetTyping(qint64 id, bool ok);
    void onGeochatsSendMessage(qint64 id, GeoChatMessage message, QList<Chat> chats, QList<User> user, qint32 seq);
    void onGeochatsSendMedia(qint64 id, GeoChatMessage message, QList<Chat> chats, QList<User> user, qint32 seq);
    void onGeochatsCreateGeoChatAnswer(qint64 id, GeoChatMessage message, QList<Chat> chats, QList<User> users, qint32 seq);

    // Working with updates
    void onUpdatesGetStateAnswer(qint64 id, qint32 pts, qint32 qts, qint32 date, qint32 seq, qint32 unreadCount);
    void onUpdatesGetDifferenceAnswer(qint64 id, qint32 date, qint32 seq);
    void onUpdatesGetDifferenceAnswer(qint64 id, QList<Message> messages, QList<SecretChatMessage> secretChatMessages, QList<Update> otherUpdates, QList<Chat> chats, QList<User> users, UpdatesState state, bool isIntermediateState);

    // Working with files
    void onUploadGetFileAnswer(qint64 fileId, StorageFileType type, qint32 mtime, QByteArray bytes, qint32 partId, qint32 downloaded, qint32 total);
    void onUploadCancelFileAnswer(qint64 fileId, bool cancelled);
    void onUploadSendFileAnswer(qint64 fileId, qint32 partId, qint32 uploaded, qint32 totalSize);

    // Miscellaneous
    void onHelpGetSuppportAnswer(qint64 id, QString phoneNumber, User user);
    void onHelpGetInviteTextAnswer(qint64 id, QString message);
    void onHelpGetAppUpdateAnswer(qint64 id, qint32 updateId, bool critical, QString url, QString text); // if updateId <=0 there isn't any update

    // Updates
    void onUpdatesTooLong();
    void onUpdateShortMessage(qint32 id, qint32 fromId, QString message, qint32 pts, qint32 date, qint32 seq);
    void onUpdateShortChatMessage(qint32 id, qint32 fromId, qint32 chatId, QString message, qint32 pts, qint32 date, qint32 seq);
    void onUpdateShort(Update update, qint32 date);
    void onUpdatesCombined(QList<Update> updates, QList<User> users, QList<Chat> chats, qint32 date, qint32 seqStart, qint32 seq);
    void onUpdates(QList<Update> udts, QList<User> users, QList<Chat> chats, qint32 date, qint32 seq);
    void onUpdateSecretChatMessage(const SecretChatMessage &secretChatMessage, qint32 qts);

    // Additional signals
    void onDisconnected();
    void onConnected();
    void onWoken();

    void onFatalError();
};

#endif // TELEGRAMEVENTS_H
