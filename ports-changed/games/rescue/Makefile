# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/rescue/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	rescue
PORTVERSION=	1.0.0.2
PORTREVISION=	2
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/r/R/}%21%20Max/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/r/R/}_${PORTVERSION}
DIST_SUBDIR=	java

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Action adventure in space

LICENSE=	GPLv2

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:S/r/R/}

PORTDOCS=	ChangeLog.txt bugs.txt
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Rescue! Max" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;StrategyGame;" false

.include <bsd.port.options.mk>

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -j Rescue.jar rescue/gui/logo.png)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "help missions *.jar" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
