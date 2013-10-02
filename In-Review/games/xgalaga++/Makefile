# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/xgalaga++/Makefile 327730 2013-09-20 17:36:33Z bapt $

PORTNAME=	xgalaga++
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://marc.mongenet.ch/OSS/XGalaga/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Classic single screen vertical shoot em up

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake
ALL_TARGET=	${PORTNAME}
USE_XORG=	x11 xpm
USE_GCC=	yes
#SCORES=		/var/games/xgalaga++.scores

SUB_FILES=	pkg-install

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		man/man6/xgalaga++.6.gz

PORTDOCS=	README

DESKTOP_ENTRIES="XGalaga++" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^CXX =/ d; s|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xgalaga++.6x ${STAGEDIR}${MAN6PREFIX}/man/man6/xgalaga++.6
	@${CHGRP} games ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} g+s  ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

#	@if [ ! -f ${SCORES} ] ; then \
#		${MKDIR} ${SCORES:S/xgalaga++.scores//} ; \
#		${TOUCH} ${SCORES} ; \
#		${CHGRP} games ${SCORES} ; \
#		${CHMOD} 664 ${SCORES} ; \
#	fi

.include <bsd.port.mk>
