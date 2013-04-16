# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD: ports/graphics/cadubi/Makefile,v 1.12 2012/06/28 18:37:12 az Exp $

PORTNAME=	cadubi
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	graphics editors
MASTER_SITES=	http://langworth.com/pub/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	ASCII drawing utility

LICENSE=	ART10

RUN_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/cadubi/help.txt \
		share/cadubi/logo.txt
PLIST_DIRSTRY=	share/cadubi

PORTDOCS=	*

.include <bsd.port.options.mk>

do-configure:
	@${PERL} -pi -e \
		's|Bin/help|Bin/../share/cadubi/help|g' ${WRKSRC}/cadubi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for d in help.txt logo.txt
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/ansi_term_codes.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
