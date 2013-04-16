--- config.mk.orig	2013-01-22 00:21:07.000000000 +0100
+++ config.mk	2013-02-04 17:25:50.000000000 +0100
@@ -5,17 +5,18 @@
 
 default: all
 
-CC    := gcc
-CXX   := g++
+CC    := cc
+CXX   := c++
 OSDIR := linux
 
 # (Add a -g for debugging)
-CPPFLAGS += -O2 -Wall
+CPPFLAGS += -Wall
 
 ### FreeBSD configuration
 
 ifeq ($(shell uname), FreeBSD)
-CPPFLAGS += -L/usr/local/lib
+CPPFLAGS += -I%%LOCALBASE%%/include %%PTHREAD_CFLAGS%%
+LDFLAGS += -L%%LOCALBASE%%/lib %%PTHREAD_LIBS%%
 endif
 
 ### Default directory
