TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    sim_fcw.c \
    sim_paraset.c \
    sim_io.c \
    mysyslog.c

HEADERS += \
    sim_fcw.h \
    sim_paraset.h \
    sim_io.h \
    mysyslog.h \
    base_type.h

STATECHARTS +=

DISTFILES += \
    sim_hv_rv_dist \
    Config.ini
