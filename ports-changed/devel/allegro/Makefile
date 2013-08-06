# $FreeBSD: head/devel/allegro/Makefile 323734 2013-07-26 16:04:47Z crees $

PORTNAME=	allegro
DISTVERSION=	4.4.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform library for games and multimedia programming

LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png

USES=		cmake pkgconfig
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_GL=		gl glu
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_SUB+= 	SHLIB_VER="${SHLIB_VER}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}"

SHLIB_VER=	${PORTVERSION}

# Wrong versioning upstream
PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	DOCS ALSA JACK OGG
OPTIONS_GROUP=	EXAMPLES_DEMOS
OPTIONS_GROUP_EXAMPLES_DEMOS=	EXAMPLES DEMOS
OPTIONS_DEFAULT=	DEMOS ALSA OGG
DEMOS_DESC=	Install Demos programs, requires EXAMPLES

OPTIONS_SUB=	yes

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS CHANGES THANKS readme.txt

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
.include "Makefile.man"
INFO=		allegro
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=-DWANT_EXAMPLES=on
.else
CMAKE_ARGS+=-DWANT_EXAMPLES=off
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
CMAKE_ARGS+=-DWANT_ALSA=on
.else
CMAKE_ARGS+=-DWANT_ALSA=off
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CMAKE_ARGS+=-DWANT_JACK=on
.else
CMAKE_ARGS+=-DWANT_JACK=off
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
CMAKE_ARGS+=-DWANT_LOGG=on
.else
CMAKE_ARGS+=-DWANT_LOGG=off
.endif

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
SUB_FILES+=	shooter skater skater_agl \
		pkg-message
MASTER_SITES+=	SF/nemysisfreebsdp/allegro/:icons
DISTFILES+=	shooter.png:icons \
		skater.png:icons
DESKTOP_ENTRIES+="Shooter" "In a distant corner of the galaxy" "shooter" \
		"shooter" "Game;ArcadeGame;" false
DESKTOP_ENTRIES+="Skater" "Allegro's next demo game" "skater" \
		"skater" "Game;ArcadeGame;" false
DESKTOP_ENTRIES+="Skater AGL" "Allegro's next demo game" "skater" \
		"skater_agl" "Game;ArcadeGame;" false
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/allegro-$${ALLEGRO_VERSION}||' \
		${WRKSRC}/docs/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|<X11/extensions/xf86dga.h>|<X11/extensions/Xxf86dga.h>|' \
		${WRKSRC}/src/x/xdga2.c
.if ${PORT_OPTIONS:MJACK}
	@${REINPLACE_CMD} -e 's|jack_client = jack_client_new(jack_client_name);|jack_client = jack_client_open(jack_client_name, (jack_options_t)0, NULL);|' \
		${WRKSRC}/src/unix/jack.c
.endif
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|add_subdirectory(docs)|#add_subdirectory(docs)|' \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs/man/ && \
		${FIND} . -type f -and -name "*.3" -exec ${INSTALL_MAN} {} ${PREFIX}/man/man3/{} \;
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${EXAMPLESDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/shooter ${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/shooter.png ${PREFIX}/share/pixmaps
	@(cd ${EXAMPLESDIR}/demos/shooter && ${CHMOD} 755 shooter)
	${INSTALL_SCRIPT} ${WRKDIR}/skater* ${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/skater.png ${PREFIX}/share/pixmaps
	@(cd ${EXAMPLESDIR}/demos/skater && ${CHMOD} 755 skater*)
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif
.include <bsd.port.mk>
