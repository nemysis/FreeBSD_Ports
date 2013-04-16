# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	super_mario_bros_python
PORTVERSION=	0.1
CATEGORIES=	games python
MASTER_SITES=	SF/supermariobrosp/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	Super-Mario-Bros-Python-v${DISTVERSION}release${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	Super-Mario-Bros-Python-v${DISTVERSION}release${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Clone of the original Super Mario Bros

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/Super-Mario-Bros-Python-v${DISTVERSION}release

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	changelog.txt readme.txt

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Super Mario Bros. Python" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -i '' -e '1d' ${WRKSRC}/start.py
	@${FIND} ${WRKSRC} -name "*.py~" -delete -or -name "*.sav~" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data gamelib" ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
