# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	duckmaze
DISTVERSION=	0.3r34
CATEGORIES=	games python
MASTER_SITES=	SF/nemysisfreebsdp/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game about a duck that is in a maze

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}/trunk

USES=		shebangfix
SHEBANG_FILES=	*.py mopelib/mopelib.py
USE_PYTHON=	yes

PORTDOCS=	TODO.txt index.html style.css

SUB_FILES=	${PORTNAME}.sh

DESKTOP_ENTRIES="duckmaze" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-extract:
	${MV} ${WRKSRC}/doc/*.png ${WRKSRC}/images/

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images levels mopelib music sounds" ${DATADIR})
.for d in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${d} ${DATADIR}
.endfor
.for d in duckmazerc.txt version
	${INSTALL_DATA} ${WRKSRC}/${d} ${DATADIR}
.endfor
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
