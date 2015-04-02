INCLUDEPATH += $$PWD/../libqtelegram/lib/

SOURCES  *= $$PWD/../libqtelegram/lib/telegram.cpp \
            $$PWD/../libqtelegram/lib/core/connection.cpp \
            $$PWD/../libqtelegram/lib/core/settings.cpp \
            $$PWD/../libqtelegram/lib/core/inboundpkt.cpp \
            $$PWD/../libqtelegram/lib/core/outboundpkt.cpp \
            $$PWD/../libqtelegram/lib/core/dcprovider.cpp \
            $$PWD/../libqtelegram/lib/core/eventtimer.cpp \
            $$PWD/../libqtelegram/lib/core/api.cpp \
            $$PWD/../libqtelegram/lib/core/query.cpp \
            $$PWD/../libqtelegram/lib/core/abstractapi.cpp \
            $$PWD/../libqtelegram/lib/core/session.cpp \
            $$PWD/../libqtelegram/lib/core/dcauth.cpp \
            $$PWD/../libqtelegram/lib/core/sessionmanager.cpp \
            $$PWD/../libqtelegram/lib/util/asserter.cpp \
            $$PWD/../libqtelegram/lib/util/cryptoutils.cpp \
            $$PWD/../libqtelegram/lib/util/utils.cpp \
            $$PWD/../libqtelegram/lib/secret/decrypter.cpp \
            $$PWD/../libqtelegram/lib/secret/encrypter.cpp \
            $$PWD/../libqtelegram/lib/secret/secretstate.cpp \
            $$PWD/../libqtelegram/lib/secret/secretchat.cpp \
            $$PWD/../libqtelegram/lib/secret/decryptedmessagebuilder.cpp \
            $$PWD/../libqtelegram/lib/file/filehandler.cpp \
            $$PWD/../libqtelegram/lib/file/downloadfile.cpp \
            $$PWD/../libqtelegram/lib/file/uploadfile.cpp

HEADERS  *= $$PWD/../libqtelegram/lib/file/fileoperation.h \
            $$PWD/../libqtelegram/lib/file/file.h \
            $$PWD/../libqtelegram/lib/telegram.h \
            $$PWD/../libqtelegram/lib/libqtelegram_global.h

LIBS     *= -lz -lrt -lssl -lcrypto
QT       *= network
