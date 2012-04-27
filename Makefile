#############################################################################
# Makefile for building: QTApp
# Generated by qmake (2.01a) (Qt 4.6.2) on: Wed Apr 25 22:23:46 2012
# Project:  QTApp2.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile QTApp2.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		ball.cpp \
		brick.cpp \
		laser.cpp \
		player.cpp \
		altair.cpp \
		boss.cpp \
		tracker.cpp \
		TESTCPP.cpp \
		enemylaser.cpp \
		life.cpp \
		andromeda.cpp \
		runner.cpp \
		sentinel.cpp moc_sentinel.cpp \
		qrc_ball.cpp \
		qrc_paddle.cpp \
		qrc_ship1.cpp \
		qrc_asteroid.cpp \
		qrc_laser.cpp \
		qrc_Stars.cpp \
		qrc_FirstShip.cpp \
		qrc_bouncer.cpp \
		qrc_metalblock.cpp \
		qrc_hunter.cpp \
		qrc_truealtair.cpp \
		qrc_EnemyLaser.cpp \
		qrc_Heart.cpp \
		qrc_Andromeda.cpp
OBJECTS       = main.o \
		ball.o \
		brick.o \
		laser.o \
		player.o \
		altair.o \
		boss.o \
		tracker.o \
		TESTCPP.o \
		enemylaser.o \
		life.o \
		andromeda.o \
		runner.o \
		sentinel.o \
		moc_sentinel.o \
		qrc_ball.o \
		qrc_paddle.o \
		qrc_ship1.o \
		qrc_asteroid.o \
		qrc_laser.o \
		qrc_Stars.o \
		qrc_FirstShip.o \
		qrc_bouncer.o \
		qrc_metalblock.o \
		qrc_hunter.o \
		qrc_truealtair.o \
		qrc_EnemyLaser.o \
		qrc_Heart.o \
		qrc_Andromeda.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		QTApp2.pro
QMAKE_TARGET  = QTApp
DESTDIR       = 
TARGET        = QTApp

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_widget.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: QTApp2.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile QTApp2.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile QTApp2.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/QTApp1.0.0 || $(MKDIR) .tmp/QTApp1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/QTApp1.0.0/ && $(COPY_FILE) --parents ball.h brick.h laser.h player.h altair.h boss.h tracker.h enemylaser.h life.h andromeda.h runner.h sentinel.h .tmp/QTApp1.0.0/ && $(COPY_FILE) --parents ball.qrc paddle.qrc ship1.qrc asteroid.qrc laser.qrc Stars.qrc FirstShip.qrc bouncer.qrc metalblock.qrc hunter.qrc truealtair.qrc EnemyLaser.qrc Heart.qrc Andromeda.qrc .tmp/QTApp1.0.0/ && $(COPY_FILE) --parents main.cpp ball.cpp brick.cpp laser.cpp player.cpp altair.cpp boss.cpp tracker.cpp TESTCPP.cpp enemylaser.cpp life.cpp andromeda.cpp runner.cpp sentinel.cpp .tmp/QTApp1.0.0/ && $(COPY_FILE) --parents widget.ui .tmp/QTApp1.0.0/ && (cd `dirname .tmp/QTApp1.0.0` && $(TAR) QTApp1.0.0.tar QTApp1.0.0 && $(COMPRESS) QTApp1.0.0.tar) && $(MOVE) `dirname .tmp/QTApp1.0.0`/QTApp1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/QTApp1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_sentinel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_sentinel.cpp
moc_sentinel.cpp: ball.h \
		brick.h \
		player.h \
		laser.h \
		tracker.h \
		altair.h \
		boss.h \
		andromeda.h \
		runner.h \
		life.h \
		enemylaser.h \
		sentinel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) sentinel.h -o moc_sentinel.cpp

compiler_rcc_make_all: qrc_ball.cpp qrc_paddle.cpp qrc_ship1.cpp qrc_asteroid.cpp qrc_laser.cpp qrc_Stars.cpp qrc_FirstShip.cpp qrc_bouncer.cpp qrc_metalblock.cpp qrc_hunter.cpp qrc_truealtair.cpp qrc_EnemyLaser.cpp qrc_Heart.cpp qrc_Andromeda.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_ball.cpp qrc_paddle.cpp qrc_ship1.cpp qrc_asteroid.cpp qrc_laser.cpp qrc_Stars.cpp qrc_FirstShip.cpp qrc_bouncer.cpp qrc_metalblock.cpp qrc_hunter.cpp qrc_truealtair.cpp qrc_EnemyLaser.cpp qrc_Heart.cpp qrc_Andromeda.cpp
qrc_ball.cpp: ball.qrc \
		ball.png
	/usr/bin/rcc -name ball ball.qrc -o qrc_ball.cpp

qrc_paddle.cpp: paddle.qrc \
		paddle.png
	/usr/bin/rcc -name paddle paddle.qrc -o qrc_paddle.cpp

qrc_ship1.cpp: ship1.qrc \
		ship1.png
	/usr/bin/rcc -name ship1 ship1.qrc -o qrc_ship1.cpp

qrc_asteroid.cpp: asteroid.qrc \
		asteroid.png
	/usr/bin/rcc -name asteroid asteroid.qrc -o qrc_asteroid.cpp

qrc_laser.cpp: laser.qrc \
		laser.png
	/usr/bin/rcc -name laser laser.qrc -o qrc_laser.cpp

qrc_Stars.cpp: Stars.qrc \
		Stars.jpg
	/usr/bin/rcc -name Stars Stars.qrc -o qrc_Stars.cpp

qrc_FirstShip.cpp: FirstShip.qrc \
		FirstShip.png
	/usr/bin/rcc -name FirstShip FirstShip.qrc -o qrc_FirstShip.cpp

qrc_bouncer.cpp: bouncer.qrc \
		bouncers.png
	/usr/bin/rcc -name bouncer bouncer.qrc -o qrc_bouncer.cpp

qrc_metalblock.cpp: metalblock.qrc \
		metalblock.png
	/usr/bin/rcc -name metalblock metalblock.qrc -o qrc_metalblock.cpp

qrc_hunter.cpp: hunter.qrc \
		hunter.png
	/usr/bin/rcc -name hunter hunter.qrc -o qrc_hunter.cpp

qrc_truealtair.cpp: truealtair.qrc \
		truealtair.png
	/usr/bin/rcc -name truealtair truealtair.qrc -o qrc_truealtair.cpp

qrc_EnemyLaser.cpp: EnemyLaser.qrc \
		enemyfire.png
	/usr/bin/rcc -name EnemyLaser EnemyLaser.qrc -o qrc_EnemyLaser.cpp

qrc_Heart.cpp: Heart.qrc \
		heart.png
	/usr/bin/rcc -name Heart Heart.qrc -o qrc_Heart.cpp

qrc_Andromeda.cpp: Andromeda.qrc \
		andromeda.png
	/usr/bin/rcc -name Andromeda Andromeda.qrc -o qrc_Andromeda.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_widget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_widget.h
ui_widget.h: widget.ui
	/usr/bin/uic-qt4 widget.ui -o ui_widget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp sentinel.h \
		ball.h \
		brick.h \
		player.h \
		laser.h \
		tracker.h \
		altair.h \
		boss.h \
		andromeda.h \
		runner.h \
		life.h \
		enemylaser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

ball.o: ball.cpp ball.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ball.o ball.cpp

brick.o: brick.cpp brick.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o brick.o brick.cpp

laser.o: laser.cpp laser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o laser.o laser.cpp

player.o: player.cpp player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o player.o player.cpp

altair.o: altair.cpp altair.h \
		boss.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o altair.o altair.cpp

boss.o: boss.cpp boss.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o boss.o boss.cpp

tracker.o: tracker.cpp tracker.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tracker.o tracker.cpp

TESTCPP.o: TESTCPP.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TESTCPP.o TESTCPP.cpp

enemylaser.o: enemylaser.cpp enemylaser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o enemylaser.o enemylaser.cpp

life.o: life.cpp life.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o life.o life.cpp

andromeda.o: andromeda.cpp andromeda.h \
		boss.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o andromeda.o andromeda.cpp

runner.o: runner.cpp runner.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o runner.o runner.cpp

sentinel.o: sentinel.cpp sentinel.h \
		ball.h \
		brick.h \
		player.h \
		laser.h \
		tracker.h \
		altair.h \
		boss.h \
		andromeda.h \
		runner.h \
		life.h \
		enemylaser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sentinel.o sentinel.cpp

moc_sentinel.o: moc_sentinel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_sentinel.o moc_sentinel.cpp

qrc_ball.o: qrc_ball.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_ball.o qrc_ball.cpp

qrc_paddle.o: qrc_paddle.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_paddle.o qrc_paddle.cpp

qrc_ship1.o: qrc_ship1.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_ship1.o qrc_ship1.cpp

qrc_asteroid.o: qrc_asteroid.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_asteroid.o qrc_asteroid.cpp

qrc_laser.o: qrc_laser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_laser.o qrc_laser.cpp

qrc_Stars.o: qrc_Stars.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_Stars.o qrc_Stars.cpp

qrc_FirstShip.o: qrc_FirstShip.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_FirstShip.o qrc_FirstShip.cpp

qrc_bouncer.o: qrc_bouncer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_bouncer.o qrc_bouncer.cpp

qrc_metalblock.o: qrc_metalblock.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_metalblock.o qrc_metalblock.cpp

qrc_hunter.o: qrc_hunter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_hunter.o qrc_hunter.cpp

qrc_truealtair.o: qrc_truealtair.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_truealtair.o qrc_truealtair.cpp

qrc_EnemyLaser.o: qrc_EnemyLaser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_EnemyLaser.o qrc_EnemyLaser.cpp

qrc_Heart.o: qrc_Heart.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_Heart.o qrc_Heart.cpp

qrc_Andromeda.o: qrc_Andromeda.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_Andromeda.o qrc_Andromeda.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

