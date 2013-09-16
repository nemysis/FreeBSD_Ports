# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/impossible_mission_puzzle/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	impossible_mission_puzzle
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/puzzle/downloads/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	puzzle-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	puzzle-${DISTVERSION}.tgz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	This is a puzzle from the old C64 Impossible Mission game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/puzzle-${PORTVERSION}

USE_SDL=	sdl
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README

OPTIONS_DEFINE=DOCS

DESKTOP_ENTRIES="Impossible Mission puzzle" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-build:
	@cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
	`${SDL_CONFIG} --cflags --libs` puzzle.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
