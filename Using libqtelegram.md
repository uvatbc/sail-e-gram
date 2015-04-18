How to use libqtelegram sources in your own code:

-> Make sure you comply with the GPL license!

-> To to telegram.org and register your application to get an application hash and an ID.
You will also get a tg.key file. This is supposed to be a secret and it should NOT be in checked in with your source.
It does need to be added to your binary, so you should pull it in through your qrc.

-> Check out the libqtelegram source:
bzr branch lp:libqtelegram

-> The list of files that need to be added into your sources are at <TODO>

-> Implement two extern functions somewhere in your source:
QString getTgAppHash() { return "your app hash"; }
quint32 getTgAppId() { return YOUR_APP_ID; }
These two functions will be called frequently by the libqtelegram sources, so try to make them as "thin" as possible.

-> Create a new class that will be your interface to the Telegram class. It will connect to the whole list of signals from the Telegram class. See for example, the TelegramEvents class <TODO>

-> When your app runs the first time, your UI will need to get the users phone number (MSISDN).
The msisdn will be required to create an instance of the Telegram class (m_telegram).

-> make sure you pay attention to Qt warnings about signals and slots changing!

-> As soon as m_telegram is created, it will look for settings that it might have saved in the config directory. If there is nothing, it will create a settings directory for the msisdn and settings file inside it.

-> Your code will need to call m_telegram->init() once it is ready to handle signals and talk over the network.
m_telegram starts off by a handshake <TODO: ??> with the telegram servers.

-> Signals fired:
->-> onConnected
->-> onAuthNeeded
->->-> Respond to this by calling m_telegram->authCheckPhone();
->-> onAuthCheckPhoneSent
->-> onDisconnected
->-> onAuthCheckPhoneSent
->-> onConnected
->-> onAuthCheckPhoneAnswer
->->-> Respond to this with m_telegram->authSendCode();
->-> onAuthSendCodeAnswer
->->-> This is where you need to ask the user to enter the code and show the timeout before the call is made.
->-> onDisconnected
