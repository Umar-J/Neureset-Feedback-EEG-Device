QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
source_dir = src
forms_dir = ui
resources_dir = res

SOURCES += \
    $${source_dir}/main.cpp \
    $${source_dir}/mainwindow.cpp \
    $${source_dir}/EEG.cpp \
    $${source_dir}/menu.cpp \
    $${source_dir}/Session.cpp \
    $${source_dir}/batterylowmessage.cpp

HEADERS += \
    $${source_dir}/mainwindow.h \
    $${source_dir}/EEG.h \
    $${source_dir}/menu.h \
    $${source_dir}/Session.h \
    $${source_dir}/batterylowmessage.h

FORMS += \
    $${forms_dir}/mainwindow.ui \
    $${forms_dir}/batterylowmessage.ui

RESOURCES += \
    $${resources_dir}/denas.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
