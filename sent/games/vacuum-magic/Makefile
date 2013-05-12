# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	vacuum-magic
PORTVERSION=	0.14r491
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/
DISTNAME=	vacuum-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Fast-paced action game

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Carp>=0:${PORTSDIR}/devel/p5-Carp \
		p5-SDL>=0:${PORTSDIR}/devel/p5-SDL

WRKSRC=		${WRKDIR}/vacuum

USE_PERL5=	yes
USE_SDL=	mixer image sdl sound net
NO_BUILD=	yes

MAN6=		${PORTNAME}.6

PORTDOCS=	AUTHORS NEWS README

SUB_FILES=	${PORTNAME} pkg-message

DESKTOP_ENTRIES="Vacuum Magic" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" false

.include <bsd.port.options.mk>

post-extract:
	@(cd ${WRKSRC}/data && ${MV} vacuum.6 ../${PORTNAME}.6)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vacuum-magic ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "bin data" ${DATADIR})

post-install:
# Fix Permission that user can write in bin
	@(cd ${DATADIR} && ${CHMOD} -R 774 bin)

	${LN} -sf ${DATADIR}/data/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
