# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensurge
PORTVERSION=	0.2.0${SVN_REV}
CATEGORIES=	games
MASTER_SITES=	http://www.ime.usp.br/~alemart/opensurge_nightly/ \
		SF/nemysisfreebsdp/${PORTNAME}/:mods
DISTFILES=	${PORTNAME}-src-build${SVN_REV}${EXTRACT_SUFX}:mods \
		${PORTNAME}-mods-${MODS_VER}${EXTRACT_SUFX}:mods

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game based on the Sonic the Hedgehog universe

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/licenses/CC-BY-SA-3.0.txt
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}-src-build${SVN_REV}

SVN_REV=	756
MODS_VER=	20130812

USES=		cmake
USE_OPENAL=	soft

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro-devel \
		${LOCALBASE}/include/alfont.h:${PORTSDIR}/x11-fonts/alfont \
		alureplay:${PORTSDIR}/audio/alure
LIB_DEPENDS+=	alleg:${PORTSDIR}/devel/allegro \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro-devel

PORTDOCS=	readme.html

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} pkg-message

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 32x32 48x48 64x64 72x72 96x96 128x128 256x256

DESKTOP_ENTRIES="Open Surge" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/alure-static.pc)
IGNORE=		STATIC ALURE libs do not support Open Surge build. (Re)Install audio/alure with the STATIC option OFF
.endif

post-extract-script:
	@(cd ${WRKDIR}/opensurge-mods && ${COPYTREE_SHARE} . ${WRKSRC})

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/opensurge|${DATADIR}|' \
		-e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/core/global.h
#	@${REINPLACE_CMD} -e 's|logfile.txt|~/.${PORTNAME}/logfile.txt|' \
#		${WRKSRC}/src/core/logfile.c
#	@${REINPLACE_CMD} -e 's|preferences.dat|~/.${PORTNAME}/preferences.dat|' \
#		${WRKSRC}/src/core/preferences.c
	@${REINPLACE_CMD} -i '' '/FIND_LIBRARY(LDL NAMES/,/ENDIF(NOT $${CMAKE_SYSTEM_NAME}/s/^/#/' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		-e 's|/usr/bin|${PREFIX}/bin|' \
		-e 's|license.txt readme.html||' \
		-e 's|licenses||' \
		${WRKSRC}/CMakeLists.txt
#	@${REINPLACE_CMD} -i '' '/TARGETS $${GAME_UNIXNAME}/d' \
#		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' '/Copying executable to/,+2d' \
		${WRKSRC}/CMakeLists.txt

#	@${REINPLACE_CMD} -e 's|*.spr|*/*.spr|' \
#		${WRKSRC}/src/core/sprite.c
#	@${REINPLACE_CMD} -e 's|config/input.def|.config/opensurge/input.def|' \
#			${WRKSRC}/src/core/inputmap.c ${WRKSRC}/src/core/input.c
#	@${REINPLACE_CMD} -e 's|config/samples.def|.config/opensurge/samples.def|' \
#			${WRKSRC}/src/core/soundfactory.c
#	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
#		-e 's|^GAME_DIR.*|GAME_DIR=${DATADIR}|' \
#		${WRKSRC}/src/misc/${PORTNAME}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
#	${INSTALL_SCRIPT} ${WRKSRC}/src/misc/${PORTNAME} ${PREFIX}/bin
#	(cd ${DATADIR} ; ${MV} ${PORTNAME} ${PORTNAME}_bin)

.for s in ${ICON_SIZES}
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	@${INSTALL_DATA} ${WRKSRC}/src/misc/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	@${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps
#	@(cd ${DATADIR} && ${CHMOD} -R 775 sprites)
#	${CHMOD} -R 775 ${DATADIR}
#	${CHMOD} -R 777 ${DATADIR}
#	${CHMOD} 775 ${DATADIR}
#	${CHMOD} 775 ${DATADIR}/config/*.def
#	@(cd ${DATADIR} && ${CHMOD} 775 *)

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
