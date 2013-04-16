--- src/Font.py.orig	2008-02-02 15:27:38.000000000 +0100
+++ src/Font.py	2012-09-07 13:22:33.000000000 +0200
@@ -186,7 +186,7 @@
     glDisable(GL_TEXTURE_2D)
 
   def _allocateGlyphTexture(self):
-    t = TextureAtlas(size = glGetInteger(GL_MAX_TEXTURE_SIZE))
+    t= TextureAtlas()
     t.texture.setFilter(GL_LINEAR, GL_LINEAR)
     t.texture.setRepeat(GL_CLAMP, GL_CLAMP)
     self.glyphTextures.append(t)
