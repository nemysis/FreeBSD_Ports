# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/sdl_jewels/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	sdl_jewels
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/gljewel/downloads/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME:S/sdl/SDL/}-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME:S/sdl/SDL/}-${DISTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tile-matching 8x8 puzzle game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME:S/sdl/SDL/}-${PORTVERSION}

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
ALL_TARGET=

PORTDOCS=	ChangeLog README

DESKTOP_ENTRIES="SDL Jewels" "${COMMENT}" "${PORTNAME}" \
		"sdljewels" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${RM} -rf ${WRKSRC}/data/CVS
	@${REINPLACE_CMD} -e 's|data/bigfont.ppm|${DATADIR}/data/bigfont.ppm|' \
	-e 's|dirlist\[\]="data";|dirlist[]="${DATADIR}/data";|' \
	-e 's|char name[256],|char name[512],|' \
		${WRKSRC}/gljewel.c ${WRKSRC}/sound.c
	@${REINPLACE_CMD} -e 's|CFLAGS = -O2 -Wall|CFLAGS+=|' \
	-e 's|LDFLAGS =|LDFLAGS+=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gljewel ${PREFIX}/bin/sdljewels
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
