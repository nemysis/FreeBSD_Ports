# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/sdl_scavenger/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	sdl_scavenger
PORTVERSION=	145.1.2010.11.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/sdlscavenger/
DISTNAME=	sdlscav-145.1_2010_11_5

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lode Runner like game

LICENSE=	GPLv1

WRKSRC=		${WRKDIR}/sdlscav-145

USE_ZIP=	yes
USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
ALL_TARGET=

PORTDOCS=	CREDITS DOC NEW_FEATURES README STRATEGY changelog

DESKTOP_ENTRIES="SDL Scavenger" "${COMMENT}" "sdlscavenger" \
		"sdlscavenger" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/local/games/scavenger|${DATADIR}/data|' \
			${WRKSRC}/names.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdlscav ${PREFIX}/bin/sdlscavenger
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data scav" ${DATADIR})
	${LN} -sf ${DATADIR}/data/scav.png ${PREFIX}/share/pixmaps/sdlscavenger.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
