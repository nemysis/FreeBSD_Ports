# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	duckmaze
PORTVERSION=	0.3r34
CATEGORIES=	games python
MASTER_SITES=	SF/nemysisfreebsdp/
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game about a duck that is in a maze

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}/trunk

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	TODO.txt index.html style.css

SUB_FILES=	${PORTNAME}.sh

DESKTOP_ENTRIES="duckmaze" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-extract:
	${MV} ${WRKSRC}/doc/*.png ${WRKSRC}/images/

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		*.py mopelib/*.py)
	@(cd ${WRKSRC} && ${RM} *.py.bak mopelib/*py.bak)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images levels mopelib music sounds" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/duckmazerc.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/version ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/images/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
