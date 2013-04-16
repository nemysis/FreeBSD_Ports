# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD: head/games/sumwars/Makefile 314960 2013-03-22 20:06:14Z makc $

PORTNAME=	sumwars
PORTVERSION=	0.5.6
CATEGORIES=	games
MASTER_SITES=	SF/sumwars/${PORTVERSION}/
DISTNAME=	sumwars-${PORTVERSION}-src

MAINTAINER=	devel@stasyan.com
COMMENT=	Role-playing game, featuring both a single and a multiplayer mode

BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.8.1:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS-1.2.0.so:${PORTSDIR}/devel/ois \
		${LOCALBASE}/lib/libenet.a:${PORTSDIR}/net/enet
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.8.1:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS-1.2.0.so:${PORTSDIR}/devel/ois
LIB_DEPENDS=	CEGUIBase-0.7.9.0:${PORTSDIR}/graphics/cegui \
		vorbis:${PORTSDIR}/audio/libvorbis \
		PocoNet.12:${PORTSDIR}/devel/poco \
		physfs:${PORTSDIR}/devel/physfs

WRKSRC=		${WRKDIR}/sumwars-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		cmake
USE_GL=		gl glu
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_LUA=	5.1
USE_OPENAL=	al alut
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DGETTEXT_SEARCH_PATH=${LOCALBASE}/lib

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's|/usr/local/lib/|${LOCALBASE}/lib/|g' ${WRKSRC}/CMakeModules/FindEnet.cmake \
		${WRKSRC}/CMakeModules/FindPhysFS.cmake \
		${WRKSRC}/CMakeModules/FindOGRE.cmake
	@${REINPLACE_CMD} -e 's|/usr/games|${LOCALBASE}/games|g' \
		-e 's|/usr/share|${LOCALBASE}/share|g' ${WRKSRC}/packaging/sumwars.desktop
	@${REINPLACE_CMD} -e 's|"OIS|"OIS/OIS|' \
		${WRKSRC}/src/core/options.cpp ${WRKSRC}/src/gui/contenteditor/contenteditor.h \
		${WRKSRC}/src/gui/mainwindow.h ${WRKSRC}/src/gui/skilltree.h \
		${WRKSRC}/src/gui/debugpanel/filebrowser/filebrowser.h
	@${REINPLACE_CMD} -e 's|<OIS|<OIS/OIS|' \
		${WRKSRC}/src/gui/optionswindow.h ${WRKSRC}/src/gui/debugpanel/debugtab.h \
		${WRKSRC}/src/gui/debugpanel/debugcameratab.cpp ${WRKSRC}/src/gui/contenteditor/contenteditor.cpp
.for no_end in charconv.cpp mathhelper.h xmlutil.h itemlist.cpp monsterbase.cpp fixedbase.cpp
	@cd ${WRKSRC}/src/core && ${ECHO_CMD} "" >> ${no_end}
.endfor
.for no_end in contenteditor/contenteditortab.h contenteditor/renderinfoeditor.h contenteditor/fixedobjecteditor.h \
	contenteditor/itemeditor.h contenteditor/monstereditor.h contenteditor/contenteditortab.cpp inventory.cpp \
	graphicobjectrenderinfo.cpp clipboard.cpp
	@cd ${WRKSRC}/src/gui && ${ECHO_CMD} "" >> ${no_end}
.endfor

.include <bsd.port.mk>
