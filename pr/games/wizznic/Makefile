# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wizznic
PORTVERSION=	0.9.9
DISTVERSIONSUFFIX=-src
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Source%20Releases/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Implementation of the arcade classic Puzznic

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	image mixer sdl

PORTDOCS=	changelog.txt credits.txt music-score-credits.txt readme.txt

DESKTOP_ENTRIES="Wizznic!" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

.include <bsd.port.options.mk>

do-build:
	@(cd ${WRKSRC} && ${GMAKE} DATADIR=${DATADIR}/ BINDIR=${PREFIX}/bin)

do-install:
	@(cd ${WRKSRC} && ${GMAKE} DATADIR=${DATADIR}/ BINDIR=${PREFIX}/bin install)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

	${LN} -sf ${DATADIR}/data/wmicon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
