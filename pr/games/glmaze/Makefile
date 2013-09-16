# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD: ports/games/glmaze/Makefile,v 1.11 2012/02/18 10:17:52 mva Exp $

PORTNAME=	glmaze
PORTVERSION=	1.1a
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Multiplayer OpenGL Maze Game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GL=		glu
USE_SDL=	mixer sdl
MAKE_JOBS_SAFE=	yes

MAN6=	${PORTNAME}.6

PORTDOCS=	TODO readme.txt

DESKTOP_ENTRIES="glMaze" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/shot.c
	@(cd ${WRKSRC} && ${MV} glmaze.1 glmaze.6)

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
