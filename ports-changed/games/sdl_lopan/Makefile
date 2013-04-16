# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/sdl_lopan/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	sdl_lopan
PORTVERSION=	10
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/sdllopan/downloads/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	sdllopan-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	sdllopan-${DISTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Mahjong game remake

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/sdllopan-${PORTVERSION}

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

ALL_TARGET=

PORTDOCS=	Changelog README

DESKTOP_ENTRIES="SDL Lopan" "${COMMENT}" "${PORTNAME}" \
		"sdllopan" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|data/bg%d.pcx|${DATADIR}/data/bg%d.pcx|' \
	-e 's|data/tiles%d.pcx|${DATADIR}/data/tiles%d.pcx|' \
	-e 's|char temp\[64\];|char temp\[256\];|' \
		${WRKSRC}/lopan.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lopan ${PREFIX}/bin/sdllopan
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
