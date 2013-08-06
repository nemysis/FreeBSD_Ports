# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/devel/allegro-devel/Makefile 323734 2013-07-26 16:04:47Z crees $

PORTNAME=	allegro
DISTVERSION=	5.0.9
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform library for games and multimedia programming

LICENSE=	ZLIB BSD
LICENSE_COMB=	dual

LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac \
		physfs:${PORTSDIR}/devel/physfs

USES=		cmake pkgconfig
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_OPENAL=	soft
USE_GL=		gl glu
USE_FREETYPE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB+=	SHLIB_VER1="${SHLIB_VER1}"

SHLIB_VER=	${PORTVERSION}
SHLIB_VER1=	${PORTVERSION:R}

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

# Wrong versioning upstream
PORTSCOUT=	skipv:5.0.10

OPTIONS_DEFINE=	DOCS ALSA PULSEAUDIO
OPTIONS_GROUP=	EXAMPLES_DEMOS
OPTIONS_GROUP_EXAMPLES_DEMOS=	EXAMPLES DEMOS
OPTIONS_DEFAULT=	DEMOS ALSA
DEMOS_DESC=	Install Demos programs, requires EXAMPLES

OPTIONS_SUB=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs

.include <bsd.port.options.mk>
.include "Makefile.man"

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${LOCALBASE}/bin/pandoc:${PORTSDIR}/textproc/hs-pandoc
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
CMAKE_ARGS+=-DWANT_ALSA=on
.else
CMAKE_ARGS+=-DWANT_ALSA=off
.endif

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=-DWANT_DEMO=on
SUB_FILES+=	cosmic_protector speed \
		pkg-message
MASTER_SITES+=	SF/nemysisfreebsdp/allegro/:icons
DISTFILES+=	cosmic_protector.png:icons \
		speed.png:icons
DESKTOP_ENTRIES+="Cosmic Protector" "Protect the earth from a deadly meteor shower" "cosmic_protector" \
		"cosmic_protector" "Game;ArcadeGame;" false
DESKTOP_ENTRIES+="SPEED" "Simultaneous Projections Employing an Ensemble of Displays" "speed" \
		"speed" "Game;ArcadeGame;" false
.else
CMAKE_ARGS+=-DWANT_DEMO=off
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
CMAKE_ARGS+=-DWANT_PULSEAUDIO=on
.else
CMAKE_ARGS+=-DWANT_PULSEAUDIO=off
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/addons/audio/pulseaudio.c

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/man/* ${MAN3PREFIX}/man/man3

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@(cd ${DOCSRCDIR2} && ${COPYTREE_SHARE} "html src" ${DOCSDIR2})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${EXAMPLESDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/cosmic_protector ${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/cosmic_protector.png ${PREFIX}/share/pixmaps
	@(cd ${EXAMPLESDIR}/demos/cosmic_protector && ${CHMOD} 755 cosmic_protector)
	${INSTALL_SCRIPT} ${WRKDIR}/speed ${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/speed.png ${PREFIX}/share/pixmaps
	@(cd ${EXAMPLESDIR}/demos/speed && ${CHMOD} 755 speed)
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
