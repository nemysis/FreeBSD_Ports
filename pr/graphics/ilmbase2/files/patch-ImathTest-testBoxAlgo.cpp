--- ImathTest/testBoxAlgo.cpp.orig	2013-02-04 19:22:35.000000000 +0100
+++ ImathTest/testBoxAlgo.cpp	2013-06-08 01:29:13.000000000 +0200
@@ -356,7 +356,7 @@
 	Box3f ()
     };
 
-    for (int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
+    for (unsigned int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
 	testEntryAndExitPoints (boxes[i]);
 }
 
