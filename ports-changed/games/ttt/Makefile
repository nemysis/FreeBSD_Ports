# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD: head/games/ttt/Makefile 304004 2012-09-09 22:08:43Z swills $

PORTNAME=	ttt
PORTVERSION=	2011.04
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/ttt/ \
		ftp://ftp.billsgames.com/unix/x/ttt/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple one or two player Tic Tac Toe game

LICENSE=	GPLv2

USE_AUTOTOOLS=	aclocal automake autoheader autoconf
AUTOMAKE_ARGS=	--add-missing --force
ALL_TARGET=	${PORTNAME}
USE_SDL=	mixer sdl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	 README

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="TTT" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images sounds" ${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
