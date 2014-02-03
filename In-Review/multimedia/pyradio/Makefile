# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyradio
#PORTVERSION=	0.5.2${STATIONS_VER}
PORTVERSION=	0.5.2
CATEGORIES=	multimedia python
MASTER_SITES=	SF/nemysisfreebsdp/multimedia/${PORTNAME}:nemysis
#DISTFILES=	${PORTNAME}-${DISTVERSION:S/${STATIONS_VER}//}${EXTRACT_SUFX} \
DISTFILES=	${PORTNAME}-stations.csv-${STATIONS_VER}:nemysis \
		${PORTNAME}.png:nemysis
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION:S/${STATIONS_VER}//}${EXTRACT_SUFX

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Curses based internet radio player

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	coderholic
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	c0927e4

STATIONS_VER=	20130920

#PLIST_SUB=	PYVER=${PYTHON_VER} VERSION=${PORTVERSION:S/${STATIONS_VER}//}
PLIST_SUB=	PYVER=${PYTHON_VER} VERSION=${PORTVERSION}

USE_PYTHON=	2.7-3.2
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	DOCS

OPTIONS_SINGLE=	PLAYER
OPTIONS_SINGLE_PLAYER=	MPLAYER VLC
OPTIONS_DEFAULT=	MPLAYER

VLC_DESC=	Multimedia support for VLC

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

SUB_LIST+=	PYVER=${PYTHON_VER}

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MVLC}
RUN_DEPENDS+=	vlc:${PORTSDIR}/multimedia/vlc
.endif

post-patch:
	@${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}-stations.csv-${STATIONS_VER} ${WRKSRC}/pyradio/stations.csv
	@${REINPLACE_CMD} -e 's|import sys|import os, sys|' \
		${WRKSRC}/pyradio/main.py
	@${REINPLACE_CMD} -e 's|import os|import os, sys|' \
		 ${WRKSRC}/pyradio/player.py ${WRKSRC}/pyradio/radio.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
