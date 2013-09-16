# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lostfeathers
PORTVERSION=	1.0b
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Help a bird to recover his magical feathers

LICENSE=	BSD

RUN_DEPENDS=	avbin>=0:${PORTSDIR}/multimedia/avbin

USE_ZIP=	yes
USE_GNOME=	pygtk2 librsvg2
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	README.txt

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="The Lost Feathers" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.for d in cocos data gamelib pyglet
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/run_game.py ${DATADIR}

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
