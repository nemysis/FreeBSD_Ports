# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD: head/audio/mp3mover/Makefile 300895 2012-07-14 12:56:14Z beat $

PORTNAME=	mp3mover
PORTVERSION=	2.1.1
CATEGORIES=	audio perl5
MASTER_SITES=	SF/mediamover/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename mp3s and manipulate them

RUN_DEPENDS=	p5-tagged>=0:${PORTSDIR}/audio/p5-tagged

USE_PERL5=	yes
NO_BUILD=	yes

PORTDOCS=	readme
PLIST_FILES=	bin/mp3mover \
		%%DATADIR%%/sample-.mp3moverrc \
		%%DATADIR%%/shellperfect-.mp3moverrc
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	readme

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3mover.pl ${PREFIX}/bin/mp3mover
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample-.mp3moverrc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/shellperfect-.mp3moverrc ${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
