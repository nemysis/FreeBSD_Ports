# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/moagg/Makefile 308604 2012-12-10 13:18:28Z bapt $

PORTNAME=	moagg
PORTVERSION=	1.95b
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${DISTVERSION:S/b//}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-bin.zip \
		${PORTNAME}.png:icons
DIST_SUBDIR=	java
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-bin.zip

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Pilot a small space ship

LICENSE=	GPLv2

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

REPLACE_LIST_TEMP=	${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}

PORTDOCS=	AUTHORS README.txt
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

DESKTOP_ENTRIES="MOAGG, Mother of all gravity Games" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch-script:
	@${SED} ${REPLACE_LIST_TEMP} ${WRKSRC}/run.sh > ${WRKSRC}/run.sh.new

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run.sh.new ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data ghosts jar" ${DATADIR})
.for d in hiscores.dat log4j.properties
	${INSTALL_DATA} ${WRKSRC}/${d} ${DATADIR}
.endfor
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
