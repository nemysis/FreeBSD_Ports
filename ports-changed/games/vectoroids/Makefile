# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD: head/games/vectoroids/Makefile 304008 2012-09-10 01:34:42Z swills $

PORTNAME=	vectoroids
PORTVERSION=	1.1.0
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/vectoroids/src/ \
		ftp://ftp.billsgames.com/unix/x/vectoroids/src/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Vector-based rock-shooting game similar to Asteroids

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_SDL=	image mixer sdl

MAN6=		${PORTNAME}.6

PORTDOCS=	CHANGES.txt README.txt

DESKTOP_ENTRIES="Vectoroids" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKDIR} -name .xvpics | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images music sounds" ${DATADIR})
	${LN} -sf ${DATADIR}/images/icon.png  ${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
