# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	vodovod
PORTVERSION=	1.10
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/vodovod/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform pipe connecting action puzzle game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-src

USE_SDL=	image mixer sdl
USE_GMAKE=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CHANGES

DOCSRCDIR2=	${WRKSRC}/html
DOCSDIR2=	${DOCSDIR}/html
DOC_FILES2=	*.gif *.png *.jpg *.html

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Vodovod" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data icon.ico" ${DATADIR})

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
