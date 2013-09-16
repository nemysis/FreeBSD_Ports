# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/black-box/Makefile 314007 2013-03-12 23:26:14Z beech $

PORTNAME=	black-box
PORTVERSION=	1.4.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/black-box/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Shoot in and watch where the shot leaves the box

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README

DESKTOP_ENTRIES="Black-Box" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
