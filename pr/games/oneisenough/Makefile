# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	oneisenough
PORTVERSION=	0.4.0
CATEGORIES=	games python
MASTER_SITES=	http://hectigo.net/games/oneisenough/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}_a${DISTVERSION:S/.//g}_src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}_a${DISTVERSION:S/.//g}_src${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Economic development in the land of the balls

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/"one is enough"

USE_ZIP=	yes
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
USE_DOS2UNIX=	*.py *.txt

PORTDOCS=	README.txt

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="One Is Enough" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/run_game.py ${DATADIR}
	@(cd ${WRKSRC}/bin && ${COPYTREE_SHARE} . ${DATADIR}/bin)
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
