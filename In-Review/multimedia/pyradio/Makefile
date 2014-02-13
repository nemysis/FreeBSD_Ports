# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyradio
#PORTVERSION=	0.5.2${STATIONS_VER}
PORTVERSION=	0.5.2
CATEGORIES=	multimedia python
MASTER_SITES=	SF/nemysisfreebsdp/multimedia/${PORTNAME}:nemysis
DISTFILES+=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-stations.csv-${STATIONS_VER}:nemysis \
		${PORTNAME}.png:nemysis
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
#EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION:S/${STATIONS_VER}//}${EXTRACT_SUFX

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Curses based internet radio player

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	coderholic
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	4cd14de

STATIONS_VER=	20130920

USE_PYTHON=	2
USE_PYDISTUTILS=	yes


PORTDOCS=	Changelog README.md

OPTIONS_DEFINE=	DOCS

OPTIONS_SINGLE=	PLAYER
OPTIONS_SINGLE_PLAYER=	MPLAYER VLC
OPTIONS_DEFAULT=	MPLAYER

VLC_DESC=	Multimedia support for VLC

SUB_FILES=	pkg-message

MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
VLC_RUN_DEPENDS=	vlc:${PORTSDIR}/multimedia/vlc

.include <bsd.port.options.mk>

post-patch:
	@${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}-stations.csv-${STATIONS_VER} \
		${WRKSRC}/pyradio/stations.csv
	@${REINPLACE_CMD} -e 's|import sys|import os, sys|' \
		${WRKSRC}/pyradio/main.py
	@${REINPLACE_CMD} -e 's|import os|import os, sys|' \
		 ${WRKSRC}/pyradio/player.py ${WRKSRC}/pyradio/radio.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
