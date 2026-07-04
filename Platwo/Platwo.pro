QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    custommessagebox.cpp \
    filemanager.cpp \
    forgotpasswordwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainmenuwindow.cpp \
    security.cpp \
    signupwindow.cpp \
    user.cpp \
    usermanager.cpp \
    welcomewindow.cpp \
    widget.cpp

HEADERS += \
    custommessagebox.h \
    filemanager.h \
    forgotpasswordwindow.h \
    loginwindow.h \
    mainmenuwindow.h \
    security.h \
    signupwindow.h \
    user.h \
    usermanager.h \
    welcomewindow.h \
    widget.h

FORMS += \
    forgotpasswordwindow.ui \
    loginwindow.ui \
    mainmenuwindow.ui \
    signupwindow.ui \
    welcomewindow.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
