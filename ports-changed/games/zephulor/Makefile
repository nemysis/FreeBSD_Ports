# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD: head/games/zephulor/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	zephulor
PORTVERSION=	1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/apz/apz/stable/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-source${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-source${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Side scrolling arcade game

LICENSE=	LGPL20

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:${PORTSDIR}/x11-toolkits/py-tkinter

WRKSRC=		${WRKDIR}/zephulor-source

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt manual.txt readme-*.txt

DOCSRCDIR2=	${WRKSRC}/maptool
DOCSDIR2=	${DOCSDIR}/maptool
DOC_FILES2=	manual.txt

DESKTOP_ENTRIES="Adventures on Planet Zephulor" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|#!.*python|#!${PYTHON_CMD}|' \
		${WRKSRC}/*.py ${WRKSRC}/maptool/*.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/maptool
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/maptool/*.py ${DATADIR}/maptool

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
