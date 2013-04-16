# New ports collection makefile for:	bomberclone
# Date created:				5 May 2003
# Whom:					Edwin Groothuis
#
# $FreeBSD: ports/games/bomberclone/Makefile,v 1.32 2012/06/01 05:18:30 dinoex Exp $
#

PORTNAME=	bomberclone
PORTVERSION=	0.11.9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Reimplementation of Atomic Bomber Man

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_SDL=	image mixer sdl
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README TODO

DESKTOP_ENTRIES="BomberMan clone" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

post-install:
	${LN} -sf ${PREFIX}/share/bomberclone/pixmaps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
