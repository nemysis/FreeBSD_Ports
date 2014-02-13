# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensurge
#PORTVERSION=	0.2.0${SVN_REV}
PORTVERSION=	0.2.0
CATEGORIES=	games
MASTER_SITES=	http://www.ime.usp.br/~alemart/opensurge_nightly/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:mods
DISTFILES=	${PORTNAME}-src-build${SVN_REV}${EXTRACT_SUFX} \
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

SVN_REV=	760
MODS_VER=	20130928

USES=		cmake dos2unix openal:soft
#dos2unix
DOS2UNIX_FILES=	*.txt *.lng *.lev *.obj *.qst *.spr *.h *.c *.bg *.brk *.grp
#USE_GCC=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro \
		${LOCALBASE}/include/alfont.h:${PORTSDIR}/x11-fonts/alfont \
		alureplay:${PORTSDIR}/audio/alure
LIB_DEPENDS+=	liballeg.so:${PORTSDIR}/devel/allegro \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro

PORTDOCS=	readme.html

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} pkg-message

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 32x32 48x48 64x64 72x72 96x96 128x128 256x256

DESKTOP_ENTRIES="Open Surge" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

.if exists(${LOCALBASE}/libdata/pkgconfig/alure-static.pc)
IGNORE=		STATIC ALURE libs do not support Open Surge build. (Re)Install audio/alure with the STATIC option OFF
.endif

post-extract-script:
	@(cd ${WRKDIR}/opensurge-mods ; ${COPYTREE_SHARE} . ${WRKSRC})
	@${CHMOD} 644 ${WRKSRC}/levels/desert1.lev

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/opensurge|${DATADIR}|' \
		-e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/core/global.h
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/core/osspec.c

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		-e 's|/usr/bin|${PREFIX}/bin|' \
		-e 's|license.txt readme.html||' \
		-e 's|licenses||' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' '/Copying executable to/,+2d' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	@${INSTALL_DATA} ${WRKSRC}/src/misc/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
