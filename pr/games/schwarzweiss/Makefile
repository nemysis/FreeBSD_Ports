# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	schwarzweiss
PORTVERSION=	95263
CATEGORIES=	games
MASTER_SITES=	GH
DISTNAME=	${PORTNAME}-d${DISTVERSION}f
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Tank game for 2 players

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/horstjens-${DISTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	horstjens
GH_PROJECT=	schwarzweiss
GH_TAGNAME=	master
GH_COMMIT=	d95263f

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	readme.txt

INSTALLS_ICONS=	yes

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="SchwarzWeiss" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${LN} -sf ${WRKSRC}/data/menupic.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
