# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	pangzero
PORTVERSION=	1.3
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Clone of Super Pang

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Carp>=0:${PORTSDIR}/devel/p5-Carp \
		p5-SDL>=0:${PORTSDIR}/devel/p5-SDL

USE_PERL5=	yes
USE_SDL=	mixer image sdl sound net
NO_BUILD=	yes

PORTDOCS=	AUTHORS ChangeLog README

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Pang Zero" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" false

.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -name "Makefile*" -delete
.for f in *.png *.jpg
	@${CP} -a ${WRKDIR}/${f} ${WRKSRC}/data
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "bin data" ${DATADIR})

post-install:
	${LN} -sf ${DATADIR}/data/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
