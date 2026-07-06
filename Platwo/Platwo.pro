QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    custommessagebox.cpp \
    editprofilewindow.cpp \
    filemanager.cpp \
    forgotpasswordwindow.cpp \
    gamehistory.cpp \
    gamewindow.cpp \
    guestwindow.cpp \
    hostwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    security.cpp \
    signupwindow.cpp \
    user.cpp \
    usermanager.cpp \
    welcomewindow.cpp \
    widget.cpp

HEADERS += \
    custommessagebox.h \
    editprofilewindow.h \
    filemanager.h \
    forgotpasswordwindow.h \
    gamehistory.h \
    gamewindow.h \
    guestwindow.h \
    hostwindow.h \
    loginwindow.h \
    mainwindow.h \
    security.h \
    signupwindow.h \
    user.h \
    usermanager.h \
    welcomewindow.h \
    widget.h

FORMS += \
    editprofilewindow.ui \
    forgotpasswordwindow.ui \
    gamewindow.ui \
    guestwindow.ui \
    hostwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    signupwindow.ui \
    welcomewindow.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
