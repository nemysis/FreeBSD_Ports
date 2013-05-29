# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD: head/games/whichwayisup/Makefile 312762 2013-02-22 11:44:20Z rene $

PORTNAME=	whichwayisup
PORTVERSION=	0.7.9
PORTREVISION=	4
CATEGORIES=	games python
MASTER_SITES=	http://www.oletus.fi/static/whichwayisup/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}_b${DISTVERSION:S/.//g}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}_b${DISTVERSION:S/.//g}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Platformer game with rotational twist

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USES=		desktop-file-utils
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
USE_DOS2UNIX=	*.py *.txt

PORTDOCS=	README.txt changelog.txt

DESKTOP_ENTRIES="Which Way Is Up" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/libdir =/s|=.*|= "${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}"|'\
		${WRKSRC}/run_game.py
	@${REINPLACE_CMD} -e '/data_dir =/s|data_py.*data.|"${DATADIR}"|'\
		${WRKSRC}/lib/data.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete -or -name "*.orig" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	@${TOUCH} ${WRKSRC}/data/music/.keep_me

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run_game.py ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR})
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
