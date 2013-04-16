# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD: ports/games/xarchon/Makefile,v 1.17 2012/01/19 10:13:17 scheidell Exp $

PORTNAME=	xarchon
PORTVERSION=	0.50
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seul.org/pub/xarchon/ \
		http://xarchon.seul.org/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Chess-like strategy game with battle options

LICENSE=	GPLv2

USE_GNOME=	esound gtk12
USE_GMAKE=	yes
USE_XORG=	x11 xpm ice
GNU_CONFIGURE=	yes

MAN6=	xarchon.6

PORTDOCS=	AUTHORS ChangeLog README

DESKTOP_ENTRIES="XArchon" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '169s|^static ||' ${WRKSRC}/src/board.c
	@${REINPLACE_CMD} -e 's|Xarchon_Evolution::||' \
		${WRKSRC}/src/Xarchon_Genetic.hpp

# For XArchon 0.60 that find libglade
#	@${REINPLACE_CMD} -e 's|set dummy glade|set dummy libglade-config|' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

NOT_FOR_ARCHS=	sparc64

.include <bsd.port.mk>
