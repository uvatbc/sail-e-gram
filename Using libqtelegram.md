How to use libqtelegram sources in your own code:

-> Make sure you comply with the GPL license!

-> To to telegram.org and register your application to get an application hash and an ID.

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

-> As soon as m_telegram is created, it will do a bit of negotiation with the telegram servers.