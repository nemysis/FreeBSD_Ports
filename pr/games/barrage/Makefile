# New ports collection makefile for:  	barrage
# Date created:       	23 April 2003
# Whom:  	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD: ports/games/barrage/Makefile,v 1.25 2012/02/18 10:17:38 mva Exp $
#

PORTNAME=	barrage
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Destroy as many targets as possible

LICENSE=	GPLv2

USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PORTDOCS=	AUTHORS BUGS ChangeLog README

INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/games/|/|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|barrage.png|barrage|' ${WRKSRC}/barrage.desktop

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
