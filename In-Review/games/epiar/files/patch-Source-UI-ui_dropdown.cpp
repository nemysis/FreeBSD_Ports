--- Source/UI/ui_dropdown.cpp.orig	2012-10-27 10:18:51.000000000 +0200
+++ Source/UI/ui_dropdown.cpp	2013-09-15 01:48:22.000000000 +0200
@@ -178,7 +178,7 @@
 }
 
 string Dropdown::GetText(){
-	if(( selected < 0) || (selected >= options.size()) ) {
+	if(selected >= options.size()) {
 		// Invalid selection, likely because this is an empty dropdown list.
 		return "";
 	}
