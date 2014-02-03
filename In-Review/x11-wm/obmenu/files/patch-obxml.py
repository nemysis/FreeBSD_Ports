--- ./obxml.py.orig	2006-02-01 00:26:38.000000000 +0100
+++ ./obxml.py	2013-11-30 22:28:49.000000000 +0100
@@ -117,7 +117,7 @@
 				accion = it.attributes["name"].nodeValue
 				if accion.lower() == "execute":
 					for itm in it.childNodes:
-						if itm.nodeType == 1 and itm.nodeName.lower() == "execute":
+						if itm.nodeType == 1 and itm.nodeName.lower() == "command":
 							for item in itm.childNodes:
 								if item.nodeType == 3:
 									param = item.nodeValue.strip()
@@ -207,7 +207,7 @@
 		nodo.attributes["label"] = label
 		accion = self.dom.createElement("action")
 		accion.attributes["name"] = "Execute"
-		exe = self.dom.createElement("execute")
+		exe = self.dom.createElement("command")
 		txt = self.dom.createTextNode("")
 		txt.nodeValue = execute
 		exe.appendChild(txt)
@@ -256,14 +256,14 @@
 				it.attributes["name"].nodeValue = action
 				if action == "Execute":
 					if not it.childNodes:
-						elm = xml.dom.minidom.Element("execute")
+						elm = xml.dom.minidom.Element("command")
 						txt = xml.dom.minidom.Text()
 						txt.nodeValue = exe
 						elm.appendChild(txt)
 						it.appendChild(elm)
 					else:
 						for i in it.childNodes:
-							if i.nodeType == 1 and i.nodeName == "execute":
+							if i.nodeType == 1 and i.nodeName == "command":
 								for item in i.childNodes:
 									if item.nodeType == 3:
 										item.nodeValue = exe
