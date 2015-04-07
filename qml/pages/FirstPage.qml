import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    Column {
        id: startMessaging

        anchors.centerIn: parent
        Label {
            text: "Welcome to Sail-e-Gram"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            text: "Start messaging"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                startMessaging.visible = false;
            }
        }
    }

    Column {
        visible: !startMessaging.visible
        anchors.centerIn: parent

        Label {
            text: "Enter your number (with country code)"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        TextField {
            id: number
            width: parent.width
            placeholderText: "+1 222 333 4444"
            inputMethodHints: Qt.ImhDialableCharactersOnly
        }

        Button {
            text: "Log in"
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                g_mainwindow.userLoginWithPhoneNumber(number.text);
            }
        }
    }
}
