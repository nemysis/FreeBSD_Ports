# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyradio
PORTVERSION=	0.5.1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/nemysisfreebsdp/:icons
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Curses based internet radio player

LICENSE=	MIT

RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

USE_GITHUB=	yes
GH_ACCOUNT=	coderholic
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	19a9492

PLIST_SUB=	PYVER=${PYTHON_VER} VERSION=${PORTVERSION}

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
	@${INSTALL_DATA} ${FILESDIR}/stations.csv ${WRKSRC}/pyradio

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
