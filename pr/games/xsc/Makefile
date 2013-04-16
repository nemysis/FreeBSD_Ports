# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD: head/games/xsc/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	xsc
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.panix.com/~mbh/xsc/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Vector graphics space shoot'em up game

USE_XORG=	x11
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="Xce" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
