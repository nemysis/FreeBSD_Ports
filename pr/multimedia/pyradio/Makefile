# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyradio
PORTVERSION=	0.5.1${STATIONS_VER}
CATEGORIES=	multimedia python
MASTER_SITES=	SF/nemysisfreebsdp/${PORTNAME}:nemysis
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION:S/${STATIONS_VER}//}${EXTRACT_SUFX} \
		${PORTNAME}-stations.csv-${STATIONS_VER}:nemysis \
		${PORTNAME}.png:nemysis
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION:S/${STATIONS_VER}//}${EXTRACT_SUFX

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Curses based internet radio player

LICENSE=	MIT

RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

USE_GITHUB=	yes
GH_ACCOUNT=	coderholic
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	8092a02

STATIONS_VER=	20130920

PLIST_SUB=	PYVER=${PYTHON_VER} VERSION=${PORTVERSION:S/${STATIONS_VER}//}

USE_PYTHON=	2.7-3.2
USE_PYDISTUTILS=	easy_install

PORTDOCS=	Changelog README.md

DESKTOP_ENTRIES="PyRadio" "${COMMENT}" "${PORTNAME}" \
		"xterm -e ${PORTNAME}" "AudioVideo;Player;" "false"

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
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
